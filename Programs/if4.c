#include <stdio.h>

#define NORMAL_EXIT 0
#define E_NO_INSTRUCTIONS 1
#define E_BAD_INPUT 2

int main(void) {
  int c;

  printf("Do you wish instructions? ");
  c = getchar();

  if (c == 'y') {
	fprintf(stderr, "No instructions are available!\n");
	return E_NO_INSTRUCTIONS;
  }

  if (c == 'n') {
	printf("Well, its a good thing, because none are available.\n");
	return NORMAL_EXIT;
  }

  fprintf(stderr, "Type y for Yes or n for No\n");
  return E_BAD_INPUT;
}
