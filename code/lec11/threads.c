#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int counter;
void* dog(void* message) {
  char* mesg = message;
  puts(mesg);
  char* result = malloc(10);
  sprintf(result, "%d\n", (int)pthread_self());
  
  pthread_exit(result);
  return result;
}

int main() {
  pthread_t tid1, tid2;
  pthread_create( &tid1, /*Attribs*/ NULL, dog, "HELLO" );
  pthread_create( &tid2, /*Attribs*/ NULL, dog, "WORLD" );
  
  void* mythreadsaid;
  pthread_join(tid2, &mythreadsaid);
  printf("Thread 2 exited with %s", (char*) mythreadsaid);
  free(mythreadsaid);
  sleep(2);
  pthread_join(tid1, NULL);
  puts("All done - byeeee");
  return 0; // time to go away 
}
