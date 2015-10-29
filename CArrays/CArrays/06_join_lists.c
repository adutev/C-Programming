
/* 
 * File:   06_join_lists.c
 * Author: adutev
 *
 * Created on October 29, 2015, 6:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int get_numbers(int*, int);

int main(int argc, char** argv) {
    int i, j, size_a, size_b;
    
    printf("Enter a size for list a:");
    if(scanf("%d", &size_a) != 1) {
        printf("Invalid input");
        return 1;
    }
    int list_a[size_a];
     printf("\nEnter a size for list b:");
    if(scanf("%d", &size_b) != 1) {
        printf("Invalid input");
        return 1;
    }
    int list_b[size_b];
    int got_numbers_a = get_numbers(list_a, size_a);
    int got_numbers_b = get_numbers(list_b, size_b);
    if(got_numbers_a != 0 || got_numbers_b != 0){
        printf("Invalid number of integers entered.");
        return 1;
    }
    int size_result = size_a + size_b;
    for(i = 0; i < size_a; i++){
        for(j = 0; j< size_b; j++){
            if(list_a[i] == list_b[j]){
                printf("%d",list_a[i]);
            }
        }
    }
    
    int result_list[size_result];

    return 0;
}

int get_numbers(int* numbers, int size) {
    int i, matches = 0;

    printf("Enter %d integers numbers:", size);
    for (i = 0; i < size; i++) {
        matches += scanf("%d", &numbers[i]);
    }
    if (matches != size) {
        printf("Invalid number of integers entered.");
        return 1;
    }
    
    return 0;
}