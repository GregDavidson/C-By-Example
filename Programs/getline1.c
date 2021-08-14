#include <stdio.h>
#include <stdlib.h>

typedef char *String;	// Pointer to '\0' terminated string.

/* Read the remainder of a line of text into a C string,
 * preceeded by reserve bytes of extra space.  Return a
 * pointer to the first byte of the string.
 */
static String RestOfLine( int reserve ) {
  int i = getchar();
  int c = ( i == '\n' || i == EOF ) ? '\0' : i;
  int n = reserve+1;
  char *cp = c ? RestOfLine( n )
	       : malloc( n ) + n;
  String s = cp-1;
  *s = c;
  return s;
}

/* Read in a line of text and return it as a
 * dynamically allocated C string array.
 */
String GetLine(void) {
  return RestOfLine(0);
}
