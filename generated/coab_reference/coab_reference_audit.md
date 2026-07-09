# COAB Secondary-Reference Audit

COAB is used only as secondary evidence. Curse-specific content and unverified behavior are not promoted.

## ECL interpreter

- COAB command-table entries parsed: 65
- Integrated verified behavior: `LOAD MONSTER` queues argument-2 copies, normalizes zero to one, and caps the queue at 63.
- Matrix Cubed local proof includes ECL block 38 at `0x9754`: monster 11, copies 10, CPIC 11.
- Existing arithmetic, comparison/IF, ON GOTO/GOSUB, menu-index, and first-argument `LOAD FILES` semantics agree; no replacement was needed.
- Combat rules and Curse-specific handlers were not imported.

## ECL packed text

- Candidates checked: 10314 across 33 blocks
- Decoder mismatches: 0
- Compared the project whole-block decoder, project disassembler decoder, and an independent MSB-first bitstream decoder.

## GEO map layout

- Blocks checked: 25
- Cells checked: 6400
- Layout mismatches: 0
- Decoded block sizes observed: [1026]
- COAB adds no missing GEO field decode: our parser already matches all four 256-byte planes.
- COAB rendering/collision policy remains secondary and was not imported without Matrix Cubed behavioral proof.

## Provenance

- COAB commit: `9dc46f1d5911710fb2fcb7a9c0ec0ef74264d17c`
- ECL1 SHA-256: `5330bb436b3cac474506265db90cb3e0a888d7a9e5b0b65051d302035b60d854`
- GEO1 SHA-256: `398bab0120f5d16102aa121178d8f10d932a8db2bc23d96cb615dc6bb1171598`
