#include "window.h"

struct window_t {
  char *title;
  size_t width, height;
  GLFWwindow *glfw_window;
};

window_t *window_create() {
  window_t *window = (window_t *)malloc(sizeof(window_t));
  window->title = strdup("Ella");
  window->width = 1024;
  window->height = 768;

  if (!glfwInit()) {
    fprintf(stderr, "Unable to initialize GLFW\n");
    return NULL;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  window->glfw_window = glfwCreateWindow(window->width, window->height,
                                         window->title, NULL, NULL);
  if (!window->glfw_window) {
    fprintf(stderr, "Unable to create a window\n");
    return NULL;
  }

  glfwMakeContextCurrent(window->glfw_window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    fprintf(stderr, "Unable to initialize OpenGL context\n");
    return NULL;
  }

  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

  return window;
}

void window_loop(window_t *window, void (*update)(), void (*render)()) {
  while (!glfwWindowShouldClose(window->glfw_window)) {
    glfwPollEvents();
    update();
    render();
    glfwSwapBuffers(window->glfw_window);
  }
}

void window_destroy(void *window) {
  window_t *w = (window_t *)window;
  glfwDestroyWindow(w->glfw_window);
  glfwTerminate();

  free(w->title);
  free(w);
}