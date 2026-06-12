#ifndef COMBAT_STATE_SINK_H
#define COMBAT_STATE_SINK_H
#include <stdint.h>
/* Driven port. Authoritative combat state out to replication. */
typedef struct combat_state_sink {
  void *ctx;
  void (*publish)(void *ctx, const uint8_t *state_bytes, uint32_t len);
} combat_state_sink;
#endif
