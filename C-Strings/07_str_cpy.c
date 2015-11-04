/* 
 * File:   07_str_cpy.c
 * Author: Toni
 *
 * Created on November 4, 2015, 1:21 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* str_cpy(char* dest, const char* src, size_t n);
int main() {
    size_t size = 100;
    char buffer[size];
    memset(buffer, 0, size);
    str_cpy(buffer, "SoftUni", 7);
    printf("%s\n", buffer);   

    str_cpy(buffer, "SoftUni", 3);
    printf("%s\n", buffer);   

    str_cpy(buffer, "C is cool", 0);
    printf("%s\n", buffer);
    
    char* result = str_cpy(NULL, "SoftUni", 7);
    printf("%s\n", result);
    return (EXIT_SUCCESS);
}

char* str_cpy(char* dest, const char* src, size_t n){
    if(dest == NULL){
        dest = malloc(n + 1);
        if(dest == NULL){
            printf("Cannot allocate memory.");
            exit(1);
        }
    }

    size_t i = 0;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
        if(src[i]=='\0'){
            return dest;
        }
    }
    
    dest[i] = '\0';    
    return dest;
}