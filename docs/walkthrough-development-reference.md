# Walkthrough Development Reference

Source: GameFAQs, "Buck Rogers: Matrix Cubed - Guide and Walkthrough" by kibbitz, updated 2023-08-30.

URL: https://gamefaqs.gamespot.com/pc/577927-buck-rogers-matrix-cubed/faqs/80490

## Use Policy

Use this walkthrough as secondary gameplay evidence for development planning, route validation, and acceptance tests. Do not copy its prose into runtime data, generated game text, or source-equivalent reconstruction artifacts. Original binaries, decoded assets, ECL/GEO evidence, and DOS captures remain primary evidence.

## Development Value

The guide is useful for:

- confirming intended progression order,
- identifying important coordinates to validate against decoded GEO/ECL events,
- building smoke-test routes through the playable runtime,
- checking mechanics such as starting equipment, ship fuel, banks, shops, healing, training, and logbook progress,
- prioritizing missing systems that block start-to-finish play.

## Route Order For Acceptance Testing

The walkthrough's main route can become a staged validation checklist:

1. Caloris opening, Romney/Sun King incident, Sid Refuge encounter.
2. Spaceflight/free travel setup, Ceres objective, ship-fuel economy.
3. Ceres / Doomsday laser sequence.
4. Early side/plot branches around Luna, Venus, Mars, and Losangelorg.
5. Historical museum sequence.
6. PURGE headquarters and prison sequences.
7. Optional Losangelorg cleanup.
8. Copernicus crime/investigation sequence.
9. Time-bomb sequence.
10. Captured/prison equipment-loss sequence.
11. Mole hunt.
12. Pirate and Stormrider negotiation sequence.
13. Stormrider University attack.
14. Late capture sequence.
15. Jupiter finale / Matrix endgame.

These are not source names unless the decoded game data confirms them. Use them as playthrough labels for tests and handoff notes.

## Immediate Runtime Checkpoints

Convert these into local validation data only after matching them to decoded GEO/ECL rows or DOS captures.

| Area | Walkthrough checkpoint | Development use |
|---|---|---|
| Caloris Space Port | Start at coordinate `(0,2)` facing east after the opening briefing. | Validate initial map load, map direction, and starting event chain. |
| Caloris Space Port | Dockside Supplies is called out at `(3,4)` and an auto-clinic at `(4,4)`. | Validate shop/clinic event IDs and UI commands. |
| Caloris Space Port | Security office, Berth A, Romney/Sun King/Sid Refuge path are early required checks. | Build first story smoke route and combat reward checks. |
| Spaceflight | Ship starts with a fuel pool and travel consumes fuel based on navigation success/failure. | Implement ship fuel state and Navigation/Astrogation validation. |
| Stormrider University | Start at `(3,4)`; training and shop are called out before the attack sequence. | Validate GEO 112 entry point, training/shop events, and attack transition. |
| Jupiter finale | Start at `(7,4)`; auto-clinic, safety-net rooms, Nikita, aircar hatch, and repeated attack rounds are called out. | Build final-act route tests for GEO 114/115 and multi-stage event progression. |

## Mechanics To Cross-Check

- Starting party grant: credits plus a set of weapons, armor, and grenades after Buck's briefing.
- THAC0 hit logic: use the guide only as a comparison note; keep local combat validation tied to decoded stats and DOS captures.
- Weapon data: ranges, damage dice, rate of fire, and ammo should be cross-checked against decoded ITEM0/ITEMS fields before runtime promotion.
- Post-combat healing: guide descriptions should guide liveplay tests, not become authoritative formulas.
- Ship combat/travel: fuel, refuel, repairs, banks, NEO account, hailing, bluff/intimidate, and random ship encounters need runtime systems.
- Captured/no-equipment segments: inventory removal/restoration must be modeled before the walkthrough route can be completed.

## Implementation Backlog

1. Create a compact route-checkpoint JSON generated from confirmed local evidence, with walkthrough labels only as secondary annotations.
2. Add a developer route runner that can teleport to `(GEO, x, y, facing)` and trigger the local event.
3. Add focused tests for the Caloris opening route: starting state, Dockside Supplies, auto-clinic, Romney branch, Security/Help options, Sid Refuge combat.
4. Add ship-state data to `GameState`: fuel, NEO account, repair/restock/refuel endpoints, and travel result hooks.
5. Link guide checkpoints to `docs/ecl-dialog-trees-reference.md` owner targets once ECL menu/prompt recovery is stronger.
6. Use DOSBox captures to verify guide-derived checkpoints before marking story progression complete.

## Evidence Status

- The guide confirms a coherent start-to-finish play route, but it is not a substitute for missing binary data.
- The Gold Box Explorer map audit currently supports the 25 decoded `GEO1.DAX` maps as the local map set available to this project.
- The next useful pass is a Caloris route-validation dataset that ties guide coordinates to decoded GEO event cells and ECL branch targets.
