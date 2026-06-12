#ifndef COMBAT_BEHAVIOR_SOURCE_H
#define COMBAT_BEHAVIOR_SOURCE_H
#include <stdint.h>
/* Driving port. Enemy intents (spawns, moves) from sandboxed generated logic. */
typedef struct { uint32_t kind; uint32_t arg; } combat_intent;
typedef struct combat_behavior_source {
  void *ctx;
  int (*poll)(void *ctx, combat_intent *out);
} combat_behavior_source;
#endif
