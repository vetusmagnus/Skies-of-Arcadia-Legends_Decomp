#!/usr/bin/env python3

###
# Generates build files for the project.
# This file also includes the project configuration,
# such as compiler flags and the object matching status.
#
# Usage:
#   python3 configure.py
#   ninja
#
# Append --help to see available options.
###

import argparse
import re
import sys
from pathlib import Path
from typing import Any, Dict, List

from tools.project import (
    Object,
    ProgressCategory,
    ProjectConfig,
    calculate_progress,
    generate_build,
    is_windows,
)

# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "GEAE8P",  # 0
]

parser = argparse.ArgumentParser()
parser.add_argument(
    "mode",
    choices=["configure", "progress"],
    default="configure",
    help="script mode (default: configure)",
    nargs="?",
)
parser.add_argument(
    "-v",
    "--version",
    choices=VERSIONS,
    type=str.upper,
    default=VERSIONS[DEFAULT_VERSION],
    help="version to build",
)
parser.add_argument(
    "--build-dir",
    metavar="DIR",
    type=Path,
    default=Path("build"),
    help="base build directory (default: build)",
)
parser.add_argument(
    "--binutils",
    metavar="BINARY",
    type=Path,
    help="path to binutils (optional)",
)
parser.add_argument(
    "--compilers",
    metavar="DIR",
    type=Path,
    help="path to compilers (optional)",
)
parser.add_argument(
    "--map",
    action="store_true",
    help="generate map file(s)",
)
parser.add_argument(
    "--debug",
    action="store_true",
    help="build with debug info (non-matching)",
)
if not is_windows():
    parser.add_argument(
        "--wrapper",
        metavar="BINARY",
        type=Path,
        help="path to wibo or wine (optional)",
    )
parser.add_argument(
    "--dtk",
    metavar="BINARY | DIR",
    type=Path,
    help="path to decomp-toolkit binary or source (optional)",
)
parser.add_argument(
    "--objdiff",
    metavar="BINARY | DIR",
    type=Path,
    help="path to objdiff-cli binary or source (optional)",
)
parser.add_argument(
    "--sjiswrap",
    metavar="EXE",
    type=Path,
    help="path to sjiswrap.exe (optional)",
)
parser.add_argument(
    "--ninja",
    metavar="BINARY",
    type=Path,
    help="path to ninja binary (optional)",
)
parser.add_argument(
    "--verbose",
    action="store_true",
    help="print verbose output",
)
parser.add_argument(
    "--non-matching",
    dest="non_matching",
    action="store_true",
    help="builds equivalent (but non-matching) or modded objects",
)
parser.add_argument(
    "--warn",
    dest="warn",
    type=str,
    choices=["all", "off", "error"],
    help="how to handle warnings",
)
parser.add_argument(
    "--no-progress",
    dest="progress",
    action="store_false",
    help="disable progress calculation",
)
args = parser.parse_args()

config = ProjectConfig()
config.version = str(args.version)
version_num = VERSIONS.index(config.version)

# Apply arguments
config.build_dir = args.build_dir
config.dtk_path = args.dtk
config.objdiff_path = args.objdiff
config.binutils_path = args.binutils
config.compilers_path = args.compilers
config.generate_map = args.map
config.non_matching = args.non_matching
config.sjiswrap_path = args.sjiswrap
config.ninja_path = args.ninja
config.progress = args.progress
if not is_windows():
    config.wrapper = args.wrapper
# Don't build asm unless we're --non-matching
if not config.non_matching:
    config.asm_dir = None

# Tool versions
config.binutils_tag = "2.42-2"
config.compilers_tag = "20251118"
config.dtk_tag = "v1.8.3"
config.objdiff_tag = "v3.6.1"
config.sjiswrap_tag = "v1.2.2"
config.wibo_tag = "1.0.3"

# Project
config.config_path = Path("config") / config.version / "config.yml"
config.check_sha_path = Path("config") / config.version / "build.sha1"
config.asflags = [
    "-mgekko",
    "--strip-local-absolute",
    "-I include",
    f"-I build/{config.version}/include",
    f"--defsym BUILD_VERSION={version_num}",
]
config.ldflags = [
    "-fp hardware",
    "-nodefaults",
]
if args.debug:
    config.ldflags.append("-g")  # Or -gdwarf-2 for Wii linkers
