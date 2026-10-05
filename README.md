# contract-combat

The combat core of the loot-action loop: a pure Lean 4 reducer behind narrow ports, with an engine wire adapter and a recorded trace.

## What it is for

The core resolves combo timing, hit validation, the enemy spawn-invulnerability window and damage as a deterministic step over integer ticks, so combat is testable with no server and no headset. The engine adapter runs the same rules with the server as authority and replays the recorded trace, so the wire is checked against the core. [RFD 2040](https://github.com/V-Sekai-fire/manuals-weftspun/tree/main/rfd/2040-hexagon-combat-core) owns the design and [RFD 2028](https://github.com/V-Sekai-fire/manuals-weftspun/tree/main/rfd/2028-hexagonal-core-ports-adapters) the core, ports and adapters layout.

## Build and run

```sh
cd core
lake build combat_demo
lake exe combat_emit
```

Building `combat_demo` checks the fixtures and properties. `combat_emit` writes the recorded trace to `core/build/combat_golden.csv`; the adapter replays its committed copy in `adapters/godot/combat_golden.csv`, so a new trace is copied there.

## Licence

The licence is not stated.
