#include <stdio.h>

#define GLFW_INCLUDE_NONE

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include "hash_table.h"

int main(int argc, char **argv) {
  hash_table_t *table = create_hash_table();

  hash_table_insert(table, "name", "Vilkutas");
  hash_table_insert(table, "age", "3");
  hash_table_insert(table, "color", "Gray");

  fprintf(stdout, "Name: %s\n", hash_table_search(table, "name"));
  fprintf(stdout, "Color: %s\n", hash_table_search(table, "color"));

  hash_table_remove(table, "age");

  destroy_hash_table(table);

  if (!glfwInit()) {
    return 1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

  GLFWwindow *window = glfwCreateWindow(1024, 768, "Ella", NULL, NULL);
  if (!window) {
    return 1;
  }

  glfwMakeContextCurrent(window);
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    return 1;
  }

  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();

    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  fprintf(stdout, "%s\n", argv[0]);
  return 0;
}