#include <stdio.h>
#define uint64_t unsigned long int

int main(void) {
 uint64_t i, s = 0;
 for (i=0; i<1000000000; i++) {
  s = s + i;
 }
// printf("s = %ld, c = %ld\n",s, i*(i-1) / 2);
 return(0);
}
