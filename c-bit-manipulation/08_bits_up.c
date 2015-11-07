/* 
 * File:   08_bits_up.c
 * Author: Toni
 *
 * Created on November 7, 2015, 9:09 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int n, step;
    if(scanf("%d", &n)!=1){
        printf("invalid input.");
        return 1;
    }
    if(scanf("%d", &step) != 1){
        printf("invalid input.");
        return 1;
    }
    int numbers[n];
    int i;
    printf("Bytes: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    return 0;
}

