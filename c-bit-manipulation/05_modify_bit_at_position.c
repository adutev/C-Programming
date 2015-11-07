/* 
 * File:   05_modify_bit_at_position.c
 * Author: Toni
 *
 * Created on November 7, 2015, 9:01 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int n, p, v;
    if (scanf("%d %d %d", &n, &p, &v) != 3) {
        printf("Invalid format");
        return 1;
    }
    int mask = 1 << p;
    if(v == 0){
        n = n & ~(mask);
    } else {
        n = n | mask;
    }
   
    printf("%d", n);
    return (EXIT_SUCCESS);
}