if args.map:
    config.ldflags.append("-mapunused")
    # config.ldflags.append("-listclosure") # For Wii linkers

# Use for any additional files that should cause a re-configure when modified
config.reconfig_deps = []

# Game code must be plain C: no inline asm, pragmas or fakematch markers (tools/check_game_src.py).
# It runs before anything compiles, so a hit stops the build.
game_src = sorted(
    str(p)
    for d in ("src/game", "include/game")
    for p in Path(d).rglob("*")
    if p.suffix in (".c", ".cpp", ".h", ".hpp", ".inc")
) + ["include/ninja.h"]
config.custom_build_rules = [
    {
        "name": "check_game_src",
        "command": f'"{sys.executable}" tools/check_game_src.py --stamp $out $in',
        "description": "CHECK game code is plain C",
    },
]
config.custom_build_steps = {
    "pre-compile": [
        {
            "rule": "check_game_src",
            "inputs": game_src,
            "implicit": ["tools/check_game_src.py"],
            "outputs": f"build/{config.version}/check_game_src.ok",
        },
    ],
}

# Optional numeric ID for decomp.me preset
# Can be overridden in libraries or objects
config.scratch_preset_id = None

# Base flags, common to most GC/Wii games.
# Generally leave untouched, with overrides added below.
cflags_base = [
    "-nodefaults",
    "-proc gekko",
    "-align powerpc",
    "-enum int",
    "-fp hardware",
    "-Cpp_exceptions off",
    "-O4,p",
    "-inline auto",
    '-pragma "cats off"',
    '-pragma "warn_notinlined off"',
    "-maxerrors 1",
    "-nosyspath",
    "-RTTI off",
    "-fp_contract on",
    "-str reuse",
    "-multibyte",  # For Wii compilers, replace with `-enc SJIS`
    "-i include",
    f"-i build/{config.version}/include",
    f"-DBUILD_VERSION={version_num}",
    f"-DVERSION_{config.version}",
]

# Debug flags
if args.debug:
    # Or -sym dwarf-2 for Wii compilers
    cflags_base.extend(["-sym on", "-DDEBUG=1"])
else:
    cflags_base.append("-DNDEBUG=1")

# Warning flags
if args.warn == "all":
    cflags_base.append("-W all")
elif args.warn == "off":
    cflags_base.append("-W off")
elif args.warn == "error":
    cflags_base.append("-W error")

# Metrowerks library flags
cflags_runtime = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-str reuse,pool,readonly",
    "-gccinc",
    "-common off",
    "-inline auto",
]

# Game code flags
# Every game function with a multi-register save uses stmw/lmw (never _savegpr_NN).
cflags_game = [
    *cflags_base,
    "-use_lmw_stmw on",
    "-i extern/sdk/include",
    "-i extern/sdk/libc",
    # The game was built without auto-inlining: small static helpers defined earlier in a file
    # are still called (docs/compiler.md).
    "-inline noauto",
]

config.linker_version = "GC/1.3.2"


# Helper function for Dolphin libraries
def DolphinLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.2.5n",
        "cflags": cflags_base,
        "progress_category": "sdk",
        "objects": objects,
    }


# Helper function for game code
# GC/1.3.2: the game code is stwu-first (>= GC/1.3), and fn_801C3C40 tests a bit with the
# 1.3.2-only "(x & BIT) == BIT" sequence (subf/cntlzw), which 2.0 compiles differently. Everything
# matched so far is identical under 1.3.2 and 2.0; see docs/compiler.md.
def GameLib(lib_name: str, objects: List[Object]) -> Dict[str, Any]:
    return {
        "lib": lib_name,
        "mw_version": "GC/1.3.2",
        "cflags": cflags_game,
        "progress_category": "game",
        "objects": objects,
    }


Matching = True                   # Object matches and should be linked
NonMatching = False               # Object does not match and should not be linked
Equivalent = config.non_matching  # Object should be linked when configured with --non-matching


# Object is only matching for specific versions
def MatchingFor(*versions):
    return config.version in versions


