#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/syscall.h>

#define NITER 10

int ant = 0;

void *IncThread(void *a)
{
    int i;
    for (i = 0; i < NITER; i++) {
       ant++;
       //       printf("%ld sier ant er nå %d\n",syscall(SYS_gettid),ant);
    }
    return 0;
}

void *DecThread(void *a)
{
    int i;
    for (i = 0; i < NITER; i++) {
       ant--;
       //       printf("%ld sier ant er nå %d\n",syscall(SYS_gettid),ant);
    }
    return 0;
}

int main(int argc, char * argv[]) /* NB! ingen feilsjekking! */
{
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, IncThread, NULL); /* start tråder */
    pthread_create(&tid2, NULL, DecThread, NULL);
    pthread_join(tid1, NULL);                   /* vent på tråder */
    pthread_join(tid2, NULL); 

    if (ant != 0) 
        printf(" HUFF! ant er %d, skulle vært 0\n", ant);
    else
        printf(" OK! ant er %d\n", ant);
  
    return 0;
}


