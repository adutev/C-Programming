#include <stdio.h>
#include <stdlib.h>

void swap(int* first, int* second);

int main(){
    int a = 10;
    int b = 53;
    swap(&a, &b);
    
    printf("a: %d, b: %d", a, b);
    return 0;
}

void swap(int* first, int* second){
    int tmp = *first;
    *first = *second; 
    *second =  tmp;
}
