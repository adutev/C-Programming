/* 
 * File:   08_bits_exchange_advanced.c
 * Author: Toni
 *
 * Created on November 7, 2015, 9:52 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned long n, first_position, second_position, len, bigger, smaller;
    if (scanf("%ld %ld %ld %ld", &n, &first_position, &second_position, &len) != 4) {
        printf("Invalid format");
        return 1;
    }

    // check bigger
    if (first_position > second_position) {
        bigger = first_position;
        smaller = second_position;
    } else {
        bigger = second_position;
        smaller = first_position;
    }
    // check for overlapping
    if (smaller + len - 1 >= bigger) {
        printf("overlapping");
        return 1;
    }
    // check for overlapping
    if (smaller < 0 || bigger > 32 || bigger + len > 32) {
        printf("out of range");
        return 1;
    }
    // create a mask
    unsigned long mask = (1 << len) - 1;    

    //    get the bits at both positions
        unsigned long right_bits = (n & (mask << first_position)) >> first_position;
        unsigned long left_bits = (n & (mask << second_position)) >> second_position;
        // set bits to zero
        n = n &~(mask << first_position);
        n = n &~(mask << second_position);
        // set left and right bits
        n = n | right_bits << second_position;
        n = n | left_bits << first_position;
    
        printf("%u", n);
    return 0;
}

