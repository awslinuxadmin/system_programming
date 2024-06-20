#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>


int main(){

    int size;
    char buf[100];

    strcpy(buf, "Data written to file... \n");

    int openFile = open("xyz",O_WRONLY | O_APPEND);

    if(openFile < 0) {
        perror("Sorry, there was an ERROR opening the file. \n");
        exit(1);
    }
    else {
        printf("The file has been created in this DIR with data written to it.");
    }

    size = write(openFile,buf,strlen(buf));
    printf("The number of bytes written is: %d", size);

    return 0;
}