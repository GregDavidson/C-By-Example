#include <stdio.h>

void PutDigit( int d ) {	/* Print decimal digit d as a character */
  putchar( d + '0' );
}

void PutPosInt( int i ) {	/* Print all digits in positive i */
  if (i > 0) {
      PutPosInt( i/10 );	/* Delegate all but last digit */
      PutDigit( i%10 );		/* Print last digit */
    }
}

void PutInt( int i ) {
  if (i == 0)
    putchar('0');
  else if (i > 0)
    PutPosInt(i);
  else {
	putchar('-');
	PutPosInt(-i);
  }
}

int main(void) {
  PutInt(123);
  putchar('\n');
  PutInt(-456);
  putchar('\n');
  PutInt(0);
  putchar('\n');

  return 0;
}
