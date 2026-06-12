# fixture adapter

`../godot/combat_golden.csv` is the recorded event/effect trace the Lean core
emits for the canonical kill script (`lake exe combat_emit`): spawn, the
invulnerability wait, two full timed combos to the kill, a swing at air, and a
combo drop. CI replays it through the core (`lake build` elaborates the
`#guard` fixtures and Plausible properties) and through the wire adapter.
