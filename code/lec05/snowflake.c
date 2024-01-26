// Original version by Wade Fagen, University of Illinois

#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/ioctl.h>

// http://stackoverflow.com/questions/26423537/how-to-position-the-input-text-cursor-in-c
void clear() { 
  fprintf(stderr, "\033[H\033[J"); 
}
void gotoxy(int x,int y) {
  fprintf(stderr, "\033[%d;%dH", (x), (y));
  // printf == fprintf(stdout,)
}

// http://stackoverflow.com/questions/1022957/getting-terminal-width-in-c
int rows = 0;
int cols = 0;

void snowflake() {
  // Init a random number generator
  srand((unsigned)time(NULL));

  // Pick a random column
  int col = rand() % cols;

  // Start at row 0
  int row = 0;

  // Loop as the snowflake falls one row at a time...
  while (row < rows) {
    // Write the snowflake
    gotoxy(row, col);
    fprintf(stderr, "*");

    // Sleep for a while (pause the falling)
    usleep(200000);

    // Clear the snowflake
    gotoxy(row, col);
    fprintf(stderr, " ");

    // Get ready to draw the next row
    row++;
  }
}

int main() {
  // Get the terminal window size:
  // http://stackoverflow.com/questions/1022957/getting-terminal-width-in-c
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  rows = w.ws_row;
  cols = w.ws_col;

  // Clear the screen
  clear();


  snowflake();
}
