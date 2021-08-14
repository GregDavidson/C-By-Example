#include <stdio.h>

#define STR_SIZE 30

typedef char *Strptr;
typedef char Strbuf[STR_SIZE];
typedef char String[];

Strptr President1 = "George";
Strbuf President2 = "Thomas";
String President3 = "John";

void greet(String, int);

int main(void) {
  greet(President1, sizeof President1);
  greet(President2, sizeof President2);
  greet(President3, sizeof President3);

  return 0;
}

void greet(String name, int len) {
  printf("Hello %s, your variable occupies %d bytes\n", name, len);
}
