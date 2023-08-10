/* Small shell, illustrating fork(), exec(), wait() 
   J. Greg Davidson, 1999
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *GetCommand(const char *prompt); /* as a line */
char **ParseCommand(char *line); /* into an argument vector */
void SimpleCommand(char *cmnd);	/* no pipes allowed */
void DoCommand(char *cmnd);	/* zero or more pipes */

main()
{
  char *line;

  while ( line = GetCommand("> ") ) {
    if ( fork() )
      wait(0);
    else
      DoCommand(line);
  }
}

/* The length of an array is it's size divided by it's element size */
#define RA_LEN(array) ( sizeof(array) / sizeof *(array) )
/* The end of an array is it's base pointer plus it's length */
#define RA_END(array) ( (array) + RA_LEN(array) )

/* Read a command line */
char *GetCommand(const char *prompt)
{
  static char line[100];

  if ( isatty(0) ) /* Is stdin (file descriptor 0) an interactive tty? */
      fputs(prompt, stdout);
  if ( fgets(line, sizeof line, stdin) == NULL ) /* EOF */
    return 0;
  if ( line[strlen(line)-1] != '\n' ) /* fgets stores the '\n' */ {
    fputs("Line buffer size exceeded.\n", stderr);
    return 0;
  }
  return line;
}

/* Read a command line and return it as a NULL terminated argument vector */
char **ParseCommand(char *line)
{
  static char *arg_vec[20];
  char **next_arg = arg_vec, **const end_args = RA_END(arg_vec);

  while (next_arg < end_args && (*next_arg++ = strtok(line, " \t\n")))
    line = 0;  /* tricky: strtok will resume it left off last call */
  if ( next_arg[-1] ) /* strtok didn't finish */ {
      fputs("Argument buffer size exceeded.\n", stderr);
      return 0;
    }
  return arg_vec;
}

void DoCommand(char *cmnd)
{
  char *tail, **args;

  if ( tail = strrchr(cmnd, '|') ) { /* last '|' in command or NULL */
    int pipe_fds[2];
    pipe(pipe_fds);		/* Create the pipe */
    *tail++ = '\0';		/* Split command into head and tail */
    if ( fork() ) {
      close(pipe_fds[1]);
      dup2(pipe_fds[0], 0);
      SimpleCommand(tail);	/* parent does last part of command */
    } else {
      close(pipe_fds[0]);
      dup2(pipe_fds[1], 1);
      DoCommand(cmnd);		/* child looks for more pipes */
    }
  }
  else
    SimpleCommand(cmnd);
}

void SimpleCommand(char *cmnd) 
{
  char **args = ParseCommand(cmnd);
  execvp(args[0], args);
  printf("Command %s not found!\n", args[0]);
  exit(1);
}
  
  
