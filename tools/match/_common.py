"""Shared helpers for the variant searches: write a temporary copy of a source file, diff it."""
import os, subprocess

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
WORK = os.path.join(ROOT, "build", "match")
FDIFF = os.path.join(os.path.dirname(os.path.abspath(__file__)), "fdiff.py")


def score(text, fns, tag):
    """Diff line count of FNS when the source is TEXT; 999 if it doesn't compile."""
    os.makedirs(WORK, exist_ok=True)
    path = os.path.join(WORK, f"_v{os.getpid()}_{tag}.c")
    with open(path, "w") as f:
        f.write(text)
    r = subprocess.run(["python3", FDIFF, path] + list(fns), capture_output=True, text=True)
    os.remove(path)
    if r.returncode or "== " not in r.stdout:
        return 999
    return sum(1 for l in r.stdout.splitlines() if l[:1] in "+-" and l[1:2].isalpha())
