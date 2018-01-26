#include <stdio.h> /* printf */
#include <stdlib.h> /* exit */
#include <unistd.h> /* fork */
#include <sys/wait.h> /* waitpid */
#include <sys/types.h> /* pid_t */

void process(int number, int time) {
  printf("Prosess %d kjører\n", number);
  sleep(time);
  printf("Prosess %d kjørte i %d sekunder\n", number, time);
}

int main(void) {
  int p;

  p = fork();
  if (p == 0) {
    process(1,1);
    exit(0); 
  }
  waitpid(p, NULL, 0);
  process(2,1);
  exit(0);
}
