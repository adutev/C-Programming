/* 
 * File:   10_strlen.c
 * Author: Toni
 *
 * Created on November 4, 2015, 3:27 PM
 */

#include <stdio.h>
#include <stdlib.h>

int str_len(char*);

int main(int argc, char** argv) {

    printf("\"\" is %d characters long\n", str_len(""));
    printf("Soft is %d characters long\n",strlen("Soft"));
    printf("SoftUni is %d characters long\n", str_len("SoftUni"));
    char buffer1[10] = {'C', '\0', 'B', 'a', 'b', 'y'};
    printf("{'C', '\\0', 'B', 'a', 'b', 'y'} is %d characters long\n", str_len(buffer1));
    char buffer2[] = {'D', 'e', 'r', 'p', '\0'};
    printf("{'D', 'e', 'r', 'p', '\\0'} is %d characters long\n",str_len(buffer2));

    return (EXIT_SUCCESS);
}

int str_len(char* str){
    int i = 0;
    while(*str != '\0'){
        i++;
        str++;
    }

    return i;
}