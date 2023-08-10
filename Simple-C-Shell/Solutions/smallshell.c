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
  int pid1, pid2, status;
  
  /* Main command loop */
  while ( args = GetCommand("> ") )
    if ( pid1 = fork() ) {
      printf("Parent waiting for child with pid %d.\n", pid1);
      pid2 = wait( &status );
      if ( WIFEXITED(status) )
	printf("Child %d exited with status %d.\n", pid2, WEXITSTATUS(status));
      else if ( WIFSIGNALED(status) )
	printf("Child %d killed by signal %d.\n", pid2, WTERMSIG(status));
      else if ( WIFSTOPPED(status) )
	printf("Child %d stopped by signal %d.\n", pid2, WTERMSIG(status));
      else
	printf("Child terminated with mysterious status %d.\n", status);
    }
    else
      execvp(args[0], args);
}
  
/* The length of an array is it's size divided by it's element size */
#define RA_LEN(array) ( sizeof(array) / sizeof *(array) )
/* The end of an array is it's base pointer plus it's length */
#define RA_END(array) ( (array) + RA_LEN(array) )

/* Read a command line and return it as a NULL terminated argument vector */
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
