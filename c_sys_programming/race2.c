#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

void main(){

    int openFile, i;

    openFile = open("./log.tx", O_RDWR);
    if(openFile < 0){
        sleep(5);
        openFile = open("./log.txt", O_RDWR | O_CREAT, 0666);
        if(openFile > 0){
            printf("\nProgram2 created log.txt\n");
            close(openFile);
        }

    }

}