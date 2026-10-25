# GitHub Actions

[.github/workflows/build.yml](/.github/workflows/build.yml) builds the project and uploads the
objdiff progress report, which [ByteMatch](https://bytematch.dev/vetusmagnus/SoAL-Decomp) reads
from runs on `main` (artifacts named `GEAE8P_report`).

## Self-hosted runner

The build needs the disc image, which can't be in the repository, so the job runs on a self-hosted
runner on the maintainer's PC. It hardlinks the local disc image into `orig/GEAE8P/` and uploads
only the report and the build log; no game data leaves that machine.

Setup, once:

1. Download the Windows runner from the repository's Settings > Actions > Runners > New
   self-hosted runner, and unpack it outside the repository.
2. `config.cmd --url https://github.com/<owner>/SoAL-Decomp --token <token> --labels soal`
3. `pip install --user ninja` in a normal shell.
4. If the disc image or ninja live somewhere else than the defaults in `build.yml`, set `SOAL_ISO`
   and `SOAL_NINJA` in the runner's `.env` file.
5. Start it with `run.cmd`. Jobs only run while it's running.

## Safety

Code from anyone else must never run on the runner's PC:

- The workflow has no `pull_request` trigger, so forks and pull requests never start it.
- It runs on pushes to `main` and manual runs only, and the job is skipped unless the push or run
  came from the repository owner.
- Merging a pull request does run its code on the next push, so review before merging.
