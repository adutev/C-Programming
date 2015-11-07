/* 
 * File:   03_check_bit_at_position.c
 * Author: Toni
 *
 * Created on November 7, 2015, 8:54 AM
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
    int result = (1&(n>>p));
    if(result){
        printf("true");
    } else {
        printf("false");

    }
    return 0;
}

