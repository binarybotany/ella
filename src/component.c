#include "component.h"

transform_t *transforms = NULL;
size_t n_transforms = 0;
size_t max_transforms = 0;
size_t entity_to_transforms[MAX_ENTITIES];
pthread_mutex_t transform_mutex = PTHREAD_MUTEX_INITIALIZER;

void component_startup() {
  pthread_mutex_lock(&transform_mutex);
  for (size_t i = 0; i < MAX_ENTITIES; ++i) {
    entity_to_transforms[i] = NO_COMPONENT;
  }
  pthread_mutex_unlock(&transform_mutex);
}

void component_shutdown() {
  pthread_mutex_lock(&transform_mutex);
  free(transforms);
  transforms = NULL;
  n_transforms = 0;
  max_transforms = 0;
  pthread_mutex_unlock(&transform_mutex);
  pthread_mutex_destroy(&transform_mutex);
}

void transform_add(entity_t entity, float x, float y, float z) {
  if (entity >= MAX_ENTITIES) {
    fprintf(stderr, "Entity %d is out of range\n", entity);
    return;
  }

  pthread_mutex_lock(&transform_mutex);

  if (entity_to_transforms[entity] != NO_COMPONENT) {
    fprintf(stderr, "Entity %d already has a transform component\n", entity);
    pthread_mutex_unlock(&transform_mutex);
    return;
  }

  if (n_transforms == max_transforms) {
    max_transforms = max_transforms == 0 ? 1 : max_transforms * 2;
    transforms = realloc(transforms, sizeof(transform_t) * (max_transforms));
    if (!transforms) {
      fprintf(stderr, "Unable to allocate memory for transforms\n");
      pthread_mutex_unlock(&transform_mutex);
      return;
    }
  }

  transforms[n_transforms] = (transform_t){entity, x, y, z};
  entity_to_transforms[entity] = n_transforms;
  n_transforms++;

  pthread_mutex_unlock(&transform_mutex);
}

void transform_remove(entity_t entity) {
  if (entity >= MAX_ENTITIES) {
    fprintf(stderr, "Entity %d is out of range\n", entity);
    return;
  }

  pthread_mutex_lock(&transform_mutex);
  size_t index = entity_to_transforms[entity];

  if (index == NO_COMPONENT) {
    fprintf(stderr, "Entity %d does not have a transform component\n", entity);
    pthread_mutex_unlock(&transform_mutex);
    return;
  }

  transforms[index] = transforms[--n_transforms];
  entity_to_transforms[transforms[index].entity] = index;
  entity_to_transforms[entity] = NO_COMPONENT;

  pthread_mutex_unlock(&transform_mutex);
}

transform_t *transform_get(entity_t entity) {
  if (entity >= MAX_ENTITIES) {
    fprintf(stderr, "Entity %d is out of range\n", entity);
    return;
  }

  pthread_mutex_lock(&transform_mutex);
  size_t index = entity_to_transforms[entity];
  transform_t *result = (index != NO_COMPONENT) ? &transforms[index] : NULL;
  pthread_mutex_unlock(&transform_mutex);

  return result;
}