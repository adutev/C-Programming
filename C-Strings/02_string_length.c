#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *string;
    size_t buff_size = 21;
    size_t line_count;

    string = (char *)malloc(buff_size * sizeof(char));
    if( string == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    
    printf("Type a string, followed with new line:\n");
    line_count = getline(&string, &buff_size, stdin);
    if (line_count == -1) {
        printf("Failed Reading an input.");
        return 1;
    }
    
    size_t string_length = strlen(string);
    int i;
    if(string_length < 21){
        for(i = 0; i < (21 - string_length);i++){
            string[string_length - 1 + i] = '*';
        }
    }
    string = realloc(string, 21);
    string[20] = '\0';
    printf("%s", string);    
    free(string);
    
    return 0;
}



