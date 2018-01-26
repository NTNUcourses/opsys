#include <unistd.h>   /* fork */
#include <stdio.h>    /* printf */
#include <stdlib.h>   /* exit */
#include <sys/wait.h> /* wait */

int main(void) {
	int p;

	p=fork();
	if (p==0){
		fork();
		printf("HelloC!\n");
		exit(0);
	} else{
		while(wait(NULL) > 0) { /* no-op */ ; }
		printf("HelloP!\n");
	}

	return 0;
}

