/* Figure 2.15 from Tanenbaum, see 'man 3 pthread_create' for args,example */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid) {
 printf("Hello World. Greetings from thread %ld\n", (intptr_t) tid);
 pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
 pthread_t threads[NUMBER_OF_THREADS];
 int status,j;
 intptr_t i;

 for (i=0; i < NUMBER_OF_THREADS; i++) {
  printf("Main here. Creating thread %ld\n", i);
  status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);

  if (status != 0) {
   printf("Oops. pthread create returned error code %d\n", status);
   exit(EXIT_FAILURE);
  }
 }
 for(j=0;j<NUMBER_OF_THREADS;j++) pthread_join(threads[j], NULL);
 return 0;
}
