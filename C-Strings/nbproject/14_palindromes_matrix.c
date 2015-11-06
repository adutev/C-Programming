/* 
 * File:   14_palindromes_matrix.c
 * Author: Toni
 *
 * Created on November 4, 2015, 9:38 PM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int r;
    printf("Rows: ");
    scanf("%d", &r); 
    int c;
    printf("Cols: ");
    scanf("%d", &c);
    char a = 'a';
    int i;
    for (i = 0; i < r; i++) {
        int j;
        for (j = 0; j < c; j++) {
            printf("%c%c%c ", a, a+j, a);
        }
        a += 1;
        printf("\n");
    }

    return (EXIT_SUCCESS);
}

