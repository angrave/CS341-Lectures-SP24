// Lawrence Angrave CS241 Lecture Demo
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h> 

ssize_t mygetline(char **lineptr, size_t *n, FILE *f){
  assert(lineptr);
  assert(n);
  assert(f);
  if( *n == 0 || *lineptr == NULL)  { 
    *n = 256; 
    *lineptr = malloc(*n);
  }
  size_t bytesread = 0;
  int c = 0;
  while( ferror(f)==0 && feof(f)==0 ){
      if (bytesread + 1 == *n) { /* extend buffer. +1 because we will need space for the NUL byte */ 
        *n *= 2;
        void* old = *lineptr; // In the future we will learn about realloc
        *lineptr = malloc(*n);
        memcpy( *lineptr, old, bytesread );
        free( old );
      }
      c = fgetc(f);
      if( c == -1) { 
         if( ferror(f) || bytesread == 0 ) {
          return -1;
        }
        (*lineptr)[bytesread] = '\0';
        return bytesread;
      }
      (*lineptr)[bytesread++] =  c;
      // returned value does not include writing the NUL byte
      if(c == '\n') { 
         (*lineptr)[bytesread] = '\0'; 
         return bytesread; 
      }
  }
  return -1; // error (e.g. end of file)
}

int main(int argc, char**argv) {
  if(argc != 2) { fprintf(stderr,"Usage: %s filename\n", argv[0]); exit(1);}

  FILE* file = fopen(argv[1], "r"); // may return NULL if argv[1] is an invalid filename
  if(!file) {
    perror("Failed to open file");
    exit(1);
  }
  char* line = NULL;
  size_t capacity=0;
  ssize_t bytesread;
  int linenumber = 1;
  while(1) {
    bytesread = mygetline( &line, &capacity, file);
    if(bytesread == -1) break;
    printf("%3d: %s", linenumber++, line);
  }
  free(line);
  fclose(file);
  return 0;
}
