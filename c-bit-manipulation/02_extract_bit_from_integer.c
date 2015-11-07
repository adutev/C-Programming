/* 
 * File:   02_extract_bit_from_integer.c
 * Author: Toni
 *
 * Created on November 7, 2015, 8:48 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main() {
    int n, p;
    if (scanf("%d %d", &n, &p) != 2)
    {
        printf("Invalid input!");
        return 1;
    }
    int p_bit = 1 & (n>>p);
    printf("%d", p_bit);
    return (EXIT_SUCCESS);
}

