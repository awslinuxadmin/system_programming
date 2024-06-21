#include <stdio.h>

int main (int argc, char *argv[]){

    int i;
    system("clear");

    if (argc == 1){
        printf("Please provide command line arguments...");
    return 0;

    }
    else{
        printf("Total number of arguments is %d and they are \n\n", argc);
        for(i=0; i<argc ; i++){
            printf("%d -- %s \n", i+1, argv[i]);
        }
    
        return 0;
    }
}
