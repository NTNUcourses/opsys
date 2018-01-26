#include <unistd.h>   /* fork,sleep */
#include <stdio.h>    /* printf */
#include <sys/wait.h> /* wait */

int main(void) {
	int p;

	p = fork();
	if (p == 0) { /* sjekk om vi er i child eller parent */
		printf("...er i child og skal sove 4 sekunder!\n");
		usleep(4000000);
	} else {
		printf("...har skapt child og venter på at den skal avslutte!\n");
		while(wait(NULL)>0) { /*no-op*/ ; }
		printf("...og der var den ferdig, gitt.\n\n");
	}

	return 0;
}

