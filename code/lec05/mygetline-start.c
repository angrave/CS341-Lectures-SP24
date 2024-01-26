#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

ssize_t mygetline(char **lineptr, size_t *n, FILE *f){
  what asserts would you add here?


  if( _____)  { *n = 256; _________ = malloc(*n);}
  size_t bytesread = 0;
  int c = 0;
  while( ferror(f)==0 && feof(f)==0 ){
      if (bytesread == *n) { /* extend buffer */ 
?
      }
      c = fgetc(f);
?  }
   return -1; // error (e.g. end of file)
}

