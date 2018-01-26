#include<stdio.h>
#define SIZE 10000

int g_x[SIZE][SIZE],g_y[SIZE][SIZE],g_prod[SIZE][SIZE];

int main(void) {
   int i,j;
   for (i=0;i<SIZE;i++) {
      for (j=0;j<SIZE;j++) {
         g_prod[i][j] = g_x[i][j] * g_y[i][j];
      }
   }
   return 0;
}
