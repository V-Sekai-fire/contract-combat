#ifndef COMBAT_EVENT_SINK_H
#define COMBAT_EVENT_SINK_H
#include <stdint.h>
/* Driven port. Hits, deaths, and door unlocks out to gameplay. */
typedef struct combat_event_sink {
  void *ctx;
  void (*emit)(void *ctx, uint32_t effect, uint32_t arg);
} combat_event_sink;
#endif
