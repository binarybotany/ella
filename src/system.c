#include "system.h"

void system_physics() {
  for (size_t i = 0; i < n_transforms; ++i) {
    transform_t *transform = &transforms[i];
    transform->x += 0.1f;
    transform->y += 0.1f;
  }
}