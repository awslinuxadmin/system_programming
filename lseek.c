#include <string.h> //  for string manipulation functions like strcpy
#include <stdlib.h> // for exit function
#include <fcntl.h> // for file control options like O_RDWR
#include <stdio.h> // for standard input/output operations like printf
#include <unistd.h> // for POSIX OS API, including file handling(open,close,lseek)

// This C program demonstrates how to open a file, seek to specific 
// positions, read from it, append data to it, and close it using 
// standard file manipulation functions in C. This example showcases 
// basic file handling operations commonly used in systems programming

int main() {

    int size, seek_pos=0;
    char buf[200];

    int openFile = open("xyz.txt", O_RDWR); // read/write perms
    if(openFile < 0){
        perror("ERROR opening file"); // if xyz.txt does not exist
        exit(1);
    }

    seek_pos = lseek(openFile, 5, SEEK_SET);
    // lseek is used to move the file pointer (openFile) 
    // to a specific position (5 bytes from the beginning 
    // of the file (SEEK_SET))

    size = read(openFile,buf,10);
    buf[size]='\0'; // buf[size] = '\0' ensures buf is null-terminated to treat it as a string

    printf("\n The read bytes are as follows: %s ", buf);

    seek_pos = lseek(openFile, 0, SEEK_END);
    strcpy(buf, "\n This line was added using lseek function w/ SEEK_SET");
    size = write(openFile,buf,strlen(buf));
    // lseek seeks to the end of the file (SEEK_END), 
    // returning the current position (seek_pos is updated).

    close(openFile);


    return 0;
}