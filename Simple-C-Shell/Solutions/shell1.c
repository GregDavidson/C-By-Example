/* Small shell, illustrating fork(), exec(), wait() 
   J. Greg Davidson, 1999
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Read a command line and return it as a NULL terminated  argument vector */
char **GetCommand(const char *prompt);

int main(void) {
  char **args;

  /* Main command loop */
  while ( args = GetCommand("> ") )
    if ( fork() )
      wait(0);
    else {
      execvp(args[0], args);
      printf("Command %s not found!\n", args[0]);
      exit(1);
    }
}
  
  
/* The length of an array is it's size divided by it's element size */
#define RA_LEN(array) ( sizeof(array) / sizeof *(array) )
/* The end of an array is it's base pointer plus it's length */
#define RA_END(array) ( (array) + RA_LEN(array) )

char **GetCommand(const char *prompt) {
  static char *arg_vec[20];
  char **next_arg = arg_vec, **const end_args = RA_END(arg_vec);
  static char line[100];
  char *p = line;

  if ( isatty(0) ) /* Is stdin (file descriptor 0) an interactive tty? */
      fputs(prompt, stdout);
  if ( fgets(line, sizeof line, stdin) == NULL ) /* EOF */
    return 0;
  if ( line[strlen(line)-1] != '\n' ) /* fgets stores the '\n' */ {
    fputs("Line buffer size exceeded.\n", stderr);
    return 0;
  }
  while (next_arg < end_args && (*next_arg++ = strtok(p, " \t\n")))
    p = 0;  /* tricky: strtok will resume it left off last call */
  if ( next_arg[-1] ) /* strtok didn't finish */ {
      fputs("Argument buffer size exceeded.\n", stderr);
      return 0;
    }
  return arg_vec;
}
