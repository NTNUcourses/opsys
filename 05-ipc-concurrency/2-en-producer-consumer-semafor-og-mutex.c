#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     /* usleep */
#include <pthread.h>
#include <semaphore.h>
#define SHARED 0        /* process-sharing if !=0, thread-sharing if =0*/
#define BUF_SIZE 10
#define MAX_MOD 100000
#define NUM_ITER 200

void *Producer(void *); /* Producer thread */
void *Consumer(void *); /* Consumer thread */

sem_t empty;            /* empty: How many empty buffer slots */
sem_t full;             /* full: How many full buffer slots */
pthread_mutex_t mutex;  /* mutex: Mutex lock */
int g_data[BUF_SIZE];   /* shared finite buffer  */
int g_idx;              /* index to next available slot in buffer, 
                           remember that globals are set to zero
                           according to C standard, so no init needed  */

int main(void) {
	pthread_t pid, cid;
	
	// Initialie the semaphores
	sem_init(&empty, SHARED, BUF_SIZE);
	sem_init(&full, SHARED, 0);
	// Initialize the mutex
	pthread_mutex_init(&mutex,0);

	// Start both the producer and the consumer.
	printf("main started\n");
	pthread_create(&pid, NULL, Producer, NULL);
	pthread_create(&cid, NULL, Consumer, NULL);
	
	// Wait for the 
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
	printf("main done\n");

	return 0;
}


void *Producer(void *arg) {
	int i=0, j;

	while(i < NUM_ITER) {
		// Sleep a random time, to simulate the generation of something
		usleep(rand()%MAX_MOD);
		
		// Wait for at least one empty slot in the buffer
		sem_wait(&empty);
		// Try to enter region with exclusive access.
		pthread_mutex_lock(&mutex);
		
		// Insert item into buffer
		g_data[g_idx] = 1;
		g_idx++;
		
		// Print buffer status
		j=0; printf("(Producer, Buffer usage is %d): ", g_idx);
		while(j < g_idx) { j++; printf("="); } printf("\n");
		
		// Leave region with exclusive access
		pthread_mutex_unlock(&mutex);
		// Increase the counter for full bufferslots.
		sem_post(&full);
		
		i++;    
	}

	return 0;
}


void *Consumer(void *arg) {
	int i=0, j;

	while(i < NUM_ITER) {
		// Wait a random time, to pretend to consume the item.
		usleep(rand()%MAX_MOD);
		
		// Wait for at least one slot to be full
		sem_wait(&full);
		// Wait for exclsive access to critical region
		pthread_mutex_lock(&mutex);
		
		// Remove item from buffer.
		g_data[g_idx-1]=0;
		g_idx--;
		
		// Print the buffer status.
		j=0; printf("(Consumer, Buffer usage is %d): ", g_idx);
		while(j < g_idx) { j++; printf("="); } printf("\n");
		
		// Leave region with exclusive access
		pthread_mutex_unlock(&mutex);
		// Increase counter of empty bufferslots.
		sem_post(&empty);
		
		i++;
	}

	return 0;

}
