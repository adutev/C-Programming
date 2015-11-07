/* 
 * File:   04_bit_destroyer.c
 * Author: Toni
 *
 * Created on November 7, 2015, 8:59 AM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int n, p;
    if(scanf("%d %d", &n, &p)!=2){
        printf("Invalid format");
        return 1;
    }
    int mask = 1 << p;
    n = n & ~(mask);
    printf("%d", n);
    return (EXIT_SUCCESS);
}

