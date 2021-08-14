#include <stdio.h>

int main(void) {
  int c;

  printf("Do you wish instructions? ");
  c = getchar();

  if ( c == 'y' )
      printf("Sorry, none are available!\n");
  else {
      printf("Well, its a good thing, ");
      printf("because none are available.\n");
  }

  return 0;
}

