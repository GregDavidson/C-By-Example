#include <stdio.h>

int main(void) {
  printf("Do you wish instructions? ");

  if ( getchar() == 'y' )
     printf("Sorry, none are available.\n");

  return 0;
}

