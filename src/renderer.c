#include "renderer.h"

struct renderer_t {
  component_t **components;
  size_t component_count;
};

renderer_t *renderer_create() {
  renderer_t *renderer = (renderer_t *)malloc(sizeof(renderer_t));
  if (renderer == NULL) {
    fprintf(stderr, "Unable to allocate memory to initialize renderer");
    return NULL;
  }
  return renderer;
}

void renderer_destroy(void *renderer) {
  renderer_t *r = (renderer_t *)renderer;
  free(renderer);
}

void renderer_update(renderer_t *renderer) {
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void renderer_render(renderer_t *renderer) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void renderer_system(renderer_t *renderer) {}