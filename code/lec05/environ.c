#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {

getenv("HOME");

getenv("PATH");

getenv("USER") ;

getenv("AWESOME");

extern char** environ;

return 0;
}
