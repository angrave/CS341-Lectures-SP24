#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
   close(1); // close standard out
   open("log.txt", O_RDWR | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
   puts("Captain's log");
   fflush(stdout);
   chdir("/usr/bin");
   execl("/bin/ls", "ls",".",(char*)NULL); // "ls ."
   perror("exec failed");
   return 0; // Not expected
}
