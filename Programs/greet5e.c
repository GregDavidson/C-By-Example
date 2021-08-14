#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array)[0])
#define ARRAY_END(array) (array + ARRAY_SIZE(array))
#define ARRAY_LOOP(pointer, array) \
  for ( (pointer) = (array) ; (pointer) < ARRAY_END(array) ; (pointer)++ )

typedef char *Strptr;

Strptr presidents[] = { "George", "Thomas", "John" };

void greet(Strptr,  int);

int main(void) {
  Strptr *ptr;

  ARRAY_LOOP(ptr, presidents)
    greet(*ptr, strlen(*ptr));

  return 0;
}

void greet(Strptr name, int len) {
  printf("Hello %s, your name is %d bytes long\n", name, len);
}
