# ssi-engine Reference Acceleration Plan

Date: 2026-06-30

## Local Status

- Checkout: `references/ssi-engine/`
- Commit: `f10f96f277dbe27f75a39d87de8c4cc0f662155f`
- License: GPL-3.0
- Build: `.tools/apache-maven-3.9.9/bin/mvn clean package` succeeds under Java 21.
- Tests: `.tools/apache-maven-3.9.9/bin/mvn test` reports 14 tests, 0 failures, 6 skipped.
- Runtime: `scripts/run_ssi_engine_reference.sh` launches Matrix Cubed by classpath, not by jar, because upstream jar-mode config discovery assumes a directory classpath.

## What We Can Use Immediately

- Runtime oracle: compare screen/state behavior in Java against our Python/Pygame runtime when DOS capture is slow or unavailable.
- Format reference: DAX block loading, GEO map decoding, WALLDEF wall rendering, ECL script execution, text decoding, space-view state, and Buck Rogers-specific addresses.
- Address table: Matrix Cubed config names useful memory locations including GEO id, dungeon coordinates/facing, selected PC state, party count, combat result, combatants, ship enemy component values, money, and repair cost.
- Renderer reference: Java has a working first-person dungeon renderer and wallset builder that can help resolve our remaining wall/door parity gaps.
- ECL reference: Java includes a virtual machine and opcode table that can guide our dialog/choice/event compiler.

## Python Port Boundary

We should not blindly paste or mechanically translate Java source into Python without making the repo GPL-compatible and preserving attribution. The safer workflow is:

1. Use Java behavior as evidence.
2. Write small Python tests that encode observed behavior.
3. Reimplement the behavior in our existing Python architecture.
4. Cite `ssi-engine` as a reference when the implementation is derived from it.

If we decide to directly port substantial Java code, treat that as a licensing decision first: `ssi-engine` is GPL-3.0, so derivative code must be handled accordingly.

## Highest-Leverage Next Uses

1. ECL/dialog compiler: compare Java opcode handling and menu callbacks against our ECL disassembly, then wire missing choice/prompt behavior into Python.
2. Space/ship systems: use Java's Matrix Cubed address table and space-travel feature paths to recover Caloris/Luna transitions and ship-service menus.
3. Combat validation: compare Java combat state addresses and event VM behavior against our queued combat loop before changing mechanics.
4. Wall rendering parity: use Java WALLDEF and `DungeonRenderer` projection logic as reference for remaining door/front/side visual mismatches.
5. Save/state bridge: compare Java virtual memory addresses to our `SAVGAMA.DAT` and runtime state fields to reduce unknown save bytes.

## Commands

Launch Java reference engine:

```bash
cd /home/jzatopa/.openclaw/workspace/matrix-cubed-re
./scripts/run_ssi_engine_reference.sh
```

Build/test Java reference:

```bash
cd /home/jzatopa/.openclaw/workspace/matrix-cubed-re/references/ssi-engine
/home/jzatopa/.openclaw/workspace/matrix-cubed-re/.tools/apache-maven-3.9.9/bin/mvn test
```
