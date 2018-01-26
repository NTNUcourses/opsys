#include<unistd.h>

int main(void) {
 int i;
 for (i=0; i<10000000; i++) {
  getppid();
 }
 return(0);
}
