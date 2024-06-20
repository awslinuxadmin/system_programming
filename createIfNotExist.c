#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){

    int fd;
    // check man 2 open page for flags for create and permissions
    // create the file if it does not exist
    fd = open("xyz", O_RDONLY | O_CREAT , S_IRUSR | S_IWUSR);
    if (fd == -1){
        printf("NO SUCH FILE...");        
    }
    else{
        printf("The file was not found...I created it for you in this DIR.");
    }
    return 0;
}