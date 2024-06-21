#include <stdio.h>
#include <stdlib.h>

//dynamic memory allocation

void main(void){

    int *pointer = NULL; // create a NULL pointer
    
    pointer = (int*)malloc(10 * sizeof(int)); // we point it to memory allocation
    // calloc function takes 2 arguments -- malloc takes 1
    // pointer = (int*)calloc(10, sizeof(int)); // needs to know for each value
    if(pointer == NULL){
        printf("\n ERROR during MEMORY allocation"); // if it doesn't work - maintain NULL
        exit(-1);
    }

for (int x = 0; x < 10; x++){
    pointer[x] = x;
}
for (int x = 0; x < 10; x++){
    printf("\n pointer int[%d] = (%d)", x, pointer[x]);
}
    free(pointer); // free the pointer memory location

}