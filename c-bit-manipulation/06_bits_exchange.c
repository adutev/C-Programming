/* 
 * File:   06_bits_exchange.c
 * Author: Toni
 *
 * Created on November 7, 2015, 9:05 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    unsigned long long n;
    if (scanf("%d", &n) != 1) {
        printf("Invalid format");
        return 1;
    }
    // get the bits at 3-5 and 24-26 positions
    unsigned long long right_bits = (n & (7 << 3)) >> 3;
    unsigned long long left_bits = (n & (7 << 24)) >> 24;
    // set 3-5 and 24-26 to zero
    n = n &~(7 << 3);
    n = n &~(7 << 24);
    // set left and right bits
    n = n | right_bits << 24;
    n = n | left_bits << 3;

    printf("%u", n);
    return (EXIT_SUCCESS);
}

