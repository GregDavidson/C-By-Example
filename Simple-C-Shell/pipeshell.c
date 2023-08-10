/* Small shell with pipes, illustrating fork(), exec(),
   wait(), pipe(), dup2(), close()
   Skeleton
*/

#include <stdio.h>
#include <string.h>


/* This function prints a prompt, reads in a command
   line,  and  parses it,  placing  pointers  to the
   individual  tokens prior to a "|"  token into the
   upstream  array  (u),  and tokens following a "|"
   token (if any)  into  the  downstream  array (d).
   Both arrays are terminated by a NULL pointer
*/
int prompt_and_parse(char **u, char **d) {
    static char line[100];

    d[0] = NULL;
    printf("> ");
    if (gets(line) == NULL)
        return -1;
    *u++ = strtok(line, " \t");
    while (*u = strtok(NULL, " \t")) {
        if (strcmp(*u, "|") == 0) {
	    *u = NULL;
	    while (*d++ = strtok(NULL, " \t"))
	        /* Empty body */ ;
	    return 1;
	}
	u++;
    }
    return 1;
}

int main(void) {
    int p[2];
    char *upstream[20], *downstream[20];

    while (prompt_and_parse(upstream, downstream) > 0)
      if ( fork() )		/* parent waits */
	wait(0);
      else
	if (downstream[0])	/* There's a pipe */ {
	  pipe(p);
	  if ( fork() ) {	/* first child handles downstream part */
	    dup2(p[0], 0);
	    close(p[0]);    close(p[1]);
	    execvp(downstream[0], downstream);
	    printf("%s: not found\n", downstream[0]);
	    exit(2);
	  } else {		/* grandchild (will be zombie briefly)  */
	    dup2(p[1], 1);
	    close(p[0]);    close(p[1]);
	  }
	}
    execvp(upstream[0], upstream);
    printf("%s: not found\n", upstream[0]);
    exit(1);
}
