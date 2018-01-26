#include<stdio.h>

struct firkant {
  int x;
  int y;
} firkant;

void en(void* b) {
  struct firkant* c;
  c = (struct firkant*) b; 
  printf("c er %d\n", (*c).x);
}

void to(void* b) {
  struct firkant* c;
  c = (struct firkant*) b; 
  printf("c er %d\n", c->x);
}

void tre(void* b) {
  printf("b er %d\n", (*(struct firkant*)b).x);
}

void fire(void* b) {
  printf("b er %d\n", ((struct firkant*)b)->x);
}

int main (void) {
  int a = 1;
  int* p = &a;
  
  struct firkant k;
  k.x = 2;
  k.y = 3;

  en(&k);
  to(&k);
  tre(&k);
  fire(&k);

  return 0;
}
