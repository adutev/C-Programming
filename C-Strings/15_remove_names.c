/* 
 * File:   15_remove_names.c
 * Author: Toni
 *
 * Created on November 4, 2015, 10:12 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline(char* line);

int main(int argc, char** argv) {
    char* first = readline(first);
    size_t first_len = strlen(first);
    char* second = readline(second);
    char* token = strtok(second, " ");
    size_t token_len = strlen(token);
    while (token != NULL) {
        char* substring = strstr(first, token);
        while (substring) {
            size_t remove_from = substring - first;
            size_t remove_to = remove_from + token_len + 1;
            size_t bytes_to_move = first_len - remove_from;
            memmove(&first[remove_from], &first[remove_to], bytes_to_move);
            substring = strstr(first, token);
        }
        token = strtok(NULL, " ");
    }

    printf("%s", first);
    free(token);
    free(first);
    free(second);

    return (EXIT_SUCCESS);
}

char* readline(char* line) {
    unsigned long long buffer = 2;
    unsigned long long current_length = 0;
    char* result = malloc(buffer);
    char ch = getchar();
    while (ch != '\n' && ch != EOF) {
        if (current_length == buffer - 1) {
            buffer *= 2;
            char* new_size = realloc(result, buffer);
            if (!new_size) {
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
