#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * 1. Get the string -- CHECK
 * 2. Split it in a words -- CHECK
 * 3. Check if words are palindromes -- CHECK
 * 4. Add them in an array if they are not already in it -- CHECK
 * 5. Sort the array -- CHECK
 *      a. make strings to lower case -- CHECK
 *      b. compare them -- CHECK
 *      c. return new array -- CHECK
 * 6. Print it -- CHECK
 */

int find_palindromes(char**, char*, size_t);
int check_palindrome(char*, int);
int check_exist(char**, size_t, char*);

void sort_array(char**, size_t);
char* str_to_lower(char* str, size_t size);
void print_palindromes(char**, size_t);

int main() {
    char* text = NULL;
    size_t size = 0;
    int input_length = getline(&text, &size, stdin);
    text[input_length - 1] = '\0';
    char **palindromes = calloc(input_length, sizeof (char*));
    size_t pal_count = find_palindromes(palindromes, text, input_length);
    sort_array(palindromes, pal_count);
    print_palindromes(palindromes, pal_count);

    free(palindromes);
    free(text);
    return 0;
}

int find_palindromes(char** palindromes, char* input, size_t input_len) {
    int i, pal_count = 0, current_count = 0, in_a_word = 0;
    char* tmp_word = calloc(input_len + 1, sizeof (char*));
    if (tmp_word == NULL) {
        printf("Unable to allocate memory.");
        exit(1);
    }
    for (i = 0; i <= input_len; i++) {
        char ch = input[i];
        if (ch == '\0' || !isalpha(ch)) {
            if (in_a_word) {
                tmp_word[current_count] = '\0';
                int is_palindrome = check_palindrome(tmp_word, current_count);
                if (is_palindrome) {
                    palindromes[pal_count] = calloc(input_len + 1, sizeof (char*));
                    size_t len = strlen(tmp_word);
                    if (check_exist(palindromes, pal_count, tmp_word) == 0) {
                        memcpy(palindromes[pal_count], tmp_word, len);
                        palindromes[pal_count][len] = '\0';
                        pal_count++;
                    } else {
                        free(palindromes[pal_count]);
                    }

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

    return pal_count;
}

int check_palindrome(char* str, int size) {
    int i, is_palindrome = 1;
    for (i = 0; i < size / 2; i++) {
        if (str[i] != str[size - 1 - i]) {
            is_palindrome = 0;
            break;
        }
    }
    return is_palindrome;
}

int check_exist(char** palindromes, size_t size, char* checkword) {
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(palindromes[i], checkword) == 0) {
            return 1;
        }
    }
    return 0;
}

void sort_array(char** arr, size_t size) {
    int i, swapped = 1;
    while (swapped) {
        swapped = 0;

        for (i = 0; i < size - 1; i++) {

            size_t a_len = strlen(arr[i]);
            char* a = str_to_lower(arr[i], a_len);
            size_t b_len = strlen(arr[i]);
            char* b = str_to_lower(arr[i + 1], b_len);
            
            if (strcmp(a, b) > 0) {
                char* tmp = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = tmp;
                swapped = 1;
            }
            
            free(a);
            free(b);
        }
    }

}

char *str_to_lower(char *str, size_t size) {
    int i;
    char* result = calloc(size + 1, sizeof(char));
    if(!result){
        printf("Cannot allocate memory..");
        exit(1);
    }
    for (i = 0; i < size; i++) {
        result[i] = tolower(str[i]);
    }
    result[i] = '\0';
    
    return result;
}

void print_palindromes(char** palindromes, size_t palindromes_count) {
    int i;
    for (i = 0; i < palindromes_count; i++) {
        if (i == 0) {
            printf("%s", palindromes[i]);
        } else {
            printf(", %s", palindromes[i]);
        }
    }
}

