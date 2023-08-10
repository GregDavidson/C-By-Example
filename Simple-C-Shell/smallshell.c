/* Small shell, illustrating fork(), exec(), wait() 
   Skeleton
*/

#include <stdio.h>
#include <string.h>

/* This function prints a prompt, reads in a command
   line,  and  parses it,  placing  pointers  to the
   individual  tokens in the args  array,  which  is
   terminated by a NULL pointer
*/
int BackgroundTheCommand;

int prompt_and_parse(char **args) {
    static char line[100];
    printf("> ");
    if (gets(line) == NULL)
        return -1;
    if ( BackgroundTheCommand = ( line[strlen(line)-1] == '&' ) )
      line[strlen(line)-1] = '\0';
    *args++ = strtok(line, " \t");
    while (*args++ = strtok(NULL, " \t"))
      /* Empty body */ ;
    return 1;
}

int main(void) {
    char *args[20];

    /* Main command loop */
    while (prompt_and_parse(args) > 0)
      if ( pid = fork() )
	if ( !BackgroundTheCommand )
	  printf("%d\n", pid);
	else
	  wait(0);
      else {
        execvp(args[0], args);
        fprintf(stderr, "Can't execute program %s!\n", args[0]);
    }
}
