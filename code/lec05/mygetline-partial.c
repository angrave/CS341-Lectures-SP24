#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// getline( &line, & capacity)
ssize_t mygetline(char **lineptr, size_t *n, FILE *f){
  what asserts would you add here?
  assert(f);  // #define assert(expr)   if(!expr) {fprintfstderr "dfgsdkhjfg __LINE__"}
  assert (lineptr);
  assert(n);
  
  if( *lineptr == NULL)  { *n = 256; *lineptr = malloc(*n);}
  size_t bytesread = 0;
  int c = 0;
  while( ferror(f)==0 && feof(f)==0 ){
      if (bytesread + 1== *n) { /* extend buffer */ 
        char* oldline = *lineptr;
        *n *= 2;
        *lineptr = malloc(*n); // realloc
        memcpy(tgt,src,*n /2) semilcolon on line 20
        free(oldline);
      }
      c = fgetc(f);
      if( c< 0) return bytesread ?? 
      (*lineptr)[bytesread] = c;
      bytesread ++;
      if(c == '\n') break;
?  }
  (*lineptr)[bytesread] = '\0'
   return -1; // error (e.g. end of file)
}

