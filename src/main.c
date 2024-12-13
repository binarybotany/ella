#include <stdio.h>

int main(int argc, char **argv) {
  fprintf(stdout, "%s\n", argv[0]);
  return 0;
}