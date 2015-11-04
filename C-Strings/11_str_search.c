/* 
 * File:   11_str_search.c
 * Author: Toni
 *
 * Created on November 4, 2015, 3:39 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strsearch(char*, char*);

int main() {
    printf("%d\n", strsearch("SoftUni", "Soft"));
    printf("%d\n", strsearch("Hard Rock", "Rock"));
    printf("%d\n", strsearch("Ananas", "nasa"));
    printf("%d\n", strsearch("Coolnes", "cool"));


    return (EXIT_SUCCESS);
}

int strsearch(char* str, char* word) {
    int count = 0;
    int str_len = strlen(str);
    int word_len = strlen(word);

    int i, j;
    for (i = 0; i < str_len - word_len + 1; i++) {
        count = 0;
        for (j = 0; j < word_len; j++) {

            if (str[i + j] == word[j]) {
                count++;
            } else {
                break;
            }
        }
        if (count == word_len) {
            return 1;
        }
    }

    return 0;
}
