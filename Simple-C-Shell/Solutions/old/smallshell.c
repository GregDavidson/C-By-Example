/* Small shell, illustrating fork(), exec(), wait() 
   Solution -- Chris Brown 15 Oct 1997
*/

#include <stdio.h>
#include <string.h>


/* This function prints a prompt, reads in a command
   line,  and  parses it,  placing  pointers  to the
   individual  tokens in the args  array,  which  is
   terminated by a NULL pointer
*/
int prompt_and_parse(char **args)
{
    static char line[100];
    printf("> ");
    if (gets(line) == NULL)
        return -1;
    *args++ = strtok(line, " \t");
    while (*args++ = strtok(NULL, " \t"))
        /* Empty body */ ;
    return 1;
}

main()
{
    char *args[20];

    /* Main command loop */
    while (prompt_and_parse(args) > 0) {
        if (fork() == 0) { /* Child */
	    execvp(args[0], args);
	    printf("%s: not found\n", args[0]);
	    exit(1);
	}
	else { /* Parent */
	    wait(0);
	}
    }
}

