#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *string;
    size_t buff_size = 1024;
    size_t line_count;
    string = (char *) malloc(buff_size * sizeof (char));
    if (string == NULL) {
        perror("Unable to allocate buffer");
        exit(1);
    }

    printf("Type a string, followed with new line:\n");
    line_count = getline(&string, &buff_size, stdin);
    if (line_count == -1) {
        printf("Failed Reading an input.");
        return 1;
    }
    size_t str_len = strlen(string);

    int i;
    for (i = 1; i < str_len; i++) {
        if(string[i] != string[i -1]){
            printf("%c", string[i-1]);
        }
    }


    return 0;
}



