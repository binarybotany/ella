#ifndef ELLA_COMPONENT_H_
#define ELLA_COMPONENT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "entity.h"

#define NO_COMPONENT -1

typedef struct {
  entity_t entity;
  float x, y, z;
} transform_t;

extern transform_t *transforms;
extern size_t n_transforms;
extern size_t entity_to_transforms[MAX_ENTITIES];

void component_startup();
void component_shutdown();

void transform_add(entity_t entity, float x, float y, float z);
void transform_remove(entity_t entity);
transform_t *transform_get(entity_t entity);

#endif