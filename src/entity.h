#ifndef ELLA_ENTITY_H_
#define ELLA_ENTITY_H_

#include <stdint.h>

typedef uint32_t entity_t;

entity_t entity_create() {
  static entity_t next = 0;
  return next++;
}

typedef struct {
  entity_t entity;
  uint32_t component_mask;
} entity_metadata_t;

entity_metadata_t *entities;

#endif