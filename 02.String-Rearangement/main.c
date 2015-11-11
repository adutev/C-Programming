#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 64

size_t read_line(char **line, size_t *size);
void get_string(char* str, char* input);
int check_command(char*);

int main(int argc, char** argv) {
    char* input = NULL;
    size_t size = 0;
    read_line(&input, &size);

    size_t len = strlen(input);
    char* str = (char) malloc(len);
    if (!str) {
        return 1;
    }
    get_string(str, input);
    if (!str) {
        return 1;
    }
    size_t str_len = strlen(str);
    
    read_line(&input, &size);
    while (strcmp(input, "end") != 0) {
        strtok(input," ");
        int first_pos = atoi(strtok(NULL, " ")); 
        int second_pos = atoi(strtok(NULL, " ")); 
        int bytes_to_swap = atoi(strtok(NULL, " "));
        
        int check_first = first_pos >= 0 && first_pos + bytes_to_swap <  str_len; 
        int check_second = second_pos >= 0 && second_pos + bytes_to_swap <  str_len;
        int check_bytes_toswap = bytes_to_swap >= 0;
        
        if(check_bytes_toswap && check_first && check_second) {
            char tmp[bytes_to_swap];
            strncpy(tmp, str + first_pos, bytes_to_swap);
            strncpy(str + first_pos, str+second_pos, bytes_to_swap);
            strncpy(str+second_pos, tmp, bytes_to_swap);
        }
        else
        {
            printf("Invalid command parameters\n");
        }
        read_line(&input, &size);        
    }
    printf("%s", str);
    free(input);
    free(str);

    return 0;
}

size_t read_line(char **line, size_t *size) {
    char *result = *line;
    if (!result) {
        result = (char*) malloc(INITIAL_BUFFER_SIZE);
        if (!result)
            return 0;
    }

    size_t index = 0;
    size_t currentSize = INITIAL_BUFFER_SIZE;
    char ch = getchar();
    while (ch != '\n' && ch != EOF) {
        if (index == currentSize - 1) {
            char *resized = (char*) realloc(result, currentSize * 2);
            if (!resized)
                return 0;
            result = resized;
            currentSize *= 2;
        }
        result[index] = ch;
        index++;
        ch = getchar();
    }

    result[index] = '\0';
    *line = result;
    *size = currentSize;

    return index - 1;
}

void get_string(char* str, char* input) {
    int count = 0;
    char* token = strtok(input, "|");
    while (token != NULL) {
        char* start;
        char* end;
        if ((start = strchr(token, '{')) && (end = strchr(start + 1, '}'))) {
            int i;
            int len = end - start;
            for (i = 1; i < len; i++) {
                str[count++] = start[i];
            }
            str[count] = '\0';
        }
        token = strtok(NULL, "|");
    }
}
