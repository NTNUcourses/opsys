#include <unistd.h>   /* fork, exec */
#include <stdio.h>    /* printf */
#include <sys/wait.h> /* wait */

int main(int argc, char *argv[]) {
	int p;

	p=fork();
	if (p==0) { 			/* sjekk om vi er i child */
		printf("\n\n... er i child og starter gedit\n\n");
		execv("/usr/bin/gedit", argv); 	/* child */
		printf("\n\n... HEISANN!");
	}
	
	printf("\n\n... Parent: Child skal starte gedit og venter paa at den skal avslutte!\n\n"); 
	while(wait(NULL)>0) { /*no-op*/ ; }
	printf("\n\n...Parent:..og der var den ferdig, gitt.\n");

	return 0;
}
