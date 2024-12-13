#include <stdio.h>

#define GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <glfw/glfw3.h>

int main(int argc, char **argv) {
  if (!glfwInit()) {
    return 1;
  }

  fprintf(stdout, "%s\n", argv[0]);
  return 0;
}