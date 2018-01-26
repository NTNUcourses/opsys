// Ingve Skåra - 2016-01-02
// musl is required for threads.h. Install with apt-get install musl-dev'

/*
 Compile with:
 gcc demo-c11-stdthread-atomic.c -o demo-c11-stdthread-atomic \
 -Wno-incompatible-pointer-types -std=c11 -static \
 -nostdlib -I/usr/include/x86_64-linux-musl \
 -L/usr/lib/x86_64-linux-musl /usr/lib/x86_64-linux-musl/crt1.o \
 /usr/lib/x86_64-linux-musl/crti.o /usr/lib/x86_64-linux-musl/crtn.o -lc 
*/

#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>

void status();
thrd_start_t inc(void *);
thrd_start_t dec(void *);

static const int count = 10000000;
static const int iterations = 20;
static atomic_int number = ATOMIC_VAR_INIT(0);

int main(void) {
    for(int i = 0; i < iterations; i++) {
        thrd_t tid1, tid2;
        thrd_create(&tid1, inc, NULL);
        thrd_create(&tid2, dec, NULL);
        thrd_join(tid1, NULL);
        thrd_join(tid2, NULL);

        status();
    }
}

void status() {
    printf("My number is: %d\n", number);
}
 
thrd_start_t inc(void *a) {
    for(int i = 0; i < count; i++)
           number++;
}

thrd_start_t dec(void *a) {
    for(int i = 0; i < count; i++)
        number--;
}
