# combat

The combat hexagon of the instanced loot-action core loop: a dependency-free
core resolving the three-button combo timing, hit validation, the enemy
spawn-invulnerability window, and damage — behind narrow ports, with a Godot
wire adapter and a recorded fixture.

It follows the V-Sekai `core/` + `repository/` + `adapters/` triad
([hexagonal decision](https://v-sekai-multiplayer-fabric.github.io/manuals/decisions/20260610-hexagonal-core-ports-adapters.html))
and the [combat hexagon decision](https://v-sekai-multiplayer-fabric.github.io/manuals/decisions/20260611-hexagon-combat-core.html).

## The core

`core/CombatCore/Core.lean` is the pure reducer `step : State -> Event -> State x Effects`
over integer ticks: opener always swings; a chained press lands inside the
`[6, 18]`-tick window; the third strike resets the chain; the enemy blocks
inside its 30-tick spawn window; damage is `10/15/25` by stage.

- `#guard` fixtures pin the blocked opener, the full combo, the six-press kill,
  the whiff, and the combo drop.
- Plausible properties: state invariants, no hit inside the invulnerability
  window, and hp monotone under any event stream.
- `lake exe combat_emit` writes the golden event/effect trace.

## The wire (server authority)

`adapters/godot` runs the reducer server-authoritatively behind
`WebTransportPeer` (QUIC, `feat/module-http3`) in the merged double-precision
build; the client replays the golden script and asserts every effect in order.

```sh
GODOT=bin/godot.linuxbsd.editor.double.x86_64
$GODOT --headless --script adapters/godot/combat_server.gd &
COMBAT_GOLDEN=adapters/godot/combat_golden.csv \
  $GODOT --headless --script adapters/godot/combat_client.gd
# -> COMBAT WIRE PARITY PASS: 88 server-authoritative effects match the Lean trace
```

The GDScript server is a transcription of the proven reducer; the flat C ABI
binding is the production path, and the wire parity is what pins the behavior.
