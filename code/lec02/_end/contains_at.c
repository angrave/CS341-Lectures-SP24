
#if 0
double * ptr = r
  while(i++ < N) *ptr ++ = 42;

findat(0x1235451243)
findat(double*     ptr) {}

float A[7];

sizeof(A) / sizeof(A[0])
  28 / 4


char* mys = malloc(1200);
strcpy(mys,"hello");
strcat(mys,"world");
#endif
//open -- system call 
//FILE* fh = fopen("mydata.txt" ,"r")  -- c library
//fscanf("%d,%d,%d", &x, fh)  
//  fgetchar(fh) 


//  mmap
#include <stdio.h>

int mystrlen(char*ptr) {
  int size = 0;
  while( ptr[size] != '\0') size++;
  return size;
}
#if 0
int contains_at_ON2(char* ptr) {
  for( int i = 0; i < strlen(ptr); i++)
    if( ptr[i] == '@' ) {
      return 1;
    }
    
  return 0;
}
#endif

int contains_at(char* ptr) { // 0000 0000 'NUL' 
  char temp;
  while( ((temp= * ptr ++) != '\0') && (temp != '@')) {};
  return temp == '@'; 
}

int main(int argc, char** argv) {
  printf("hello world\n%p", (char*) main);
  char* ptr = main;
  *ptr='!';
  return 0;
  int result = contains_at("hello");
  if(result) printf("Contains an @");
  else printf("No @ found");
  return 0;
}



