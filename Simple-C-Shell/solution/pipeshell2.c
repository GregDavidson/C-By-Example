/* Small shell, illustrating fork(), exec(), wait() 
   J. Greg Davidson, 1999
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *GetCommand(const char *prompt); /* as a line */
char **ParseCommand(char *line); /* into an argument vector */
void SimpleCommand(char *cmnd);	/* Runs commands with no pipes */
void FancyCommand(char *cmnd);	/* Runs commands with 0 or more pipes */
int main(void) {
  char *line;

  while ( line = GetCommand("> ") ) {
    int do_wait, pid;
    char *end = line + strlen(line) - 1;
    if  (do_wait=(*end != '&')) 
      *end = '\0';
    if ( pid = fork() )
      if (do_wait)
	wait(0);
      else
	printf("Child's pid is %d, just in case you want to kill it.", pid);
    else
      FancyCommand(line);
  }
  return 0;
}

void SimpleCommand(char *cmnd) {
  char **args = ParseCommand(cmnd);
  execvp(args[0], args);
  printf("Command %s not found!\n", args[0]);
  exit(1);
}
void FancyCommand(char *cmnd) {
  char *tail, **args;
  while ( tail = strrchr(cmnd, '|') ) { /* last '|' in command or NULL */
    int pipe_ends[2];
    pipe(pipe_ends);
    *tail++ = '\0';	/* Split command into head and tail */
    if ( fork() ) {	/* Parent handles last part of command (the tail) */
      dup2(pipe_ends[0], 0);/* parent's stdin to pipe's output */
      close(pipe_ends[1]);      close(pipe_ends[0]); /* Close original ends of pipe. */
      break;	/* parent does last part
    } else {		/* Child handles all but last part
      dup2(pipe_ends[1], 1);/* child's stdout to pipe's input */
      close(pipe_ends[0]);      close(pipe_ends[1]);/* Close original descriptors */
    }
  }
  SimpleCommand(cmnd);	/* no pipe in command */
}

/* The length of an array is it's size divided by it's element size */
#define RA_LEN(array) ( sizeof(array) / sizeof *(array) )
/* The end of an array is it's base pointer plus it's length */
#define RA_END(array) ( (array) + RA_LEN(array) )

/* Read a command line */
char *GetCommand(const char *prompt) {
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
char **ParseCommand(char *line) {
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
  
