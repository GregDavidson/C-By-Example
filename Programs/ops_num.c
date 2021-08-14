#include <stdio.h>

int main(void) {
  int int1, int2, int3;
  int * int_ptr;

  int1 = 2 + 3 - 15;
  int2 = -int1;
  printf("int1 = %d, int2 = %d\n", int1, int2);

  int1 = 2 + (3*5);
  int2 = 2 + 3 * 5;
  int3 = (2+3) * 5;
  printf("int1 = %d, int2 = %d, int3 = %d\n", int1, int2, int3);

  int1 = int2 = int3 = 0;	/* associates right to left */
  printf("int1 = %d, int2 = %d, int3 = %d\n", int1, int2, int3);

  int1 = 123;
  int2 = int1 / 10;
  int3 = int1 % 10;
  printf("int1 = %d, int2 = %d, int3 = %d\n", int1, int2, int3);

  int_ptr = &int1;
  printf("The int pointed to by int_ptr is %d\n", *int_ptr);
  *int_ptr = 0;
  printf("int1 = %d\n", int1);

  return 0;
}
