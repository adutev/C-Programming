/* 
 * File:   18_longest_area_in_array.c
 * Author: Toni
 *
 * Created on November 5, 2015, 2:57 PM
 */

#include <stdio.h>
#include <stdlib.h>

/* 1. Get n
 * 2. Get n-lines and store them in char** array
 * 3. 
 */

int main() {
    int n, i;
    int matches = scanf("%d", &n);
    if(matches != 1){
        return NULL;
    }
    char** lines = malloc(n*sizeof(char*));
    
    for (i = 0; i < n; i++) {
        char currentLine[1024];
        scanf("%s", &currentLine);
        lines[i] = strdup(currentLine);
        if(n == 1 && lines[0]){
            printf("%d\n%s", n, lines[0]);
            return 0;
        }
    }
    
    int max_len = 1;
    int current_length = 1;
    char* max_element = lines[0];
    char* current_element = max_element;
    
    for (i = 1; i < n; i++) {
        if(i != n - 1 && strcmp(lines[i], current_element) == 0){
            current_length++;
        } else {
            if(strcmp(lines[i], current_element) == 0){
                current_length++;
            }
            if(current_length > max_len){
                max_len = current_length;
                max_element = current_element;
            }
            current_length = 1;
            current_element = lines[i];
        }
    }
    printf("%d\n", max_len);
    for(i = 0; i < max_len; i++){
        printf("%s\n", max_element);
    }
    
    for (i = 0; i < n; i++) {
        free(lines[i]);

    }

    free(lines);
    return 0;
}

