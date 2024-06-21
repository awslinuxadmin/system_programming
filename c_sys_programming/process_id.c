#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

void main (void) {

    printf("\n PROCESS id = %d", getpid());
    printf("\nPARENT PROCESS id = %d", getppid());
    sleep(5);

}

