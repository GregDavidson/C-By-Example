/* Slash Star Comments can continue past the line
   until a Star Slash.
   Comments cannot be nested!
   A comment is equivalent to whitespace.

   Whitespace refers to any non-empty sequence of spaces,
   tabs or newlines. Whitespace is used to separate adjacent
   keywords and identifiers.

   At least one whitespace character is required where
   necessary to keep keywords or identifiers separate.
   Any additional use of whitespace is optional and
   should be used to improve human readability.

   The formatting in this example has each Token
   of the program on its own line.  This is not normal
   style!

   Tokens cannot be further separated, except for
   adjacent "string" "literals" which will be implicitly
   concatenated into one "string literal"!
*/
#include <stdio.h>
// replaced with contents of <system> file stdio.h

int
// type to be returned by Function
main
// name of Function
(
// begins list of required parameters
void
// indicates NONE
//   empty parentheses would indicated UNSPECIFIED
//   for historical reasons and is now bad style!
)
// ends list of required parameters
{
// begins Function Body Block
// i.e. what this Function when it is Called
puts
// name of library function
(
// begins function call operator, i.e. ()
"Hello "
"world!"
// same as "Hello world!" (adjacent concatenation)
)
// completes function call operator
;
// ; completes Expression which completes Statement
return
// ends Execution of current Function
0
// value to hand back to Calling Function
;
// ; completes Expression which completes Statement
}
// completes Body Block which completes Function
