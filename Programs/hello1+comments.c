// double slash Comments extend to end of Line
// capitaltion in Comments indicate specific technical meaning
#include <stdio.h>
// each # directive must be its own line
// #include textually includes contents of C Code File
// <stdio.h> means <System> File named stdio.h containing
// Declarations of Standard Input-Output Functions such as puts
// C Procedures called Functions, whether Value Returning or not

int main(void)
// Head of Function which:
// Declares function named main
// which when Called takes NO value, i.e. void
// returns a value of type int (one word Integer)
{
// open curly brace begins a block
// i.e. a sequence of statements to perform sequentially
  puts("Hello world!");
// calls library function puts with literal string argument
// semi-colon completes the Statement
  return 0;
// Returns int 0 to Function which Called this Function
// semi-colon completes the Statement
}
// Common C Style puts close curly brace on line by itself,
// indented the same as line with matching open brace
