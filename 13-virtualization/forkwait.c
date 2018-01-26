#include <unistd.h>  
#include <sys/wait.h> 

#include<unistd.h>

int main(void) {
  int i,pid;
  for (i=0; i<25000; i++) {
    pid = fork();
    if (pid < 0) return -1;
    if (pid == 0) return 0;
    waitpid(pid,NULL,0);
  }
  return(0);
}

