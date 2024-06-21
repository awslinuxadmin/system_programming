#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
    // create a buffer array with 100 byte length to store the string
    size_t length;
    int lenString;
    char buf[100];

    strncpy(buf, "Hello! Printed through system call.", 99);
    lenString = strlen(buf);

    length = write(1,buf,lenString);
    
    return 0;
}

