/* 
 * File:   02_odd_lines.c
 * Author: adutev
 *
 * Created on November 8, 2015, 12:35 PM
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    int ch, rows = 0;

    FILE *file = fopen("file.txt", "r");
    if (file) {
        while ((ch = fgetc(file)) != EOF) {
            if (ch == '\n') {
                rows++;
            }
        }
        printf("%d", rows / 2);
        fclose(file);
    } else {
        printf("no such file");
    }

    return (EXIT_SUCCESS);
}

