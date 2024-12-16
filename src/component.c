#include "component.h"

transform_t *transforms = NULL;
size_t n_transforms = 0;
size_t entity_to_transforms[MAX_ENTITIES];

void component_startup() {
  for (size_t i = 0; i < MAX_ENTITIES; ++i) {
    entity_to_transforms[i] = NO_COMPONENT;
  }
}

void component_shutdown() { free(transforms); }

void transform_add(entity_t entity, float x, float y, float z) {
  if (entity_to_transforms[entity] != NO_COMPONENT) {
    fprintf(stderr, "Entity %d already has a transform component\n", entity);
    return;
  }

  transforms = realloc(transforms, sizeof(transform_t) * (n_transforms + 1));
  transforms[n_transforms] = (transform_t){entity, x, y, z};
  entity_to_transforms[entity] = n_transforms;
  n_transforms++;
}

void transform_remove(entity_t entity) {
  size_t index = entity_to_transforms[entity];

  if (index == NO_COMPONENT) {
    fprintf(stderr, "Entity %d does not have a transform component\n", entity);
    return;
  }

  transforms[index] = transforms[--n_transforms];
  entity_to_transforms[transforms[index].entity] = index;
  entity_to_transforms[entity] = NO_COMPONENT;
  transforms = realloc(transforms, sizeof(transform_t) * n_transforms);
}

transform_t *transform_get(entity_t entity) {
  size_t index = entity_to_transforms[entity];
  if (index == NO_COMPONENT) return NULL;
  return &transforms[index];
}