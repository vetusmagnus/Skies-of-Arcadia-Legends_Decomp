#!/usr/bin/env python3
"""Locate a compiled translation unit inside the original main.dol and emit its splits.txt entry.

Given an object compiled from known source (e.g. SDK/MSL/TRK code borrowed from another
decomp project), this finds:
  - code:    .text (and .init) by matching each function's bytes (relocated fields masked)
  - data:    by anchoring each data section through the code's relocations
             (the original instruction gives the absolute address of `symbol+addend`)
and verifies data contents byte-for-byte (relocated words masked).

Usage:
    python tools/tusplit.py build/foo.o [--name path/in/splits.c] [--verbose]

Exit status is 0 only if every section was located and verified.
"""

import argparse
import re
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DOL = ROOT / "orig" / "GEAE8P" / "sys" / "main.dol"
SYMBOLS = ROOT / "config" / "GEAE8P" / "symbols.txt"
SDA_BASE = {13: 0x8034E720, 2: 0x80350000}

R_PPC_ADDR32, R_PPC_ADDR16_LO, R_PPC_ADDR16_HI, R_PPC_ADDR16_HA = 1, 4, 5, 6
R_PPC_REL24, R_PPC_REL14, R_PPC_EMB_SDA21 = 10, 11, 109
MASKS = {
    R_PPC_ADDR32: 0xFFFFFFFF, R_PPC_ADDR16_LO: 0xFFFF, R_PPC_ADDR16_HI: 0xFFFF,
    R_PPC_ADDR16_HA: 0xFFFF, R_PPC_REL24: 0x03FFFFFC, R_PPC_REL14: 0xFFFC,
    R_PPC_EMB_SDA21: 0x001FFFFF,
}
CODE_SECTIONS = (".init", ".text")
DATA_SECTIONS = (".ctors", ".dtors", ".rodata", ".data", ".bss", ".sdata", ".sbss", ".sdata2", ".sbss2")
STRIPPED_WITH_USER = (".bss", ".sbss", ".sbss2", ".sdata2")
BSS_SECTIONS = (".bss", ".sbss", ".sbss2")


