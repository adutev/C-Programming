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
    char* substring1 = sub_str("Breaking Bad", 0, 2);
    printf("%s\n", substring1);
    if(substring1 != NULL){
        free(substring1);
    }
    char* substring2 = sub_str("Maniac", 3, 3);
    printf("%s\n",substring2);
     if(substring2 != NULL){
        free(substring2);
    }
    char* substring3 = sub_str("Maniac", 3, 5);
    printf("%s\n", substring3);
     if(substring3 != NULL){
        free(substring3);
    }
    char* substring4 = sub_str("Master Yoda", 13, 5);    
    printf("%s\n", substring4);
     if(substring4 != NULL){
        free(substring4);
    }


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