#include<stdio.h>

int main (void) {
  // allocate three integers and two pointers
  int a = 1;
  int b = 2;
  int c = 3;
  int* p;
  int* q;

  // print a pointer like this:
  printf("p is %p\n", (void*) p);
  // A POINTER ("a reference to another value") IS JUST A VARIABLE
  // HOLDING A MEMORY-ADDRESS! we can also print its own memory-address:
  printf("p is %p\n", (void*) &p);

  p = &a;  // set p to refer to a
  q = &b;  // set q to refer to b
  c = *p;  // retrieve p's pointee value (1) and put it in c
  p = q;   // change p to share with q (p's pointee is now b)
  *p = 13; // DEREFERENCE p to set its pointee (b) to 13 (*q is now 13)
           // The above statement is ok, because the pointer is assigned
           // NEVER DEREFERENCE AN UNASSIGNED POINTER
           // (a pointer without a "pointee")           

  return 0;
}
