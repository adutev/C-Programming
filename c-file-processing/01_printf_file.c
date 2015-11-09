/* 
 * File:   main.c
 * Author: adutev
 *
 * Created on November 8, 2015, 11:17 AM
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int ch;
    FILE *file = fopen("file.txt", "r");
    if (file) {
        while ((ch = fgetc(file)) != EOF) {
            printf("%c", ch);
        }
        fclose(file);
    } else {
        printf("no such file");
    }

    return (EXIT_SUCCESS);
}

