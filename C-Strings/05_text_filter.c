#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char* banned_words = NULL;
    size_t size = 0;
    getline(&banned_words, &size,stdin);
    int banned_words_length = strlen(banned_words);
    banned_words[banned_words_length - 1] = '\0';
    
    char* text = NULL;
    getline(&text, &size,stdin);
    int text_length = strlen(text);
    text[text_length - 1] = '\0';
    
    char* token = strtok(banned_words, ", ");
    while(token != NULL){
        char* occurrence = strstr(text, token);
        while(occurrence){
            int index = occurrence - text;
            memset(&text[index], '*', strlen(token));
            occurrence = strstr(&text[index + 1], token);
        }
        token = strtok(NULL, ", ");
    }
    
    printf("%s",text);
    free(banned_words);
    free(text);
    return 0;
}