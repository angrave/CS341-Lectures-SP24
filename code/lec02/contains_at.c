#include <stdio.h>

int contains_at(char*);


int main(int argc, char** argv) {
  int result = contains_at(NULL);
  if(result) printf("Contains an @");
  else printf("No @ found");
  return 0;
}

int contains_at(char* ptr) {
  char *p = ptr;
  while( *p ) {
    if(*p == '@') return 1;
    p += 1; // or p++
  }
  return 0;
}
