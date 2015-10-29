/* 
 * File:   05_longest_increasing_sequence.c
 * Author: adutev
 *
 * Created on October 29, 2015, 4:48 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int get_numbers(int*, int);
void longest_increasing_sequence(int*,int);

int main(int argc, char** argv) {
    int i, size;
    
    printf("Enter an integer number:");
    if(scanf("%d", &size) != 1) {
        printf("Invalid input");
        return 1;
    }
    int numbers[size];
    int got_numbers = get_numbers(numbers, size);
    if(got_numbers != 0){
        printf("Invalid number of integers entered.");
        return 1;
    }

    longest_increasing_sequence(numbers, size);
    
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

void longest_increasing_sequence(int* numbers,int size){
    int i;
    int curr_count = 1; //counts current seq
    int curr_start = 0; //start of current seq
    int max_start = 0; //start of the max seq
    int max_count = 1; //max count
    int in = 1;
    
    for(i = 1; i <= size; i++){
        if(numbers[i-1] < numbers[i]){
            if(!in){
                in = 1;
                curr_start = i - 1;
            }
            curr_count++;
            printf("%d ", numbers[i-1]);
        } else {
            if(curr_count > max_count){
                max_count = curr_count;
                max_start = curr_start;
            }
            curr_start = i -1;
            curr_count = 1;
            in = 0;
            printf("%d\n", numbers[i-1]);
        }
    }
    printf("Longest: ");

    for(i = max_start; i < (max_start + max_count);i++){
        printf("%d ", numbers[i]);
    }
}