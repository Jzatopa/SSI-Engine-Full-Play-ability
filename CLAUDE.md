# Claude Code Instructions - Universal Java SSI Gold Box Engine

This project is building a near-preservation-level universal Java SSI Gold Box
engine. Buck Rogers: Matrix Cubed is the first proof target because local
original files and validation artifacts are available, but the engine should be
architected to play the wider SSI Gold Box catalog. Curse of the Azure Bonds is
also available on this computer and should become an early secondary validation
target once the Buck Rogers path is stable.

Evidence from original binaries, decoded artifacts, tests, DOS captures, and
ported COAB behavior takes precedence over guesses.

## Start here

1. Work in `/home/jzatopa/.openclaw/workspace/matrix-cubed-re`.
2. Read `HANDOFF.md` and `COLLABORATION.md` before changing anything.
3. Read the root workspace instructions:
   - `/home/jzatopa/.openclaw/workspaces/goldenbox/SOUL.md`
   - `/home/jzatopa/.openclaw/workspaces/goldenbox/USER.md`
   - `/home/jzatopa/.openclaw/workspaces/goldenbox/TOOLS.md`
4. Run `git status --short -- matrix-cubed-re` from
   `/home/jzatopa/.openclaw/workspace`. The Git root is the larger OpenClaw
   workspace; unrelated changes outside this directory belong to the user.
5. Add your task and intended files to `COLLABORATION.md` before editing. Do not
   edit files currently claimed by another agent.

## Working rules

- Never reset, clean, checkout, delete, or overwrite existing user/agent work.
- Do not run repository-wide formatting or destructive Git commands.
- Keep title-specific mechanics behind game/rules/data profiles. The Java SSI
  engine core must remain safe for other Gold Box games.
- The architecture target is a UI-neutral engine core with Swing/AWT as the
  first production frontend adapter. Gameplay logic, rules, file formats,
  combat, VM/ECL execution, save/load, and menus should not depend directly on
  Swing/AWT classes when an interface boundary is practical.
- Swing/AWT is still the first playable desktop frontend. Do not block
  playability for abstract architecture work, but keep new frontend-specific
  behavior outside core engine logic.
- COAB and other Gold Box reconstruction projects (Simeon Pilgrim's COAB,
  Gold Box Explorer, ssi-engine, etc.) may be ported/reused directly to save
  time on universal Gold Box engine mechanics (James, 2026-07-09: COAB has
  already achieved much of the target behavior; port it into Java, cite it,
  test it, and generalize it). When porting code or logic from an external
  project: record the source repo/commit and file in `HANDOFF.md`, keep it
  behind the universal engine boundary (not hardcoded to one title), and do
  not promote a reused project's game-specific offsets/formulas as confirmed
  evidence for a different title without independent confirmation against
  local original files/binaries. Label ported values as ported/candidate until
  validated.
  Licensing compliance (attribution, compatible terms with ssi-engine's
  GPL-3.0) is intentionally deferred and still needs a dedicated pass before
  any public release.
- Preserve original behavior and quirks when known, especially when they affect
  gameplay. Document preserved bugs/quirks so later cleanup or optional fixes
  can be made intentionally rather than accidentally.
- Do not invent names, offsets, formats, formulas, or test results. Mark
  hypotheses clearly and preserve raw evidence.
- Generated artifacts should be reproduced by scripts, not edited manually.
- Original game files stay outside the project and must not be committed or
  bundled. The engine should load user-provided original installs.
- Make small, focused changes with tests. Update `HANDOFF.md` after a completed
  pass and record completion in `COLLABORATION.md`.

## Completion standard

A ported subsystem is not done until the source and evidence are recorded,
focused Java tests cover the ported behavior, the Matrix Cubed smoke path still
passes, and original-game/DOS validation is added where feasible. Fixture skips
must be reported separately from passing tests.

## Validation

Python:

```bash
cd /home/jzatopa/.openclaw/workspace/matrix-cubed-re
source .venv/bin/activate
SDL_VIDEODRIVER=dummy SDL_AUDIODRIVER=dummy PYTHONPATH=src python3 -m pytest -q
```

Java SSI engine:

```bash
cd /home/jzatopa/.openclaw/workspace/matrix-cubed-re/references/ssi-engine
./mvnw test
```

If `./mvnw` is unavailable or unsuitable, consult `HANDOFF.md` for the locally
validated Maven command. Report fixture skips separately from passes.

## Finishing a task

1. Run focused tests and the appropriate full suite.
2. Run `git diff --check -- matrix-cubed-re` from the parent Git root.
3. Update `HANDOFF.md` with evidence, changes, tests, limitations, and next work.
4. Move your entry in `COLLABORATION.md` from Active work to Completed work.
5. Tell James exactly which files changed and what remains unresolved.
