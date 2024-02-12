#include <pthread.h>
#include <stdio.h>

void* shout(void*arg) {
  printf("%p\n", arg);
  fflush(stdout);
  pthread_exit(NULL);
}

#define N (100)
pthread_t tids[N];

int main() {
  for(int i = 0; i < N;i++)  {
    int result = pthread_create(tids+i, NULL, shout, tids+i);
    if(result!=0) perror("failed");
  }
  puts(" create calls finished!");
  for(int i = 0; i < N;i++)  {
    void* retValue;
    pthread_join(tids[i], &retValue);
  }
  puts("We are done!");
//  pthread_exit(NULL); // nver returns so exit() never happens!
  return 0;
}