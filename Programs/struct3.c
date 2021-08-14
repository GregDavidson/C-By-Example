#include <stdio.h>

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array)[0])
#define ARRAY_END(array) (array + ARRAY_SIZE(array))
#define ARRAY_LOOP(pointer, array) \
  for ( (pointer) = (array) ; (pointer) < ARRAY_END(array) ; (pointer)++ )

typedef char String[];

struct employee {
  int number;
  char name[20];
  int age;
  char ssn[12];
};

int main(void) {
  struct employee first_shift[] = {
    { 2903, "New_guy", 18, "111-22-3333" },
    {    3, "Most Experienced", 55, "444-55-6666" },
    {    1, "Founder", 40, "123-45-6789" }
  };
  String president = "J. Q. Mooney";
  struct employee *eptr;

  ARRAY_LOOP(eptr, first_shift)
	printf(
	  "Employee number: %4d Name: %-20s Age: %2d SSN: %12s\n",
	  eptr->number, eptr->name, eptr->age, eptr->ssn
	);
  printf("\nAnd the president is %s\n", president);
  return 0;
}