class Elf:
    def __init__(self, path):
        d = Path(path).read_bytes()
        assert d[:4] == b"\x7fELF" and d[5] == 2
        shoff, = struct.unpack_from(">I", d, 0x20)
        shentsize, shnum, shstrndx = struct.unpack_from(">HHH", d, 0x2E)
        sh = [struct.unpack_from(">IIIIIIIIII", d, shoff + i * shentsize) for i in range(shnum)]
        cstr = lambda off: d[off:d.index(b"\0", off)].decode()
        self.sections = []
        for s in sh:
            name = cstr(sh[shstrndx][4] + s[0])
            data = b"" if s[1] == 8 else d[s[4]:s[4] + s[5]]
            self.sections.append(dict(name=name, type=s[1], size=s[5], data=data, align=s[8]))
        self.symbols = []
        self.relocs = {}  # section index -> [(offset, type, sym index, addend)]
        for idx, s in enumerate(sh):
            if s[1] == 2:
                strtab = sh[s[6]][4]
                for i in range(s[5] // 16):
                    no, val, size, info, _, shndx = struct.unpack_from(">IIIBBH", d, s[4] + i * 16)
                    self.symbols.append(dict(name=cstr(strtab + no), value=val, size=size,
                                             type=info & 0xF, bind=info >> 4, shndx=shndx))
        for s in sh:
            if s[1] == 4:
                rel = self.relocs.setdefault(s[7], [])
                for i in range(s[5] // 12):
                    off, info, add = struct.unpack_from(">IIi", d, s[4] + i * 12)
                    rel.append((off, info & 0xFF, info >> 8, add))

    def functions(self):
        out = []
        for s in self.symbols:
            if s["type"] == 2 and 0 < s["shndx"] < len(self.sections) and self.sections[s["shndx"]]["name"] in CODE_SECTIONS:
                out.append(dict(s, section=self.sections[s["shndx"]]["name"]))
        return sorted(out, key=lambda s: (s["shndx"], s["value"]))

    def masked_words(self, shndx, start, size):
        sec = self.sections[shndx]
        rel = {o & ~3: MASKS.get(t, 0xFFFFFFFF) for o, t, _, _ in self.relocs.get(shndx, [])}
        return [struct.unpack_from(">I", sec["data"], o)[0] & ~rel.get(o, 0) for o in range(start, start + size, 4)]


class Dol:
    def __init__(self, path):
        self.d = Path(path).read_bytes()
        offs = struct.unpack_from(">18I", self.d, 0)
        addrs = struct.unpack_from(">18I", self.d, 72)
        sizes = struct.unpack_from(">18I", self.d, 144)
        self.segs = [(addrs[i], sizes[i], offs[i]) for i in range(18) if sizes[i]]

    def read(self, addr, size):
        for a, s, o in self.segs:
            if a <= addr and addr + size <= a + s:
                return self.d[o + addr - a:o + addr - a + size]
        return None

    def word(self, addr):
        b = self.read(addr, 4)
        return None if b is None else struct.unpack(">I", b)[0]


def load_symbols():
    syms = {}
    for line in SYMBOLS.read_text().splitlines():
        m = re.match(r"(\S+) = (\.\w+):0x([0-9A-Fa-f]+); // (.*)", line)
        if not m:
            continue
        size = re.search(r"size:0x([0-9A-Fa-f]+)", m.group(4))
        typ = re.search(r"type:(\w+)", m.group(4))
        syms[m.group(1)] = dict(section=m.group(2), addr=int(m.group(3), 16),
                                size=int(size.group(1), 16) if size else 0,
                                type=typ.group(1) if typ else None)
    return syms


def sext16(v):
    return v - 0x10000 if v & 0x8000 else v


def calls_agree(elf, dol, syms, f, addr):
    """False if a call in f to a function the original names lands somewhere else at addr. Bytes
    match with relocations masked, so this tells apart look-alikes such as a tiny MusyX helper
    calling salFree and a game function calling the game's own free."""
    for off, typ, symi, _ in elf.relocs.get(f["shndx"], []):
        if typ != R_PPC_REL24 or not f["value"] <= off < f["value"] + f["size"]:
            continue
        target = syms.get(elf.symbols[symi]["name"])
        if target is None or target["type"] != "function":
            continue
        at = addr + (off & ~3) - f["value"]
        li = dol.word(at) & 0x03FFFFFC
        if at + (li - 0x04000000 if li & 0x02000000 else li) != target["addr"]:
            return False
    return True


def find_text(elf, dol, syms, verbose):
    """Map each compiled function to an original address. Returns {name: addr} for matched functions."""
    by_words = {}
    for name, s in syms.items():
        if s["type"] == "function" and s["section"] in CODE_SECTIONS:
            by_words.setdefault((s["section"], s["size"]), []).append((s["addr"], name))
    found = {}
    ambiguous = {}
    funcs = elf.functions()
    for f in funcs:
        ours = elf.masked_words(f["shndx"], f["value"], f["size"])
        rel = {o & ~3: MASKS.get(t, 0xFFFFFFFF) for o, t, _, _ in elf.relocs.get(f["shndx"], [])}
        cands = []
        for addr, name in by_words.get((f["section"], f["size"]), []):
            words = [dol.word(addr + i * 4) & ~rel.get(f["value"] + i * 4, 0) for i in range(f["size"] // 4)]
            if words == ours and calls_agree(elf, dol, syms, f, addr):
                cands.append((addr, name))
        named = [c for c in cands if c[1] == f["name"]]
        # Identical bytes under another real name (CARDRead / CARDWrite) are a different function.
        cands = named or [c for c in cands if c[1].startswith(("fn_", "lbl_"))]
        if named:
            found[f["name"]] = named[0][0]
        elif len(cands) == 1:
            found[f["name"]] = cands[0][0]
        elif cands:
            ambiguous[f["name"]] = {c[0] for c in cands}
        elif verbose:
            print(f"  {f['name']}: not found", file=sys.stderr)
    # Resolve ambiguous (usually tiny) functions by position next to a found neighbor.
    changed = True
    while changed:
        changed = False
        for j, f in enumerate(funcs):
            if f["name"] not in ambiguous:
                continue
            expect = set()
            if j > 0 and funcs[j - 1]["name"] in found:
                expect.add(found[funcs[j - 1]["name"]] + funcs[j - 1]["size"])
            if j + 1 < len(funcs) and funcs[j + 1]["name"] in found:
                expect.add(found[funcs[j + 1]["name"]] - f["size"])
            hit = expect & ambiguous[f["name"]]
            if len(hit) == 1:
                found[f["name"]] = hit.pop()
                del ambiguous[f["name"]]
                changed = True
    if verbose:
        for name in ambiguous:
            print(f"  {name}: ambiguous", file=sys.stderr)
    # Two of our functions with identical bytes can land on one original (sndSeqSetMidiCtrl and
    # sndSeqSetMidiCtrl14; the other was stripped). Keep the one that follows its predecessor.
    by_addr = {}
    for f in funcs:
        if f["name"] in found:
            by_addr.setdefault(found[f["name"]], []).append(f["name"])
    for a, names in by_addr.items():
        if len(names) < 2:
            continue
        def follows(n):
            j = next(i for i, f in enumerate(funcs) if f["name"] == n)
            prev = next((f for f in reversed(funcs[:j]) if f["name"] in found), None)
            return prev is not None and found[prev["name"]] + prev["size"] == a
        keep = [n for n in names if follows(n)]
        for n in names:
            if keep != [n]:
                del found[n]
                if verbose:
                    print(f"  {n}: same bytes as another function at {a:#x}; dropped", file=sys.stderr)
    # A handful of tiny generic functions is not evidence of a match.
    if found and sum(f["size"] for f in funcs if f["name"] in found) < 0x20 and \
            not any(syms.get(n, {}).get("addr") == a for n, a in found.items()):
        if verbose:
            print("  only tiny generic functions matched; rejecting", file=sys.stderr)
        return {}
    return found


def data_symbols(elf, idx):
    """Data symbols of one section, sorted by offset, with sizes filled in."""
    sec = elf.sections[idx]
    out = [dict(i=i, **sym) for i, sym in enumerate(elf.symbols)
           if sym["shndx"] == idx and sym["type"] in (0, 1) and sym["name"] and not sym["name"].startswith("...")]
    out.sort(key=lambda x: x["value"])
    for j, sym in enumerate(out):
        if sym["size"] == 0:
            nxt = out[j + 1]["value"] if j + 1 < len(out) else sec["size"]
            sym["size"] = nxt - sym["value"]
    return out


def anchor_data(elf, dol, found, syms=None):
    """Resolve code relocations to {section index: {symbol offset in section: original address}}.
    Global data symbols whose name the original already has are anchored there too, which places
    data-only files (MusyX's synth_dbtab.c) and data no surviving code references."""
    anchors = {}
    for sym in elf.symbols if syms else []:
        sec = sym["shndx"]
        if sym["bind"] == 1 and sym["type"] in (0, 1) and 0 < sec < len(elf.sections) and \
                elf.sections[sec]["name"] in DATA_SECTIONS and sym["name"] in syms and \
                syms[sym["name"]]["section"] == elf.sections[sec]["name"]:
            anchors.setdefault(sec, []).append((sym["value"], syms[sym["name"]]["addr"]))
    funcs = {f["name"]: f for f in elf.functions()}
    for fname, faddr in found.items():
        f = funcs[fname]
        rels = [r for r in elf.relocs.get(f["shndx"], []) if f["value"] <= r[0] < f["value"] + f["size"]]
        ha = {}
        for off, typ, symi, add in rels:
            if typ == R_PPC_ADDR16_HA:
                ha[(symi, add)] = dol.word(faddr + (off & ~3) - f["value"]) & 0xFFFF
        for off, typ, symi, add in rels:
            sym = elf.symbols[symi]
            sec = sym["shndx"]
            if not (0 < sec < len(elf.sections)) or elf.sections[sec]["name"] not in DATA_SECTIONS:
                continue
            w = dol.word(faddr + (off & ~3) - f["value"])
            if typ == R_PPC_EMB_SDA21:
                base = SDA_BASE.get((w >> 16) & 0x1F)
                if base is None:
                    continue
                target = base + sext16(w & 0xFFFF)
            elif typ == R_PPC_ADDR16_LO and (symi, add) in ha:
                target = (ha[(symi, add)] << 16) + sext16(w & 0xFFFF)
            else:
                continue
            # offset within the section of the referenced byte, and where it is in the original
            anchors.setdefault(sec, []).append((sym["value"] + add, target))
    return anchors


def uses(elf, idx, fname):
    """Names of the data symbols in section idx that function fname has relocations against."""
    f = next(f for f in elf.functions() if f["name"] == fname)
    syms = data_symbols(elf, idx)
    out = set()
    for off, _, symi, add in elf.relocs.get(f["shndx"], []):
        if not f["value"] <= off < f["value"] + f["size"] or elf.symbols[symi]["shndx"] != idx:
            continue
        at = elf.symbols[symi]["value"] + add
        out |= {x["name"] for x in syms if x["value"] <= at < x["value"] + max(x["size"], 1)}
    return out


def only_used_by(elf, idx, fnames):
    """Data symbols in section idx referenced by some function in fnames and by no data."""
    used = set().union(*(uses(elf, idx, f) for f in fnames)) if fnames else set()
    syms = data_symbols(elf, idx)
    for rels in (r for i, r in elf.relocs.items() if elf.sections[i]["name"] in DATA_SECTIONS):
        for _, _, symi, add in rels:
            if elf.symbols[symi]["shndx"] == idx:
                at = elf.symbols[symi]["value"] + add
                used -= {x["name"] for x in syms if x["value"] <= at < x["value"] + max(x["size"], 1)}
    return used


PLACED = []  # (address, symbol) for every data symbol placed, for --symbols


def place_section(elf, dol, idx, refs, known_starts=frozenset(), gone=frozenset()):
    """Place each data symbol of a section in the original DOL.

    Returns (start, end, problems). Symbols referenced by code are placed exactly; the others are
    placed next to a placed neighbor if their bytes match (or, for .bss, if they fit)."""
    sec = elf.sections[idx]
    is_bss = sec["name"] in BSS_SECTIONS
    syms = data_symbols(elf, idx)
    problems = []
    if not syms:
        syms = [dict(i=-1, name="(section)", value=0, size=sec["size"])]
    addr = {}
    for off, target in refs:
        owner = next((x for x in syms if x["value"] <= off < x["value"] + max(x["size"], 1)), None)
        if owner is None:
            problems.append(f"reference to +{off:#x} outside any symbol")
            continue
        a = target - (off - owner["value"])
        if addr.setdefault(owner["value"], a) != a:
            problems.append(f"{owner['name']} anchored at both {addr[owner['value']]:#x} and {a:#x}")
    if not addr:
        return None, None, ["no code references to anchor it"]

    def matches(sym, a):
        if is_bss:
            return True
        orig = dol.read(a, sym["size"])
        if orig is None:
            return False
        rel = {o & ~3 for o, _, _, _ in elf.relocs.get(idx, [])}
        for o in range(0, sym["size"] - sym["size"] % 4, 4):
            if sym["value"] + o not in rel and orig[o:o + 4] != sec["data"][sym["value"] + o:sym["value"] + o + 4]:
                return False
        tail = sym["size"] % 4
        if tail:
            o = sym["size"] - tail
            if orig[o:] != sec["data"][sym["value"] + o:sym["value"] + sym["size"]]:
                return False
        return True

    def fits_tail_gap(a, j):
        # Trailing .bss with no relocation to anchor it (unused, or only reached through a
        # section base pointer like `addi r3, r31, 0x4f8`) that fills the unclaimed space up to
        # the next object dtk knows about, give or take alignment. Nothing can shift, so it's
        # consistent with the DOL; an exact fit (GXInit's FifoObj, GXDisplayList's
        # __savedGXdata) is good evidence the variable is really there.
        # Measured over the whole run from symbol j to the end of the section.
        tail = a + syms[-1]["value"] + syms[-1]["size"] - syms[j]["value"]
        nxt_known = min((k for k in known_starts if k >= a), default=None)
        return nxt_known is not None and tail <= nxt_known <= ((tail + 7) & ~7)

    # Verify anchored symbols, then grow outward from them.
    for sym in syms:
        if sym["value"] in addr and not matches(sym, addr[sym["value"]]):
            problems.append(f"{sym['name']} contents differ at {addr[sym['value']]:#x}")
    order = [x["value"] for x in syms]
    changed = True
    while changed:
        changed = False
        for j, sym in enumerate(syms):
            if sym["value"] in addr or "$localstatic" in sym["name"]:
                continue  # inline-function statics are merged across files; one copy lives elsewhere
            prev = syms[j - 1] if j > 0 else None
            nxt = syms[j + 1] if j + 1 < len(syms) else None
            cand = None
            if prev and prev["value"] in addr:
                cand = addr[prev["value"]] + (sym["value"] - prev["value"])
            elif nxt and nxt["value"] in addr:
                cand = addr[nxt["value"]] - (nxt["value"] - sym["value"])
            if cand is None:
                continue
            # must not overlap any symbol already placed
            sizes = {x["value"]: x["size"] for x in syms}
            if any(cand < addr[v] + sizes[v] and addr[v] < cand + sym["size"] for v in addr):
                continue
            # Bracketed by placed symbols whose spacing in the DOL matches the object's, so
            # everything between them is laid out exactly as compiled (synthvoice.c's .bss).
            lo_ = next((x for x in reversed(syms[:j]) if x["value"] in addr), None)
            hi_ = next((x for x in syms[j + 1:] if x["value"] in addr), None)
            between = (lo_ is not None and hi_ is not None and
                       addr[hi_["value"]] - addr[lo_["value"]] == hi_["value"] - lo_["value"])
            if sym["name"] in gone and not between:
                continue  # its users were stripped (and nothing pins it in place)
            if is_bss and not between and cand not in known_starts and not (
                    prev and prev["value"] in addr and fits_tail_gap(cand, j)):
                continue  # .bss at an edge: only accept where dtk also found an object
            if matches(sym, cand):
                addr[sym["value"]] = cand
                changed = True
    placed = sorted(((addr[x["value"]], x) for x in syms if x["value"] in addr), key=lambda p: p[0])
    unplaced = [x["name"] for x in syms if x["value"] not in addr]
    if unplaced:
        problems.append(f"not placed (stripped, or unverifiable): {', '.join(unplaced)}")
    for (a1, s1), (a2, s2) in zip(placed, placed[1:]):
        if a1 + s1["size"] > a2:
            problems.append(f"{s1['name']} overlaps {s2['name']}")
    start = placed[0][0]
    end = (placed[-1][0] + placed[-1][1]["size"] + 3) & ~3
    PLACED.extend((a, x) for a, x in placed)
    return start, end, problems


def external_refs(elf, dol, found):
    """Resolve references to symbols this object doesn't define: {address: name}."""
    out = {}
    funcs = {f["name"]: f for f in elf.functions()}
    for fname, faddr in found.items():
        f = funcs[fname]
        rels = [r for r in elf.relocs.get(f["shndx"], []) if f["value"] <= r[0] < f["value"] + f["size"]]
        ha = {}
        for off, typ, symi, add in rels:
            if typ == R_PPC_ADDR16_HA:
                ha[(symi, add)] = dol.word(faddr + (off & ~3) - f["value"]) & 0xFFFF
        for off, typ, symi, add in rels:
            sym = elf.symbols[symi]
            if sym["shndx"] != 0 or not sym["name"]:
                continue
            at = faddr + (off & ~3) - f["value"]
            w = dol.word(at)
            if typ == R_PPC_REL24:
                li = w & 0x03FFFFFC
                target = at + (li - 0x04000000 if li & 0x02000000 else li)
            elif typ == R_PPC_EMB_SDA21:
                base = SDA_BASE.get((w >> 16) & 0x1F)
                if base is None:
                    continue
                target = base + sext16(w & 0xFFFF)
            elif typ == R_PPC_ADDR16_LO and (symi, add) in ha:
                target = (ha[(symi, add)] << 16) + sext16(w & 0xFFFF)
            else:
                continue
            out[target - add] = sym["name"]
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("obj")
    ap.add_argument("--name", help="path written in splits.txt (default: object stem + .c)")
    ap.add_argument("--verbose", action="store_true")
    ap.add_argument("--symbols", action="store_true",
                    help="also print '# sym <addr> <name> <global|local>' lines for every placed symbol")
    args = ap.parse_args()

    elf, dol, syms = Elf(args.obj), Dol(DOL), load_symbols()
    ok = True
    found = find_text(elf, dol, syms, args.verbose)
    funcs = elf.functions()
    if not found and funcs:
        sys.exit(f"{args.obj}: no functions found in the DOL")
    missing = [f["name"] for f in funcs if f["name"] not in found]

    # code ranges: matched functions must be contiguous in the DOL, in the same order
    sizes = {f["name"]: f["size"] for f in funcs}
    covered = sum(sizes[n] for n in found)
    lines = []
    for sec in CODE_SECTIONS:
        order = sorted((a, f["name"]) for f in funcs if f["section"] == sec and (a := found.get(f["name"])) is not None)
        if not order:
            if any(f["section"] == sec for f in funcs):
                print(f"  {sec}: no functions found", file=sys.stderr)
                ok = False
            continue
        lo = order[0][0]
        hi = order[-1][0] + sizes[order[-1][1]]
        dol_funcs = [s for s in syms.values() if s["type"] == "function" and lo <= s["addr"] < hi]
        if len(dol_funcs) != len(order):
            print(f"  {sec}: {len(dol_funcs) - len(order)} unmatched original functions inside {lo:#x}-{hi:#x}", file=sys.stderr)
            ok = False
        in_obj_order = [found[f["name"]] for f in funcs if f["section"] == sec and f["name"] in found]
        if in_obj_order != sorted(in_obj_order):
            print(f"  {sec}: functions are in a different order than in the original", file=sys.stderr)
            ok = False
        lines.append(f"\t{sec:<11} start:0x{lo:08X} end:0x{hi:08X}")
    if missing and args.verbose:
        print(f"  not in DOL (stripped?): {', '.join(missing)}", file=sys.stderr)

    anchors = anchor_data(elf, dol, found, syms)
    for idx, sec in enumerate(elf.sections):
        if sec["name"] not in DATA_SECTIONS or sec["size"] == 0:
            continue
        known = frozenset(v["addr"] for v in syms.values() if v["section"] == sec["name"])
        # Data used only by functions the linker stripped: in .bss, .sbss and .sdata2 it goes with
        # them (OS.c's ZeroF, snd3d.c's em$1187, snd_math.c's @121), so it's never placed. In .data
        # it stays (dsp_task.c's @294 string) and is placed and byte-checked like anything else.
        # (Empirical; the DOL hash check is the final word.)
        stripped_only = only_used_by(elf, idx, set(missing)) - {u for f in found for u in uses(elf, idx, f)}
        gone = stripped_only if sec["name"] in STRIPPED_WITH_USER else frozenset()
        start, end, problems = place_section(elf, dol, idx, anchors.get(idx, []), known, gone)
        for p in problems:
            print(f"  {sec['name']}: {p}", file=sys.stderr)
        # Data the original doesn't have means a different source revision: the linker keeps it
        # and shifts everything after. Exempt are inline-function statics (merged across TUs) and
        # data used only by functions the linker stripped, which goes with them (OS.c's ZeroF).
        if start is None:
            # A section of nothing but inline-function statics has nothing of its own to place.
            # (Not extended to stripped-only data: a function that differs looks stripped too.)
            dsyms = data_symbols(elf, idx)
            if not dsyms or not all("$localstatic" in x["name"] for x in dsyms):
                ok = False
            continue
        # unplaced symbols are reported but don't fail the split; mismatches do
        if any("differ" in p or "anchored at both" in p or "overlaps" in p for p in problems):
            ok = False
        extra = [n for p in problems if p.startswith("not placed")
                 for n in p.split(": ", 1)[1].replace(" ...", "").split(", ")
                 if "$localstatic" not in n and n not in stripped_only]
        if extra:
            ok = False
        lines.append(f"\t{sec['name']:<11} start:0x{start:08X} end:0x{end:08X}")

    # Relocations are masked when comparing code, so check that each external reference lands
    # where the original's symbol of that name is (CARDWriteAsync: __CARDAccess vs __CARDIsWritable).
    for a, n in sorted(external_refs(elf, dol, found).items()):
        if n in syms and syms[n]["addr"] != a:
            print(f"  refers to {n} at {a:#x}, but the original's {n} is at {syms[n]['addr']:#x}", file=sys.stderr)
            ok = False

    if args.symbols:
        binds = {f["name"]: f["bind"] for f in funcs}
        for fname, a in sorted(found.items(), key=lambda kv: kv[1]):
            lines.append(f"# sym {a:08X} {fname} {'local' if binds[fname] == 0 else 'global'}")
        for a, n in sorted(external_refs(elf, dol, found).items()):
            lines.append(f"# sym {a:08X} {n} global")
        for a, x in sorted(PLACED, key=lambda p: p[0]):
            if not x["name"].startswith("@") and "$" not in x["name"]:
                lines.append(f"# sym {a:08X} {x['name']} {'local' if x['bind'] == 0 else 'global'}")
    name = args.name or (Path(args.obj).stem + ".c")
    print(f"{name}:")
    print("\n".join(lines))
    print(f"# {len(found)}/{len(funcs)} functions, {covered:#x} bytes of code; {'OK' if ok else 'NEEDS REVIEW'}",
          file=sys.stderr)
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
