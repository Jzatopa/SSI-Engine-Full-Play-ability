# Story Progression Scene Validation

This report ties the HTML runtime seed and source-runtime probes to local DOS liveplay captures.
It separates confirmed local reconstruction checks from capture limits so uncertain text/menu ownership is not overstated.

## Summary

- Scenes: 5
- Passing scenes: 5
- Evidence limit: DOS screenshots are hashed and tied to scene families; exact prompt OCR/pixel equivalence is marked where still pending.

## Scenes

### Caloris floor and ceiling sprites

- Status: `pass`
- DOS capture: `/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens/z_a01_game_world.png`
- Capture SHA-256: `8b5e6bea3d76d3e33a454080a429f9669449d8ac95220fa9c7a6a20c4036640b`
- Capture dimensions: `1280x1024`
- Limit: Capture confirms an original-game world baseline exists; this pass does not pixel-match viewport textures to DOS.

| Check | Status |
|---|---|
| Caloris ceiling texture is present in runtime seed. | `pass` |
| Caloris floor texture is present in runtime seed. | `pass` |
| Ceiling texture PNG exists on disk. | `pass` |
| Floor texture PNG exists on disk. | `pass` |
| DOS liveplay capture exists for loaded game-world baseline. | `pass` |

### Caloris Dr. Romney dialog choice

- Status: `pass`
- DOS capture: `/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens/12_after_interaction.png`
- Capture SHA-256: `fa9cd5ff299e2eb8e1b50441f56dc27d526a4fb191a0ab71b5357f887c2e8114`
- Capture dimensions: `1280x1024`
- Limit: Runtime choice is tied to decoded ECL text/reference evidence; the current DOS capture is not OCR-confirmed for this exact text.

| Check | Status |
|---|---|
| Caloris event 20 is the Dr. Romney encounter. | `pass` |
| ECL dialog reference exposes HELP ROMNEY as an executable choice. | `pass` |
| DOS liveplay has an interaction-stage capture available. | `pass` |

### Caloris autodoc branch choice

- Status: `pass`
- DOS capture: `/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens/12_after_interaction.png`
- Capture SHA-256: `fa9cd5ff299e2eb8e1b50441f56dc27d526a4fb191a0ab71b5357f887c2e8114`
- Capture dimensions: `1280x1024`
- Limit: Runtime choice is tied to decoded ECL text/reference evidence; exact DOS prompt capture remains a later liveplay target.

| Check | Status |
|---|---|
| Caloris event 28 is the autodoc healing prompt. | `pass` |
| ECL dialog reference exposes SOMEONE ELSE? as an executable choice. | `pass` |
| DOS liveplay has an interaction-stage capture available. | `pass` |

### Caloris RAM Warrior combat progression

- Status: `pass`
- DOS capture: `/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens/14_after_combat_inputs.png`
- Capture SHA-256: `ce05dfe1e7b292bb09f6121ecb712a08605424597cd21726f5e4dafe58cd43d4`
- Capture dimensions: `1280x1024`
- Limit: Combat queue is decoded locally; the DOS capture anchors combat UI availability, not a turn-by-turn equivalence check.

| Check | Status |
|---|---|
| Source-runtime probe targets Caloris event 7. | `pass` |
| Caloris event 7 is classified as combat. | `pass` |
| Caloris event 7 queues RAM WARRIOR. | `pass` |
| DOS liveplay has a combat-input capture available. | `pass` |

### GEO 021 dynamic combat branch

- Status: `pass`
- DOS capture: `/home/jzatopa/.openclaw/workspace/matrix-cubed-re/generated/liveplay/screens/f_04_after_search.png`
- Capture SHA-256: `6acf96cd641bdf91828793c936b6c810ef94512a44b2084f334f8dcae5cfeae1`
- Capture dimensions: `1280x1024`
- Limit: Dynamic encounter candidates are locally decoded; exact branch selection still needs a targeted DOS route capture.

| Check | Status |
|---|---|
| GEO 021 event 4 is a combat candidate in the HTML runtime seed. | `pass` |
| Dynamic encounter candidate table is preserved. | `pass` |
| DOS liveplay has a search/exploration capture available. | `pass` |
