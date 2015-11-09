/* 
 * File:   04_copy_bin_file.c
 * Author: adutev
 *
 * Created on November 8, 2015, 2:58 PM
 */

#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 4096

int main(int argc, char** argv) {
    char *buffer[BUFFER_SIZE];
    FILE *source = fopen("pic.jpg", "r");
    FILE *destination = fopen("new_pic.jpg", "w");

    if (source && destination) {
        while (!feof(source)) {
            fread(buffer, 1, BUFFER_SIZE, source);
            fwrite(buffer, 1, BUFFER_SIZE, destination);
        }
    }

    return (EXIT_SUCCESS);
}

