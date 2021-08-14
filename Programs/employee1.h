#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include "array1.h"

typedef
  struct employee {
    int number;
    char name[20];
    int age;
    char ssn[12];
  }
*Employee;

void ShowEmployee( Employee );

#endif
