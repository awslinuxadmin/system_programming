#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <malloc.h>
#include <unistd.h>

int main() {

    int readFile, size;

    char buf[100] = {0}; // add a value

    readFile = open("xyz", O_RDONLY);

    if(readFile < 0){

        perror("ERROR");  
        exit(1); 
    }
    
    else {
        
    size = read(readFile,buf,10);
    printf("First %d bytes are: \n %s ", size, buf); 
    // use %d to return an int value and %s for string
    exit(1);
    }  

    
    return 0;
}