config.warn_missing_config = True
config.warn_missing_source = False
config.libs = [
    {
        "lib": "Runtime.PPCEABI.H",
        "mw_version": config.linker_version,
        "cflags": cflags_runtime,
        "progress_category": "sdk",  # str | List[str]
        "objects": [
            Object(NonMatching, "Runtime.PPCEABI.H/global_destructor_chain.c"),
            Object(NonMatching, "Runtime.PPCEABI.H/__init_cpp_exceptions.cpp"),
        ],
    },
    GameLib(
        "game",
        [
            # Battle character state: stat block, command handlers, callback list, file-name
            # builders and the title sequence task. The start is a guess; 83 of 101 match.
            Object(NonMatching, "game/battle.c"),
            # Battle character command task and its helpers. The start is a guess (no constants
            # before 0x80032E78); fn_80032C6C is a near miss.
            Object(NonMatching, "game/btlchar.c"),
            # Quad, billboard and model draw helpers (.sdata2 from 0x80348570). Near misses:
            # fn_800334B8, fn_80033888, fn_8003529C, fn_80035518.
            Object(NonMatching, "game/draw2d.c"),
            # Event task handlers and resource chunk lists (0x80035918-0x8003DEE0): 230 of 235
            # match. Left: fn_80035918, fn_80035C38, fn_8003D2E4 (string pool), fn_8003DBAC,
            # fn_8003DCF4. The original keeps the strings in .rodata (needs -str reuse,readonly
            # once linked), and a 4-byte gap before lbl_802DD238 may mean a file boundary.
            Object(NonMatching, "game/tasks.c"),
            # .SAMP sample, voice and stream loading. fn_8003E1BC and fn_8003ECF4 differ only in
            # string offsets: like tasks.c, the strings belong in .rodata (-str reuse,readonly).
            Object(NonMatching, "game/sound.c"),
            # Effect and particle tasks (a new 0.0f at 0x80348638). The end is a guess. 27 of 29
            # match; fn_80041E64 and fn_800470F0 are near misses.
            Object(NonMatching, "game/effect.c"),
            # 40 of 44 match; UiDrawNumber, UiLayoutDrawPart, UiLayoutDraw and UiSpriteDraw are
            # register allocation / scheduling away.
            Object(NonMatching, "game/uiobj.c"),
            Object(Matching, "game/drawstate.c"),
            # 29 of 33 match; FontFindGlyph, TextNodeNewN, TextNodeNew and TextReadChar are
            # register allocation away. Data still comes from the asm.
            Object(NonMatching, "game/text.c"),
            # Motion playback (Ninja NJS_MOTION keyframes). fn_801E3DE0 and fn_801E41E0 are near
            # misses; fn_801E461C has no C yet.
            Object(NonMatching, "game/motion.c"),
            # Table accessors and the story-flag bitset. The file's end is a guess (no float
            # constants to pin it); fn_801E48A8, fn_801E4984 and fn_801E4AB0 are near misses.
            Object(NonMatching, "game/flags.c"),
            # Model objects: draw, motion blend, per-frame update. 38 of 39 match; fn_801E735C is
            # a near miss. The file ends at 0x801E7654 (a second u32 conversion constant there).
            Object(NonMatching, "game/model.c"),
            # Motion sampling and chunk strip/UV helpers. The end is a guess (no constants);
            # fn_801E85BC is a near miss.
            Object(NonMatching, "game/chunk.c"),
            # Story-flag event object and event NPC state pickers (a new 0.0f at 0x8034C020).
            # The end is a guess; 5 of 18 match.
            Object(NonMatching, "game/evobj.c"),
        ],
    ),
]


