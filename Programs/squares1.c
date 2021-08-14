#include <stdio.h>

int square(int i) {
  return i * i;
}

int sum_of_squares(int x, int y) {
  return x * x + y * y;
}

int main(void) {
  printf( "The square of %d is %d\n", 4, square(4) );

  printf(
	"The sum of the squares of %d and %d is %d\n",
	3, 4, sum_of_squares(3, 4)
  );

  return 0;
}
