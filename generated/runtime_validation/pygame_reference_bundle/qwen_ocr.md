# Pygame Reference Bundle Qwen OCR

Model: `ollama/qwen3.6:latest` via `openclaw infer model run --file`.

## `screens/caloris_romney_dialog.png`

```text
[S]
Pos: (4,0)
Credits: 100
HP: 38 / CAR1
Steps: 0
"A MAN CARRYING A BUNDLE OF PAPERS RUSHES UP TO YOU. HE GRABS YOUR ARM DE
1. HELP ROMNEY
```

Verdict: Qwen judged the UI text sharp and high-contrast. Boundary: the dialog text is visibly truncated by the runtime overlay width.

## `screens/caloris_autodoc_dialog.png`

```text
[S]
Pos: (4,5)
Credits: 100
HP: 38 / CAR1
Steps: 0
"THE AUTODOCS HUM SOOTHINGLY. 'DO YOU NEED HEALING?'"
1. SOMEONE ELSE?
```

Verdict: Qwen judged the text clear, high contrast, and unambiguous.

## `screens/caloris_combat.png`

```text
COMBAT
Turn 1 | HP: 100 | RAM WARRIOR(35)

Combat! RAM WARRIOR
RAM WARRIOR: d20 3+2 vs AC 10 = miss

SPACE=next I=inv C=char O=shop F5=save ESC=quit
```

Verdict: Qwen judged the combat UI text clearly legible against the dark background.
