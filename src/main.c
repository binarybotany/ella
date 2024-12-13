#include <stdio.h>

#define GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "hash_table.h"

int main(int argc, char **argv) {
  if (!glfwInit()) {
    fprintf(stderr, "Unable to initialize GLFW\n");
    return 1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  GLFWwindow *window = glfwCreateWindow(1024, 768, "Ella", NULL, NULL);
  if (!window) {
    fprintf(stderr, "Unable to create a window\n");
    return 1;
  }

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    fprintf(stderr, "Unable to initialize OpenGL context\n");
    return 1;
  }

  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  return 0;
}