// double slash Comments extend to the end of the Line
// capitalized words in Comments usually have specific technical meanings
#include <stdio.h>
// # directives have to be on their own line
// #include textually includes the contents of a File of C Code
// <stdio.h> means the <System> File named stdio.h containing
// Declarations of Standard Input-Output Functions such as puts
// C Procedures are called Functions, whether Returning a Value or not

int main(void)
// Declares a function named main which when Called
// takes NO parameters, i.e. void
// returns a value of type int (one word Integer)
{
// an open curly brace begins a block
// i.e. a sequence of statements to be performed one by one in order
  puts("Hello world!");
// calls the library function puts with a literal string as an argument
// the semi-colon ends the Statement
  return 0;
// Returns int 0 to the Function which Called this Function
}
// Common C Style puts a close curly brace on a line by itself,
// indented the same as the line with the matching open brace
