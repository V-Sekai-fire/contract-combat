#ifndef COMBAT_TICK_SOURCE_H
#define COMBAT_TICK_SOURCE_H
#include <stdint.h>
/* Driving port. The constant-step clock the core advances on. */
typedef struct combat_tick_source {
  void *ctx;
  uint32_t (*now)(void *ctx);
} combat_tick_source;
#endif
