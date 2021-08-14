#include <stdio.h>

#define ARRAY_SIZE(array) (sizeof (array) / sizeof (array)[0])
#define ARRAY_END(array) (array + ARRAY_SIZE(array))
#define ARRAY_LOOP(pointer, array) \
  for ( (pointer) = (array) ; (pointer) < ARRAY_END(array) ; (pointer)++ )

typedef
  struct employee {
    int number;
    char name[20];
    int age;
    char ssn[12];
  }
*Employee;

struct employee personnel[] = {
  { 2903, "New_guy", 18, "111-22-3333" },
  {    3, "Most Experienced", 55, "444-55-6666" }
};

struct employee president = { 1, "Jill Stiles", 40, "1123-45-6789" };

void ShowEmployee( Employee e ) {
  printf(
	"Employee number: %4d Name: %-20s Age: %2d SSN: %12s\n",
	e->number, e->name, e->age, e->ssn
  );
}

int main(void) {
  Employee e;

  ARRAY_LOOP(e, personnel)
    ShowEmployee(e);
  puts("\nAnd the president of the company is:");
  ShowEmployee(&president);
  
  return 0;
}
