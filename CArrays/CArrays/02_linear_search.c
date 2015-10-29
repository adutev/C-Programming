#include <stdio.h>
#include <stdlib.h>

void get_numbers(int*, int);
void linear_search(int*, int, int);

int main(int argc, char** argv) {
    int size;
    printf("Enter number of integers:");
    int matches = scanf("%d", &size);
    if(matches != 1 || size < 1){
        printf("Invalid input");
    } else {
        int numbers[size];
        get_numbers(numbers, size);
    }
    
    
    return (EXIT_SUCCESS);
}

void get_numbers(int* numbers, int size){
    int i, number_to_find, matches = 0;
   
    printf("Enter %d integers:", size);
    for (i = 0; i < size; i++)
    {
        matches += scanf("%d", &numbers[i]);
    }
    if(matches != size){
        printf("Invalid number of integers entered.");
        return -1;
    } else {
        printf("Enter a number to find:");
        matches = scanf("%d", &number_to_find);
        if(matches != 1){
            printf("Invalid number entered.");
            return -1;
        } else {
            linear_search(numbers, size, number_to_find);
        }
    }
}

void linear_search(int* numbers, int size, int number_to_find){
    int i,found = 0;
    for(i = 0; i< size;i++){
        if(numbers[i] == number_to_find){
            found = 1;
            break;
        }
    }
    
    if(found){
        printf("yes");
    } else {
        printf("no");
    }
}