#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {

    int fd;
    // read only permission
    fd = open("demo.c", O_RDONLY);
    if (fd == -1){
        printf("Error opening file...");
    }
    else
    printf("OPEN FILE sucess...");

    return 0;
}