#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * 1. Get the string -- CHECK
 * 2. Split it in a words
 * 3. Check if words are palindromes
 * 4. Add them in an array if they are not already in it
 * 5. Sort the array
 *      a. make strings to lower case
 *      b. compare them
 *      c. return new array
 * 6. Print it
 */ 

int check_palindrome(char*, int);
int find_palindromes(char**, char*, size_t);
int check_exist(char**, size_t, char*);
void sort_array(char**, size_t);
char* str_to_lower(char* str, size_t size);
void print_palindromes(char**, size_t);

int main() {
    char* text = NULL;
    size_t size = 0;
    int input_length = getline(&text, &size, stdin);
    text[input_length - 1] = '\0';
    char **palindromes = calloc(input_length, sizeof(char*));
    find_palindromes(palindromes, text, input_length);
    
    free(palindromes);
    free(text);
    return 0;
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

int find_palindromes(char** palindromes, char* input, size_t input_len) {
    int i, pal_count = 0, current_count = 0, in_a_word = 0;
    char* tmp_word = calloc(input_len + 1, sizeof(char*));
    if(tmp_word == NULL){
       printf("Unable to allocate memory.");
       exit(1);
    }
    for (i = 0; i <= input_len; i++) {
        char ch = input[i];
        if(ch == '\0' || !isalpha(ch)){
            if(in_a_word){
                tmp_word[current_count] = '\0';
                printf("%s\n",tmp_word);
                in_a_word = 0;
            }
            current_count = 0;
        } else {
            if(!in_a_word) {
                in_a_word = 1;
            }
            tmp_word[current_count++] = ch;
            pal_count++;
        }
    }
    free(tmp_word);
}

void sort_array(char** arr, size_t size) {
   
}

char *str_to_lower(char *str, size_t size) {
    
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

int check_exist(char** palindromes, size_t size, char* to_check){
}