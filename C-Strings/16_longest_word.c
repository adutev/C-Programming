/* 
 * File:   16_longest_word.c
 * Author: Toni
 *
 * Created on November 5, 2015, 12:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

char* readline(char*);
char* find_longest(char*, size_t);
int main() {
    char* line = NULL;
    line = readline(line);
    size_t input_length = strlen(line);
    char* longest = find_longest(line, input_length);
    int i;
    for (i = 0; i < strlen(longest); i++) {
        printf("%c", longest[i]);
    }
    free(longest);
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

char* find_longest(char* str, size_t input_len){
    int i, current_count = 0, in_a_word = 0;
    char* longest = calloc(input_len + 1, sizeof (char*));
    size_t longest_len = 0;
    
    char* tmp_word = calloc(input_len + 1, sizeof (char*));
    //The C# Basics course is awesome start in programming with C# and Visual Studio.
    for (i = 0; i <= input_len; i++) {
        char ch = str[i];
        if (ch == '\0' || ch == ' ' || ch == '\n') {
            if (in_a_word) {
                tmp_word[current_count] = '\0';
                if(current_count > longest_len){
                    longest_len = current_count;
                    strcpy(longest, tmp_word);
                }
                in_a_word = 0;
            }
            current_count = 0;
        } else {
            if (!in_a_word) {
                in_a_word = 1;
            }
            tmp_word[current_count++] = ch;
        }
    }
    free(tmp_word);

    return longest;
}