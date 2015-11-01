#include <stdio.h>
#include <stdlib.h>

void print_integer_address(int*);

int main() {
    int n;
    int matches = scanf("%d", &n);
    if(matches != 1){
        printf("Invalid input.");
        return 1;
    }
    printf("The address before function: %p\n", &n);
    print_integer_address(&n);

    return (EXIT_SUCCESS);
}

void print_integer_address(int* number){
    printf("The address after calling the function: %p", &number);
}
