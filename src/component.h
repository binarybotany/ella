#ifndef ELLA_COMPONENT_H_
#define ELLA_COMPONENT_H_

#include <stdlib.h>

#include "entity.h"
#include "hashtable.h"

#define COMPONENT_TRANSFORM (1 << 0)

typedef struct {
  float x, y, z;
} transform_t;

typedef struct {
  entity_t entity;
  transform_t data;
} transform_entry_t;

transform_entry_t *transforms;
size_t ntransforms;
hashtable_t *transform_map;

void transform_add(entity_t entity, transform_t transform);

#endif