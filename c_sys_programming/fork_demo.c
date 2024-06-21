#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){


    pid_t id;
    printf("The ID of PARENT PROCESS is:  %d\n",getpid());
    id = fork();
    if (id < 0){
        printf("\nFORK PROCESS creation has failed...");
        exit(-1);
    }
    if (id > 0){
        printf("\nPARENT PROCESS created a CHILD PROCESS with PID:  %d\n", id);

    } else {
        printf("\n This CHILD PROCESS ID:  %d\n", id);
        printf("\n CHILD PROCESS ID using getpid() function as:  (%d)\n", getpid());
        printf("\n PARENT PROCESS of the CHILD PROCESS using function getppid() is ID:  %d\n", getppid());
    }
    return 0;
}