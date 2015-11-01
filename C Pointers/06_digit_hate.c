#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* digit_replacement(char*, size_t, int*);
void print_result(char*, int);

int main() {
    char* new_str;
    char* str; // = "The Cold War is believed to be between the period 1947-1999.";
    int replacement_count = 0;
    size_t s = 0;
    getline(&str, &s, stdin);
    int size = strlen(str);

    printf("Original string is:\n%s\n", str);



    new_str = digit_replacement(str, size, &replacement_count);
    print_result(new_str, replacement_count);

    free(new_str);

    return 0;
}

char* digit_replacement(char* original, size_t size, int* count) {
    char* result_string = malloc(size * sizeof (char));
    int i = 0;
    while (*(original + i) != '\0') {
        char ch = *(original + i);
        if (ch >= '0' && ch <= '9') {
            ch = '/';
            *(count) += 1;
        }
        *(result_string + i) = ch;
        i++;
    }

    return result_string;
}

void print_result(char* str, int count) {
    int i = 0;
    printf("New string becomes:\n");
    while (*(str + i) != '\0') {
        printf("%c", *(str + i));
        i++;
    }
    printf("\nNumber of replacements: %d", count);
}