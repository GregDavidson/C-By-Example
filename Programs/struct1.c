#include <stdio.h>

struct employee {
  int number;
  char name[20];
  int age;
  char ssn[12];
};

int main(void) {
  struct employee new_guy = { 2903, "New_guy", 18, "111-22-3333" };

  printf(
	"Employee number: %4d Name: %-20s Age: %2d SSN: %12s\n",
	new_guy.number, new_guy.name, new_guy.age, new_guy.ssn
  );

  return 0;
}

  
