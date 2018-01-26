#include <unistd.h> /* fork, getpid, getppid */
#include <stdio.h>  /* printf */

int main(void)
{
	int p;

	printf("O: Originalt program har pid = %d\n", getpid());
	p=fork();
	if (p==0) {
		printf("C: I childprosessen er pid = %d og har parent prosessen med pid = %d\n", getpid(), getppid());
	} else {
		printf("O: I parentprosessen er pid = %d, fork returnerte = %d\n", getpid(), p);
		printf("O: Parent til original parent har pid = %d\n", getppid());
	}
	printf("Prosessen %d avslutter\n", getpid());
	return 0;
}

