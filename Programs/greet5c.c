#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array)[0])

typedef char *Strptr;

Strptr presidents[] = { "George", "Thomas", "John" };

void greet(Strptr,  int);

int main(void) {
  int i;
  int npres = ARRAY_SIZE(presidents);

  for (i = 0; i < npres; i++)
    greet(presidents[i], strlen(presidents[i]));

  return 0;
}

void greet(Strptr name, int len) {
  printf("Hello %s, your name is %d bytes long\n", name, len);
}
