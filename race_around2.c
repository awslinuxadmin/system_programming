#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main(){

    int openFile, i;
    char buf[100];
    char buf2[2]={'\n'};

    openFile = open("./log.txt", O_RDWR | O_SYNC);

    for(i = 0 ; i < 99 ; i++){
        buf[i] = 'b';
    }

    for(i = 0 ; i < 5 ; i++){
        (void)write(openFile,buf,99);
        (void)write(openFile,buf2,1);
    }

    printf("\nProgram2 exited\n");
    close(openFile);

}