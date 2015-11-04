/* 
 * File:   08_str_con.c
 * Author: Toni
 *
 * Created on November 4, 2015, 2:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* str_ncat(char*, const char*, size_t);

int main(int argc, char** argv) {

    char buffer1[10] = "Soft";
    str_ncat(buffer1, "Uni", 7);
    printf("%s\n", buffer1);

    char buffer2[5] = "Soft";
    str_ncat(buffer2, "ware University", 15);
    printf("%s\n", buffer2);
    
    char buffer3[10] = "C";
    str_ncat(buffer3, " is cool", 8);
    printf("%s\n", buffer3);

    // Cannot modify this string literal
    //    char * buffer4 = "C";
    //    strncat(buffer4, " is cool", 8);
    return (EXIT_SUCCESS);
}

char* str_ncat(char* dest, const char* src, size_t n) {
    size_t i;
    int dest_size = strlen(dest);

    for (i = 0; i < n; i++) {
        if (src[i] != '\0') {
            dest[dest_size + i] = src[i];
        } else {
            dest[dest_size + i] = '\0';
            return dest;
        }

    }
    dest[dest_size + i] = '\0';

    return dest;
}
