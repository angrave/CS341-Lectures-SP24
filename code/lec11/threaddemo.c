#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_t mainthread;

void* say(void*arg) {
  write(1, arg, strlen(arg));
}

int main(int argc, char**argv) {
  pthread_t t1,t2;
  pthread_create(&t1, NULL, say, "Hello");
  pthread_create(&t2, NULL, say, "World");
}