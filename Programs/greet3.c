#include <stdio.h>

#define STR_SIZE 30

typedef char Strbuf[STR_SIZE];

Strbuf President1 = { 'G', 'e', 'o', 'r', 'g', 'e' };
Strbuf Lady1 = "Martha";

void greet(Strbuf);

int main(void) {
  greet(President1);
  greet(Lady1);

  return 0;
}

void greet(Strbuf name) {
  printf("Hello %s, how are you?\n", name);
}
