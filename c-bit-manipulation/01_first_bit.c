/* 
 * File:   01_first_bit.c
 * Author: Toni
 *
 * Created on November 6, 2015, 9:08 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int n, first_bit, third_bit, first_number, third_number;
    int matches = scanf("%d", &n);
    if(matches!=1){
        printf("Invalid input.");
        return NULL;
    }
    
    first_bit = (n >> 1) & 1;
    third_bit = (n >> 3) & 1;

 
    printf("First bit: %d\n", first_bit);
    printf("Third bit: %d\n", third_bit);

    return 0;
}

