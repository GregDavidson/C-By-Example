#include <stdio.h>
#include <ctype.h>

enum { Normal_Exit, Bad_Args_Exit, No_Help_Exit, EOF_Exit };

#define WHEN 	break; case
#define OR	: case

int GetChar(void) {	// get one printable character or EOF
  int c;

  while ( (c = getchar()) != EOF && !isgraph(c) )
    ;

  return c;
}

int main(int argc, char **argv) {
  if ( argc != 1 ) {
	fprintf(stderr, "%s: No arguments required!\n", argv[0]);
	return Bad_Args_Exit;
  }
  for ( ; ; ) {	// infinite loop
	printf("Do you wish instructions? ");
	switch ( GetChar() ) {
	  WHEN 'y' OR 'Y':
		fprintf(stderr, "%s: No instructions are available!\n", argv[0]);
	  return No_Help_Exit;
	  WHEN 'n' OR 'N':
		printf("Well, its a good thing, because none are available.\n");
	  return Normal_Exit;
	  WHEN 'i' OR 'I':
		printf("Silly example C program %s\n", argv[0]);
	  WHEN 'q' OR 'Q':
		return Normal_Exit;
	  WHEN EOF:
		return EOF_Exit;
	default:
	  printf("Type Y for Yes, N for No, I for Info, Q for Quit\n");
	}
  }
}
