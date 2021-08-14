#include <stdio.h>	/* redundant */
#include "array2.h"	/* redundant */
#include "employee2.h"

struct employee personnel[] = {
  { 2903, "New_guy", 18, "111-22-3333" },
  {    3, "Most Experienced", 55, "444-55-6666" }
};

struct employee president = { 1, "Jill Stiles", 40, "1123-45-6789" };

int main(void) {
  Employee e;

  ARRAY_LOOP(e, personnel)
    ShowEmployee(e);
  puts("\nAnd the president of the company is:");
  ShowEmployee(&president);

  return 0;
}
