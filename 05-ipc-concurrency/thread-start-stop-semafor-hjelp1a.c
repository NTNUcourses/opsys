#include <stdio.h>		 /* printf */
#include <stdlib.h>		/* exit */
#include <unistd.h>		/* fork */
#include <pthread.h> 
#include <semaphore.h> 

#define SHARED 0

sem_t sem[6];

// En datastruktur til å gi info til trådene
struct threadargs {
	int id;         // Trådens ID
	int sec;        // Hvor lenge skal tråden kjøres
	int signal[6];  // Hvem skal tråden gi signal til
                  // når den er ferdig?
};

void* tfunc(void *arg) {
	struct threadargs *targs=arg;
  // Vent på lov til å kjøre (tell ned egen semafor)

  // Print at tråden starter
  printf("Hei. Tråd %d har startet\n", targs->id);
  printf("Den skal kjøre i %d sekund\n", targs->sec);
  
  // Vent noen sekunder

  // Print at tråden er ferdig

  // For i in 0->5:

      // Hvis "jeg" skal signalisere i:

          // Tell opp semafor til tråd i
}

int main(void) {
  int i, j;                    // Tellere til løkker
  struct threadargs* targs[6]; // Pekere til argumentene vi gir til trådene.
  pthread_t tid[6];            // Variabler til å holde trådinformasjon

  // Initialiser argumentene vi gir til trådene.
  for(j = 0; j < 6; j++) {
    targs[j] = malloc(sizeof(struct threadargs)); // Sett av minne, og
    targs[j]->id = 0;                             // sett alle variablene
    targs[j]->sec = 0;                            // til 0.
    for(i = 0; i < 6; i++)
      targs[j]->signal[i] = 0;
  }
  
  // START T0
  // Sett opp data til T0
  targs[0]->id = 0;
  targs[0]->sec = 1;
  targs[0]->signal[1] = 1;
  targs[0]->signal[4] = 1;
  // Initialiser semafor til T0
  sem_init(&sem[0], SHARED, 1);
  // Start T0
  pthread_create(&tid[0], NULL, tfunc, targs[0]);

  // START T1
  // Sett opp data til T1
  targs[1]->id = 1;
  targs[1]->sec = 2;
  targs[1]->signal[3] = 1;
  // Initialiser semafor til T1
  sem_init(&sem[1], SHARED, 0);
  // Start T1
  pthread_create(&tid[1], NULL, tfunc, targs[1]);

  // START T2
  // START T3
  // START T4
  // START T5

  // Vent på alle tråder
  pthread_join(tid[0], NULL);
  pthread_join(tid[1], NULL);
	
	return 0;
}

