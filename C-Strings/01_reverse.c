#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    char *string = malloc(BUFFER_SIZE);
    if(!string) {
        printf("Cannot allocate memory.");
        return 1;
    }
    fgets(string, BUFFER_SIZE, stdin);
    int size = strlen(string);
    int i;
    for (i = 0; i < size /2; i++) {
        char tmp = string[i];
        string[i] = string[size - i -1];
        string[size - i - 1] = tmp;
    }

    printf("%s", string);    
    free(string);
    return 0;
}