# BEGIN library import (generated by tools/import_libs.py)
# Library code borrowed from other decomp projects; see extern/*/README.md for sources
# and licenses. Placement in main.dol was verified with tools/tusplit.py.
config.libs += [
    {
        "lib": "os",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-i include", "-i extern/sdk/include", "-i extern/sdk/libc", "-i build/GEAE8P/include", "-DVERSION=0", "-DCARD_PATCH_2003=0"],
        "progress_category": "sdk",
        "src_dir": "extern/sdk",
        "objects": [
            Object(Matching, "dolphin/os/__ppc_eabi_init.cpp"),
            Object(Matching, "dolphin/PPCArch.c"),
            Object(Matching, "dolphin/os/OS.c"),
            Object(Matching, "dolphin/os/OSAlarm.c"),
            Object(Matching, "dolphin/os/OSArena.c"),
            Object(Matching, "dolphin/os/OSAudioSystem.c"),
            Object(Matching, "dolphin/os/OSCache.c"),
            Object(Matching, "dolphin/os/OSContext.c"),
            Object(Matching, "dolphin/os/OSInterrupt.c"),
            Object(Matching, "dolphin/os/OSMutex.c"),
            Object(Matching, "dolphin/os/OSReset.c"),
            Object(Matching, "dolphin/os/OSResetSW.c"),
            Object(Matching, "dolphin/os/OSRtc.c"),
            Object(Matching, "dolphin/os/OSSync.c"),
            Object(Matching, "dolphin/os/OSTime.c"),
        ],
    },
    {
        "lib": "musyx",
        "mw_version": "GC/1.3.2",
        "cflags": ["-proc gekko", "-nodefaults", "-nosyspath", "-i include", "-i include/compat", "-i extern/sdk/include", "-i extern/musyx/include", "-i extern/sdk/libc", "-inline auto,depth=4", "-O4,p", "-fp hard", "-enum int", "-sym on", "-Cpp_exceptions off", "-str reuse,pool,readonly", "-fp_contract off", "-DMUSY_TARGET=MUSY_TARGET_DOLPHIN", "-DMUSY_VERSION_MAJOR=2", "-DMUSY_VERSION_MINOR=0", "-DMUSY_VERSION_PATCH=0"],
        "progress_category": "middleware",
        "src_dir": "extern/musyx/src",
        "objects": [
            Object(Matching, "musyx/runtime/CheapReverb/creverb_fx.c"),
            Object(Matching, "musyx/runtime/seq.c"),
            Object(Matching, "musyx/runtime/synth.c"),
            Object(Matching, "musyx/runtime/seq_api.c"),
            Object(Matching, "musyx/runtime/snd_synthapi.c"),
            Object(Matching, "musyx/runtime/stream.c"),
            Object(Matching, "musyx/runtime/synthdata.c"),
            Object(Matching, "musyx/runtime/synthmacros.c"),
            Object(Matching, "musyx/runtime/synthvoice.c"),
            Object(Matching, "musyx/runtime/synth_ac.c"),
            Object(Matching, "musyx/runtime/synth_adsr.c"),
            Object(Matching, "musyx/runtime/synth_vsamples.c"),
            Object(Matching, "musyx/runtime/s_data.c"),
            Object(Matching, "musyx/runtime/hw_dspctrl.c"),
            Object(Matching, "musyx/runtime/hw_volconv.c"),
            Object(Matching, "musyx/runtime/snd3d.c"),
            Object(Matching, "musyx/runtime/snd_init.c"),
            Object(Matching, "musyx/runtime/snd_math.c"),
            Object(Matching, "musyx/runtime/snd_midictrl.c"),
            Object(Matching, "musyx/runtime/snd_service.c"),
            Object(Matching, "musyx/runtime/hardware.c"),
            Object(Matching, "musyx/runtime/hw_aramdma.c"),
            Object(Matching, "musyx/runtime/hw_dolphin.c"),
            Object(Matching, "musyx/runtime/hw_memory.c"),
            Object(Matching, "musyx/runtime/StdReverb/reverb_fx.c"),
            Object(Matching, "musyx/runtime/StdReverb/reverb.c"),
            Object(Matching, "musyx/runtime/Chorus/chorus_fx.c"),
            Object(Matching, "musyx/runtime/synth_dbtab.c"),
        ],
    },
    {
        "lib": "tww_sdk_2",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-str reuse", "-DNDEBUG=1", "-D__GEKKO__", "-fp_contract off", "-i extern/tww/include", "-i extern/tww/src", "-ir extern/tww/src/dolphin", "-i extern/tww/src/PowerPC_EABI_Support/MetroTRK", "-i extern/tww/Include", "-i extern/tww/src/PowerPC_EABI_Support/MSL/MSL_C++/MSL_Common/Include", "-i extern/tww/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include", "-i extern/tww/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Include", "-i extern/tww/src/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Include", "-i extern/tww/src/PowerPC_EABI_Support/Runtime/Inc", "-DVERSION=0"],
        "progress_category": "sdk",
        "src_dir": "extern/tww",
        "objects": [
            Object(Matching, "src/dolphin/os/OSMemory.c"),
        ],
    },
    {
        "lib": "db",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-i include", "-i extern/sdk/include", "-i extern/sdk/libc", "-i build/GEAE8P/include", "-DVERSION=0", "-DCARD_PATCH_2003=0"],
        "progress_category": "sdk",
        "src_dir": "extern/sdk",
        "objects": [
            Object(Matching, "dolphin/db.c"),
        ],
    },
    {
        "lib": "dvd",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-i include", "-i extern/sdk/include", "-i extern/sdk/libc", "-i build/GEAE8P/include", "-DVERSION=0", "-DCARD_PATCH_2003=0"],
        "progress_category": "sdk",
        "src_dir": "extern/sdk",
        "objects": [
            Object(Matching, "dolphin/dvd/dvdlow.c"),
            Object(Matching, "dolphin/dvd/dvdqueue.c"),
            Object(Matching, "dolphin/dvd/dvderror.c"),
            Object(Matching, "dolphin/dvd/dvdidutils.c"),
            Object(Matching, "dolphin/dvd/fstload.c"),
        ],
    },
    {
        "lib": "tww_sdk_3",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-str reuse", "-DNDEBUG=1", "-D__GEKKO__", "-fp_contract off", "-i extern/tww/include", "-i extern/tww/src", "-ir extern/tww/src/dolphin", "-i extern/tww/src/PowerPC_EABI_Support/MetroTRK", "-i extern/tww/Include", "-i extern/tww/src/PowerPC_EABI_Support/MSL/MSL_C++/MSL_Common/Include", "-i extern/tww/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common/Include", "-i extern/tww/src/PowerPC_EABI_Support/MSL/MSL_C/MSL_Common_Embedded/Math/Include", "-i extern/tww/src/PowerPC_EABI_Support/MSL/MSL_C/PPC_EABI/Include", "-i extern/tww/src/PowerPC_EABI_Support/Runtime/Inc", "-DVERSION=0"],
        "progress_category": "sdk",
        "src_dir": "extern/tww",
        "objects": [
            Object(Matching, "src/dolphin/pad/Pad.c"),
        ],
    },
    {
        "lib": "ffcc_sdk_1",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-str reuse", "-DNDEBUG=1", "-D__GEKKO__", "-fp_contract off", "-i extern/ffcc/include", "-i extern/ffcc/include/dolphin", "-i extern/ffcc/src", "-i extern/ffcc/include/TRK_MINNOW_DOLPHIN", "-ir extern/ffcc/src", "-i extern/ffcc/Include", "-DBUILD_VERSION=0", "-DVERSION_GCCE6W"],
        "progress_category": "sdk",
        "src_dir": "extern/ffcc",
        "objects": [
            Object(Matching, "src/dsp/dsp.c"),
            Object(Matching, "src/card/CARDRdwr.c"),
            Object(Matching, "src/gx/GXDisplayList.c"),
            Object(Matching, "src/gx/GXTransform.c"),
        ],
    },
    {
        "lib": "dsp",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-i include", "-i extern/sdk/include", "-i extern/sdk/libc", "-i build/GEAE8P/include", "-DVERSION=0", "-DCARD_PATCH_2003=0"],
        "progress_category": "sdk",
        "src_dir": "extern/sdk",
        "objects": [
            Object(Matching, "dolphin/dsp/dsp_debug.c"),
            Object(Matching, "dolphin/dsp/dsp_task.c"),
        ],
    },
    {
        "lib": "card",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-i include", "-i extern/sdk/include", "-i extern/sdk/libc", "-i build/GEAE8P/include", "-DVERSION=0", "-DCARD_PATCH_2003=0"],
        "progress_category": "sdk",
        "src_dir": "extern/sdk",
        "objects": [
            Object(Matching, "dolphin/card/CARDBios.c"),
            Object(Matching, "dolphin/card/CARDUnlock.c"),
            Object(Matching, "dolphin/card/CARDBlock.c"),
            Object(Matching, "dolphin/card/CARDDir.c"),
            Object(Matching, "dolphin/card/CARDCheck.c"),
            Object(Matching, "dolphin/card/CARDFormat.c"),
            Object(Matching, "dolphin/card/CARDOpen.c"),
            Object(Matching, "dolphin/card/CARDCreate.c"),
            Object(Matching, "dolphin/card/CARDRead.c"),
            Object(Matching, "dolphin/card/CARDWrite.c"),
            Object(Matching, "dolphin/card/CARDDelete.c"),
            Object(Matching, "dolphin/card/CARDStat.c"),
        ],
    },
    {
        "lib": "gx",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-i include", "-i extern/sdk/include", "-i extern/sdk/libc", "-i build/GEAE8P/include", "-DVERSION=0", "-DCARD_PATCH_2003=0"],
        "progress_category": "sdk",
        "src_dir": "extern/sdk",
        "objects": [
            Object(Matching, "dolphin/gx/GXInit.c"),
            Object(Matching, "dolphin/gx/GXFifo.c"),
            Object(Matching, "dolphin/gx/GXAttr.c"),
            Object(Matching, "dolphin/gx/GXGeometry.c"),
            Object(Matching, "dolphin/gx/GXTev.c"),
            Object(Matching, "dolphin/gx/GXPixel.c"),
            Object(Matching, "dolphin/gx/GXStubs.c"),
            Object(Matching, "dolphin/gx/GXPerf.c"),
        ],
    },
    {
        "lib": "TRK_MINNOW_DOLPHIN",
        "mw_version": "GC/1.3.2",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-w off", "-O4,p", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-multibyte", "-i extern/trk/include", "-i extern/trk/include/stl", "-DVERSION_GPVE01", "-use_lmw_stmw on", "-common off", "-inline auto", "-inline deferred", "-sdata 0", "-sdata2 0", "-rostr"],
        "progress_category": "sdk",
        "src_dir": "extern/trk",
        "objects": [
            Object(Matching, "MetroTRK/usr_put.c"),
            Object(Matching, "MetroTRK/flush_cache.c"),
            Object(Matching, "MetroTRK/mpc_7xx_603e.c"),
            Object(Matching, "MetroTRK/targcont.c"),
            Object(Matching, "MetroTRK/target_options.c"),
            Object(Matching, "MetroTRK/mslsupp.c"),
        ],
    },
    {
        "lib": "MSL_C.PPCEABI.bare.H",
        "mw_version": "GC/1.3",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-i include", "-i extern/sdk/include", "-i extern/sdk/libc", "-i build/GEAE8P/include", "-DVERSION=0", "-DCARD_PATCH_2003=0", "-use_lmw_stmw on", "-str reuse,pool,readonly", "-gccinc", "-common off", "-char signed", "-inline deferred,auto"],
        "progress_category": "sdk",
        "src_dir": "extern/sdk",
        "objects": [
            Object(Matching, "runtime/__va_arg.c"),
            Object(Matching, "runtime/buffer_io.c"),
            Object(Matching, "runtime/FILE_POS.c"),
            Object(Matching, "runtime/mem.c"),
            Object(Matching, "runtime/misc_io.c"),
            Object(Matching, "runtime/wchar_io.c"),
            Object(Matching, "runtime/e_acos.c"),
            Object(Matching, "runtime/e_atan2.c"),
            Object(Matching, "runtime/e_fmod.c"),
            Object(Matching, "runtime/e_rem_pio2.c"),
            Object(Matching, "runtime/k_cos.c"),
            Object(Matching, "runtime/k_rem_pio2.c"),
            Object(Matching, "runtime/k_sin.c"),
            Object(Matching, "runtime/k_tan.c"),
            Object(Matching, "runtime/s_copysign.c"),
            Object(Matching, "runtime/s_cos.c"),
            Object(Matching, "runtime/s_floor.c"),
            Object(Matching, "runtime/s_frexp.c"),
            Object(Matching, "runtime/s_ldexp.c"),
            Object(Matching, "runtime/s_modf.c"),
            Object(Matching, "runtime/s_sin.c"),
            Object(Matching, "runtime/s_tan.c"),
            Object(Matching, "runtime/w_acos.c"),
            Object(Matching, "runtime/w_atan2.c"),
            Object(Matching, "runtime/w_fmod.c"),
            Object(Matching, "runtime/w_pow.c"),
            Object(Matching, "runtime/errno.c"),
        ],
    },
    {
        "lib": "ffcc_sdk_0",
        "mw_version": "GC/1.3.2",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-str reuse", "-DNDEBUG=1", "-D__GEKKO__", "-fp_contract on", "-use_lmw_stmw on", "-str reuse,pool,readonly", "-common off", "-inline deferred,auto", "-char signed", "-i extern/ffcc/include", "-i extern/ffcc/include/dolphin", "-i extern/ffcc/src", "-i extern/ffcc/include/TRK_MINNOW_DOLPHIN", "-ir extern/ffcc/src", "-i extern/ffcc/Include", "-DBUILD_VERSION=0", "-DVERSION_GCCE6W"],
        "progress_category": "sdk",
        "src_dir": "extern/ffcc",
        "objects": [
            Object(Matching, "src/MSL_C/PPCEABI/bare/H/direct_io.c"),
            Object(Matching, "src/MSL_C/PPCEABI/bare/H/file_io.c"),
        ],
    },
    {
        "lib": "exi",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-i include", "-i extern/sdk/include", "-i extern/sdk/libc", "-i build/GEAE8P/include", "-DVERSION=0", "-DCARD_PATCH_2003=0"],
        "progress_category": "sdk",
        "src_dir": "extern/sdk",
        "objects": [
            Object(Matching, "dolphin/exi/EXIUart.c"),
        ],
    },
    {
        "lib": "si",
        "mw_version": "GC/1.2.5n",
        "cflags": ["-nodefaults", "-proc gekko", "-align powerpc", "-enum int", "-fp hardware", "-Cpp_exceptions off", "-O4,p", "-inline auto", "-pragma \"cats off\"", "-pragma \"warn_notinlined off\"", "-maxerrors 1", "-nosyspath", "-RTTI off", "-fp_contract on", "-str reuse", "-i include", "-i extern/sdk/include", "-i extern/sdk/libc", "-i build/GEAE8P/include", "-DVERSION=0", "-DCARD_PATCH_2003=0"],
        "progress_category": "sdk",
        "src_dir": "extern/sdk",
        "objects": [
            Object(Matching, "dolphin/si/SIBios.c"),
            Object(Matching, "dolphin/si/SISamplingRate.c"),
        ],
    },
]
# END library import

