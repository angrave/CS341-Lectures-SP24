#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv) {
   char* lineptr = 0;
   size_t capacity = 0;
   puts("What is thy wish o awesome person?");
   ssize_t numchars = getline(&lineptr, &capacity, stdin);
   if(numchars>0 && lineptr[numchars-1] == '\n') {
     lineptr[numchars-1] = '\0';
   } 
   printf("about to run <%s>\n", lineptr);
   execlp(lineptr /*load from disk*/, lineptr /* process name*/, (char*) NULL);
   perror("Huh?"); // should not get here
   return 0;
}
