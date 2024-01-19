#include <stdio.h>

int main(int argc, char** argv) {
  // char* squirrel;
//   asprintf ( &squirrel, "Number is %d: %s , %s", 42, s1, s2);
//   free( squirrel );
#ifdef meatloafisalive
  printf("Process is %s\n", argv[0]);
  for(int i =0; i < argc; i++) {
    printf("%s\n", argv[i]);
    puts(argv[i]);
  }
#endif
  char** p = argv;
  // while( *p ) {
  //   puts(*p);
  //   p++;
  // }
  while(*p) puts(*p++);
  return 0; // Success
}
