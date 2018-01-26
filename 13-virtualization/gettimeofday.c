#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

int main(void)
{
 struct timeval c;
 int i;
 for(i=0; i<10000000; i++) {
  gettimeofday(&c,NULL);
 }
 return(0);
}
