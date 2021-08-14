#include <stdio.h>

typedef char *Strptr;

Strptr President1 = "George";

void greet(Strptr);

int main(void) {
  greet(President1);
  greet("Martha");

  return 0;
}

void greet(Strptr name) {
  printf("Hello %s, how are you?\n", name);
}
