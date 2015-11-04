/* 
 * File:   12_substring_extract.c
 * Author: Toni
 *
 * Created on November 4, 2015, 6:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
char* sub_str(char*, int, int);

int main() {
    printf("%s\n", sub_str("Breaking Bad", 0, 2));
    printf("%s\n",sub_str("Maniac", 3, 3));
    printf("%s\n",sub_str("Maniac", 3, 5));
    printf("%s\n",sub_str("Master Yoda", 13, 5));

    return (EXIT_SUCCESS);
}

char* sub_str(char* str, int from, int to){
    int count = 0;
    int str_len = strlen(str);
    char* result = calloc(str_len, sizeof(char));
    int i;
    for (i = 0; i < str_len; i++) {
        if(i>= from && i < (from+to)){
            result[count++] = str[i];
        }
    }
    
    return result;
}