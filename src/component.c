#include "component.h"

transform_t *transforms = NULL;
size_t n_transforms = 0;

render_t *renderers = NULL;
size_t n_renderers = 0;

void transform_add(entity_t entity, float x, float y, float z) {
  transforms = realloc(transforms, sizeof(transform_t) * (n_transforms + 1));
  transforms[n_transforms++] = (transform_t){entity, x, y, z};
}

void transform_remove(entity_t entity) {
  for (size_t i = 0; i < n_transforms; ++i) {
    if (transforms[i].entity == entity) {
      transforms[i] = transforms[--n_transforms];
      transforms = realloc(transforms, sizeof(transform_t) * n_transforms);
      return;
    }
  }
}

transform_t *transform_get(entity_t entity) {
  for (size_t i = 0; i < n_transforms; ++i) {
    if (transforms[i].entity == entity) {
      return &transforms[i];
    }
  }
  return NULL;
}

void renderer_add(entity_t entity, const char *texture) {
  renderers = realloc(renderers, sizeof(render_t) * (n_renderers + 1));
  strcpy(renderers[n_renderers].texture, texture);
  renderers[n_renderers++].entity = entity;
}

void renderer_remove(entity_t entity) {
  for (size_t i = 0; i < n_renderers; ++i) {
    if (renderers[i].entity == entity) {
      renderers[i] = renderers[--n_renderers];
      renderers = realloc(renderers, sizeof(render_t) * n_renderers);
      return;
    }
  }
}

render_t *renderer_get(entity_t entity) {
  for (size_t i = 0; i < n_renderers; ++i) {
    if (renderers[i].entity == entity) {
      return &renderers[i];
    }
  }
  return NULL;
}