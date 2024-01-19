#include <stdio.h>

int main(int argc, char** argv) {
  // for(int i = 0; i < argc; i++) {
  //   printf("%d: %s ", i, argv[i]);
  // }
  char** p = argv;
  while(*p) puts(*p++);
  return 0; // Success
}