# Optional callback to adjust link order. This can be used to add, remove, or reorder objects.
# This is called once per module, with the module ID and the current link order.
#
# For example, this adds "dummy.c" to the end of the DOL link order if configured with --non-matching.
# "dummy.c" *must* be configured as a Matching (or Equivalent) object in order to be linked.
def link_order_callback(module_id: int, objects: List[str]) -> List[str]:
    # Don't modify the link order for matching builds
    if not config.non_matching:
        return objects
    if module_id == 0:  # DOL
        return objects + ["dummy.c"]
    return objects


# Uncomment to enable the link order callback.
# config.link_order_callback = link_order_callback


# Optional extra categories for progress tracking
# Adjust as desired for your project
config.progress_categories = [
    ProgressCategory("game", "Game Code"),
    ProgressCategory("sdk", "SDK Code"),
    ProgressCategory("middleware", "Middleware"),
    ProgressCategory("ninja", "Ninja (Sega graphics library)"),
]


# Code that isn't split into a source file yet (dtk's auto_XX_ADDR_text units) still counts towards
# the category its address falls in, so each category's total is the whole region, not just the
# files started so far. Ranges: docs/sdk_import.md.
def auto_unit_categories(name: str) -> List[str]:
    m = re.match(r".*/auto_\d+_([0-9A-F]{8})_(text|init)$", name)
    if not m:
        return []
    addr = int(m.group(1), 16)
    if 0x80005600 <= addr < 0x80231A7C:
        return ["game"]
    if 0x80266878 <= addr < 0x80286EE8:
        return ["middleware"]
    if 0x80286EE8 <= addr < 0x802AC7E0:
        return ["ninja"]
    return ["sdk"]


config.auto_unit_categories = auto_unit_categories
config.progress_each_module = args.verbose
# Optional extra arguments to `objdiff-cli report generate`
config.progress_report_args = [
    # Marks relocations as mismatching if the target value is different
    # Default is "functionRelocDiffs=none", which is most lenient
    # "--config functionRelocDiffs=data_value",
]

if args.mode == "configure":
    # Write build.ninja and objdiff.json
    generate_build(config)
elif args.mode == "progress":
    # Print progress information
    calculate_progress(config)
else:
    sys.exit("Unknown mode: " + args.mode)
