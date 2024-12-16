#include "system.h"

void system_physics() {
  for (size_t i = 0; i < n_transforms; ++i) {
    transform_t *transform = &transforms[i];
    transform->x += 0.1f;
    transform->y += 0.1f;
  }
}

void system_render() {
  for (size_t i = 0; i < n_renderers; ++i) {
    render_t *renderer = &renderers[i];
    transform_t *transform = transform_get(renderer->entity);

    if (transform) {
      /* Do the thing */
    }
  }
}