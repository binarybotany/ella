#include <stdbool.h>
#include <stdio.h>

#include "hash_table.h"
#include "window.h"

bool run(hash_table_t *state) {
  window_t *window = (window_t *)ht_search(state, "window");
  if (!window) {
    fprintf(stderr, "Unable to find window in state\n");
    return false;
  }
  while (!glfwWindowShouldClose(window_get_glfw_window(window))) {
    glfwPollEvents();
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window_get_glfw_window(window));
  }

  return true;
}

int main(int argc, char **argv) {
  hash_table_t *state = ht_create(128);
  window_t *window = window_create();
  if (!ht_insert(state, "window", window, &window_destroy)) {
    fprintf(stderr, "Unable to insert window in state\n");
    return 1;
  }

  if (!run(state)) {
    return 1;
  }

  ht_destroy(state);

  return 0;
}