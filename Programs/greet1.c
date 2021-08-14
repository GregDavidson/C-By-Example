#include <stdio.h>

void greet(char *);

int main() {
  greet("George");
  greet("Martha");

  return 0;
}

void greet(char *name) {
  printf("Hello %s, how are you?\n", name);
}
