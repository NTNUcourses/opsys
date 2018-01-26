#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void sig_handler(int signo) {
	if (signo == SIGTERM) {
		printf("Recieved SIGTERM.\n");
	}
	if (signo == SIGINT) {
		printf("Recieved SIGINT.\n");
	}
}

int main(void) {
	if (signal(SIGTERM, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGTERM\n");
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGINT\n");


	while(1) { 
		printf("Program running\n");
		sleep(1);
    }
    
	return 0;
}
