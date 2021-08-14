#include <stdio.h>
#include <string.h>

typedef char *Strptr;

/* A 0 (the false int) will convert to NULL (the false pointer) */
Strptr presidents[] = { "George", "Thomas", "John", 0 };

void greet(Strptr, int);

int main() {
  Strptr *ptr;
  
  for (ptr = presidents; *ptr; ptr++)
    greet(*ptr, strlen(*ptr));

  return 0;
}

void greet(Strptr name, int len) {
  printf("Hello %s, your name is %d bytes long.\n", name, len);
}
