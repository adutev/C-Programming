#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void string_to_lower_case(char*, int);

int main() {
    char *string;
    char *substring;
    size_t buff_size = 1024;
    int words_found = 0;

    string = (char *) malloc(buff_size * sizeof (char));
    if (string == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    substring = (char *) malloc(buff_size * sizeof (char));
    if (substring == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    getline(&string, &buff_size, stdin);
    int str_len = strlen(string);
    string_to_lower_case(string, str_len);

    getline(&substring, &buff_size, stdin);
    int substr_len = strlen(substring);
    string_to_lower_case(substring, substr_len);

    int len1 = strlen(string);
    int len2 = strlen(substring);

    int i, hasSubstring = 0;
    for (i = 0; i < len1; i++) {
        if (string[i] == substring[0]) {
            int j;
            for (j = 0; j < len2 - 1; j++) {
                if (string[i + j] != substring[j]) {
                    hasSubstring = 0;
                    break;
                }
                hasSubstring = 1;
            }
            if (hasSubstring) {
                words_found++;
            }
        }
    }

    printf("%d", words_found);
    free(string);
    free(substring);
    return 0;
}

void string_to_lower_case(char* str, int size) {
    int i;
    for (i = 0; i < size; i++) {
        str[i] = tolower(str[i]);
    }
}