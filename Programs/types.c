#include <stdio.h>
#include <math.h>	// math library functions
#include <limits.h>	// implementation dependent integer limits
#include <float.h>	// implementation dependent floating point limits

int main(void) {
  char c = 'X';				// 7 bits, 1 byte, unsigned
  signed char sc = -1;			// 8 bits, 1 byte, signed
  unsigned char uc = 0xffU;		// 8 bits, 1 byte, unsigned
  short s = 123;			// at least 16 bits, signed
  unsigned short us = 0xffffU;		// at least 16 bits, unsigned
  int i = 123;				// at least 16 bits, 1 word, signed
  unsigned int ui = 0xffffU;		// at least 16 bits, 1 word, unsigned
  long l = 123456789;			// at least 32 bits, signed
  unsigned long ul=0xffffffffU;		// at least 32 bits, unsigned
  float f = 2 * acos(0);		// implementation single precision
  double d = f * f;			// implementation double precision
  long double ld = d * d;		// implementation extended precision
   
  printf("%s at %p has size %d and value %c\n", "c", &c, sizeof c, c);
  printf("%s at %p has size %d and value %d\n", "s", &s, sizeof s, s);
  printf("%s at %p has size %d and value %d\n", "i", &i, sizeof i, i);
  printf("%s at %p has size %d and value %ld\n","l", &l, sizeof l, l);
  printf("%s at %p has size %d and value %f\n", "f", &f, sizeof f, f);
  printf("%s at %p has size %d and value %f\n", "d", &d, sizeof d, d);
  printf("%s at %p has size %d and value %Lf\n", "ld", &ld, sizeof ld, ld);

  return 0;
}
