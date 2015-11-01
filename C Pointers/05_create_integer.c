#include <stdio.h>
#include <stdlib.h>

int new_integer();
int* new_integer_ptr();

int main() {
    int a = new_integer();
    printf("new_integer() -> %d\n", a);
    
    int* b = new_integer_ptr();
    printf("This will get the correct value of 30. b = %d\n", *b); // This will get the correct value of 30
    printf("enter some int: ");
    scanf("%d", &a);
    printf("Now we erazed the real value of b and will get invalid value. b = %d", *b);
    return 0;
}

int new_integer(){
    int a = 20;
    return a;
}
int* new_integer_ptr(){
    int b = 30;
    int *b_ptr = &b;
    return b_ptr;
}