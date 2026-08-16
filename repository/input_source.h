#ifndef COMBAT_INPUT_SOURCE_H
#define COMBAT_INPUT_SOURCE_H
#include <stdint.h>
/* Driving port. Player presses with the server tick they arrive on. */
typedef struct { uint32_t player; uint32_t tick; } combat_input;
typedef struct combat_input_source {
  void *ctx;
  int (*poll)(void *ctx, combat_input *out); /* 1 = produced, 0 = none */
} combat_input_source;
#endif
