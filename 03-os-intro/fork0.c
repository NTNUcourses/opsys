#include <unistd.h> /* fork */
#include <stdio.h>  /* printf */

int main(void) {
  int p;

  p=fork();
  printf("\n fork returnerer pid = %d\n", p);

  return 0;
}
