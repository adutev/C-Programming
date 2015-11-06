/* 
 * File:   13_read_line.c
 * Author: Toni
 *
 * Created on November 4, 2015, 7:17 PM
 */

#include <stdio.h>
#include <stdlib.h>


char* readline(char*);
int main(int argc, char** argv) {
    char* line = NULL;
    line = readline(line);
    printf("%s", line);    
    free(line);
    return 0;
}
char* readline(char* line){
    unsigned long long buffer = 2;
    unsigned long long current_length = 0;
    char* result = malloc(buffer);
    char ch = getchar();
    while(ch != '\n' && ch != EOF){
        if(current_length == buffer - 1){
            buffer *= 2;
            char* new_size = realloc(result, buffer);
            if (!new_size)
            {
                printf("Not enough memory!");
                exit(1);
            }
            result = new_size;
        }
        result[current_length++] = ch;
        ch = getchar();
    }
    result[current_length] = '\0';
    return result;
}

