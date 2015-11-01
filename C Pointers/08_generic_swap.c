#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(void* ,void* , size_t);
int main() {
    char letter = 'B', symbol = '+';
    swap(&letter, &symbol, sizeof(char));
    printf("%c %c", letter, symbol);
    printf("\n");
    
    int a = 10, b = 6;
    swap(&a, &b, sizeof(int));
    printf("%d %d", a, b);
    printf("\n");
    
    double d = 3.14, f = 1.23567;
    swap(&d, &f, sizeof(double));
    printf("%.2lf %.2lf", d, f); 

    printf("\n");
    return 0;
}

void swap(void* a, void* b, size_t size){
    char* first_ptr = a;
    char* second_ptr = b;
    
    int i;
    for (i = 0; i < size; i++) {
        char* tmp = *(first_ptr + i);
        *(first_ptr + i) = *(second_ptr + i);
        *(second_ptr + i) = tmp;
    }

}