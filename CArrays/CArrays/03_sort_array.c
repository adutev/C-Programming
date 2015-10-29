/* 
 * File:   03_sort_array.c
 * Author: adutev
 *
 * Created on October 29, 2015, 9:59 AM
 */

#include <stdio.h>
#include <stdlib.h>

int get_numbers(int*, int);
void bubble_sort(int*, int);

int main(int argc, char** argv) {
    int i, size;
    printf("Enter number of integers:");
    int matches = scanf("%d", &size);
    if (matches != 1 || size < 1) {
        printf("Invalid input");
        return -1;
    } else {
        int numbers[size];
        int got_numbers = get_numbers(numbers, size);
        if (got_numbers == 0) {
            for (i = 0; i < size; i++) {
                printf("%d ", numbers[i]);
            }
        } else {
            return -1;
        }

    }


    return 0;
}

int get_numbers(int* numbers, int size) {
    int i, matches = 0;

    printf("Enter %d integers:", size);
    for (i = 0; i < size; i++) {
        matches += scanf("%d", &numbers[i]);
    }
    if (matches != size) {
        printf("Invalid number of integers entered.");
        return -1;
    } else {
        bubble_sort(numbers, size);
        return 0;
    }
}

void bubble_sort(int* numbers, int size) {
    int swapped = 1;
    while (swapped) {
        swapped = 0;
        int i;
        for (i = 0; i < size - 1; i++) {
            if (numbers[i] > numbers[i + 1]) {
                int temp = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = temp;
                swapped = 1;
            }
        }
    }
}