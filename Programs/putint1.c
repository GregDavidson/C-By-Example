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

int main(void) {
  PutPosInt(1);
  putchar('\n');
  PutPosInt(12);
  putchar('\n');
  PutPosInt(1985);
  putchar('\n');

  return 0;
}
