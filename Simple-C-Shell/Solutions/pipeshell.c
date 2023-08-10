/* Small shell, illustrating fork(), exec(), wait(), signals
   J. Greg Davidson, 1999
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *GetCommand(const char *prompt); /* as a line */
char **ParseCommand(char *line);      /* into an argument vector */
void SimpleCommand(char *cmnd);	      /* Runs commands with no pipes */
void FancyCommand(char *cmnd);	      /* Runs commands with 0 or more pipes */

#include <setjmp.h>

jmp_buf restart;

void Restart(int dontcare)  {  putchar('\a'); longjmp(restart, 1); }

int main(void) {
  char *line;

  setjmp(restart);
  signal(SIGINT, Restart);
  while ( line = GetCommand("> ") ) {
    int pid;
    char *dont_wait  = strrchr(line, '&');
    if (dont_wait) 
      *dont_wait = '\0';		/* clobber the '&' */
    if ( pid = fork() )
      if (dont_wait)
	printf("Child's pid is %d, just in case you want to kill it.\n", pid);
      else
	wait(0);
    else {
      if (dont_wait)
	nice(10);			/* run at a lower average priority, since we're a background task */
      FancyCommand(line);
    }
    
  }
}

void SimpleCommand(char *cmnd) 
{
  char **args = ParseCommand(cmnd);
  execvp(args[0], args);
  printf("Command %s not found!\n", args[0]);
  exit(1);
}
  
void FancyCommand(char *cmnd)
{
  char *tail, **args;

  if ( tail = strrchr(cmnd, '|') ) { /* last '|' in command or NULL */
    /* STEP 1: Declare descriptor array */
    int pipe_ends[2];
    /* STEP 2: Create the pipe */
    pipe(pipe_ends);
    *tail++ = '\0';		/* Split command into head and tail */
    if ( fork() ) {
      /* Parent will handle last part of command (the tail) */
      dup2(pipe_ends[0], 0);      /* Connect parent's standard input to the pipe */
      close(pipe_ends[1]);      close(pipe_ends[0]); /* Close original ends of pipe. */
      SimpleCommand(tail);	/* parent does last part of command */
    } else {
      /* Child will handle all but the last part of command (the tail) */
      dup2(pipe_ends[1], 1);/* attach child's output to pipe's input */
      close(pipe_ends[0]);      close(pipe_ends[1]);/* Close original descriptors */
      FancyCommand(cmnd);	/* child looks for more pipes */
    }
  }
  else
    SimpleCommand(cmnd);	/* no pipe in command */
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
  
