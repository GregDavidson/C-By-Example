#include <stdio.h>
#include <stdlib.h>

static char *getline( int count ) {
  int c = getchar();
  char *s;

  ++count;
  if ( c == '\n' || c == EOF ) {
	s = malloc(count) + count;
	*--s = '\0';
  } else {
	s = getline( count );
	*--s = c;
  }
  return s;
}


char *GetLine(void) {
  return getline( 0 );
}

int main(void) {
  char *name;

  printf("What's your name? ");
  name = GetLine();
  printf("Pleased to meet you %s; goodbye!\n", name);
  free(name);

  return 0;
}
