#include <stdio.h>
#include <math.h>	/* math library functions */
#include <limits.h>	/* implementation dependent integer limits */
#include <float.h>	/* implementation dependent floating point limits */

#define SHOW(VAR, FORMAT) \
  printf(	\
	"%2s at address %p has size %lu and value %" #FORMAT "\n",	\
	#VAR, (void *) &VAR, (unsigned long) sizeof VAR, VAR		\
  )

int main(void) {
  char c = 'X';				/* 7 bits, 1 byte, unsigned */
  signed char sc = -1;			/* 8 bits, 1 byte, signed   */
  unsigned char uc = 255;		/* 8 bits, 1 byte, unsigned */
  short s = 123;			/* at least 16 bits, signed   */
  unsigned short us = 0xffffU;		/* at least 16 bits, unsigned */
  int i = 123;				/* at least 16 bits, 1 word, signed   */
  unsigned int ui = 0xffffU;		/* at least 16 bits, 1 word, unsigned */
  long l = 123456789;			/* at least 32 bits, signed   */
  unsigned long ul=0xffffffffU;		/* at least 32 bits, unsigned */
  long long ll = 123456789123456789;		/* at least 64 bits, signed   */
  unsigned long long ull=0xffffffffffffffffU;	/* at least 64 bits, unsigned */
  float f = 2 * acos(0);		/* implementation single precision */
  double d = f * f;			/* implementation double precision */
  long double ld = d * d;		/* implementation extended precision */
   
  putchar('\n');	SHOW(c, c);		SHOW(sc, d);	SHOW(uc, u);
  putchar('\n');	SHOW(s, d);		SHOW(s, x);
  putchar('\n');	SHOW(i, d);		SHOW(ui, x);
  putchar('\n');	SHOW(l, ld);		SHOW(ul, lx);
  putchar('\n');	SHOW(ll, Ld);		SHOW(ull, Lx);
  putchar('\n');	SHOW(f, f);		SHOW(d, f);	SHOW(ld, Lf);

  return 0;
}
