#ifndef ELLA_COMPONENT_H_
#define ELLA_COMPONENT_H_

#include <stdlib.h>
#include <string.h>

#include "entity.h"

#define COMPONENT_TRANSFORM (1 << 0)
#define COMPONENT_RENDERER (1 << 1)

typedef struct {
  entity_t entity;
  float x, y, z;
} transform_t;

typedef struct {
  entity_t entity;
  char texture[256];
} render_t;  // TODO rename

extern transform_t *transforms;
extern size_t n_transforms;

extern render_t *renderers;
extern size_t n_renderers;

void transform_add(entity_t entity, float x, float y, float z);
void transform_remove(entity_t entity);
transform_t *transform_get(entity_t entity);

void renderer_add(entity_t entity, const char *texture);
void renderer_remove(entity_t entity);
render_t *renderer_get(entity_t entity);

#endif