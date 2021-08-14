#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array)[0])

// Adding integer to pointer advances it by that many elements
#define ARRAY_END(array) (array + ARRAY_SIZE(array))

typedef char *Strptr;

Strptr presidents[] = { "George", "Thomas", "John" };

void greet(Strptr,  int);

int main(void) {
  Strptr *ptr;

  for (ptr = presidents ; ptr < ARRAY_END(presidents) ; ptr++)
    greet( *ptr, strlen(*ptr) );

  return 0;
}

void greet(Strptr name, int len) {
  printf("Hello %s, your name is %d bytes long\n", name, len);
}
