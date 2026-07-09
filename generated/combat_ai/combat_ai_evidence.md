# GAME.OVR Tactical Combat AI Evidence

- Source SHA-256: `d40f0309a114dbf2d9155c68404b0fb57cadb00e4841b3bfc335075a72296f67`
- Known local binary match: `True`
- ITEMS SHA-256: `9175c15b2390e12f007eed627fa5568a64bc761b81df0d5f43102f1669ca3a5c`
- ITEMS records: `39` × `9` bytes
- Boundary: Static pseudocode evidence; labels are conservative reconstruction names, not original SSI symbols.

## Candidate functions

### `0000:cb18` / file offset `52000`

Role: `automated_actor_action_loop_candidate` (high confidence)

- Loops over an actor while its combat-state action field remains active.
- Reads a remembered combatant pointer from actor combat-state offsets +8/+10.
- Enumerates candidate indices through DAT_0000_74ba and resolves pointers through DAT_0000_707f/DAT_0000_7081.
- Dispatches target/actor pairs to movement, engagement, or attack-support helpers.

### `0000:d18e` / file offset `53654`

Role: `attack_option_score_candidate` (medium confidence)

- Returns a byte-sized computed score.
- Combines linked-record fields, actor/target relation helpers, status checks, and a table-derived multiplier.

### `0000:d3bf` / file offset `54215`

Role: `linked_attack_option_selector_candidate` (high confidence)

- Walks a linked list at actor offsets +0xf7/+0xf9.
- Indexes a 9-byte table at DAT_0000_536e using each record byte +0x2e.
- Scores table type 0 through 0000:d18e and retains the greatest score.
- Handles table types 1 and 6 through distinct branches.

### `0000:d805` / file offset `55309`

Role: `remembered_target_validation_and_search_candidate` (high confidence)

- Validates or clears the remembered target at combat-state offsets +8/+10.
- Searches candidate combatants with an explicit 0x14 (20) iteration bound.
- Stores the selected candidate pointer back at combat-state offsets +8/+10.

## Unresolved

- Exact semantics and raw contents of the 9-byte DAT_0000_536e table.
- Exact candidate ranking performed by unresolved helper calls.
- Exact movement/path dispatch and morale thresholds.
