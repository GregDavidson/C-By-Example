#include <stdio.h>

enum { Normal_Exit, No_Help_Exit, Bad_Input_Exit };
  
int main(void) {
  int c;

  printf("Do you wish instructions? ");
  c = getchar();

  if (c == 'y') {
	fprintf(stderr, "No instructions are available!\n");
	return No_Help_Exit;
  }

  if (c == 'n') {
	printf("Well, its a good thing, because none are available.\n");
	return Normal_Exit;
  }

  fprintf(stderr, "Type y for Yes or n for No\n");
  return Bad_Input_Exit;
}
