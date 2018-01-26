#include <stdio.h>     /* printf */
#include <stdlib.h>    /* exit */
#include <unistd.h>    /* fork */
#include <sys/wait.h>  /* waitpid */
#include <sys/types.h> /* pid_t */

int ant = 0;           /* global declaration */

void writeloop(char *text) {
 long i = 0;
 while (ant < 10) {
  if (++i % 100000 == 0)
   printf("%s: %d\n", text, ++ant);
 }
}

int main(void)
{
 pid_t pid;

 pid = fork();
 if (pid == 0) {        /* child */
  writeloop("Child");
  exit(0);
 }
 writeloop("Parent");   /* parent */
 waitpid(pid, NULL, 0);
 return 0;
}
