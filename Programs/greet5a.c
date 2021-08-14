#include <stdio.h>
#include <string.h>

typedef char *Strptr;

Strptr presidents[] = { "George", "Thomas", "John" };

void greet(Strptr,  int);

int main(void) {
  int i = 0;
  int npres = sizeof presidents / sizeof presidents[0];

  while ( i < npres ) {
	greet(presidents[i], strlen(presidents[i]));
	i = i + 1;
  }

  return 0;
}

void greet(Strptr name, int len) {
  printf("Hello %s, your name is %d bytes long\n", name, len);
}
