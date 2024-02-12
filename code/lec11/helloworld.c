#include <pthread.h>
#include <stdio.h>

int bitcon(size_t hgh) ;

  struct args {
    size_t hgh;
    char*;
    FILE* file;
  }
void* shout(void*arg) {
  char* mesg = arg;
  printf("%s", mesg);
  fflush(stdout);
  //return 0xdeadcafe; 
  pthread_exit(0xdeadcafe);
}

int main() {
  pthread_t tidA, tidB; 
  //gotcha address of the array elements
  pthread_create( &tidA, NULL, shout,"Hello");
  pthread_create( &tidB, NULL, shout,"World");
  
  void* exitValue;
  //gotcha want thread ids
  pthread_join(tidA, &exitValue);
  pthread_join(tidB, NULL);
  printf("Exited with %p", exitValue);
  
  //pthread_exit(NULL);
  return 0;
}