#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    int ch, count = 0;

    FILE *file = fopen("03_line_numbers.c", "r");
    FILE *new_file = fopen("new_file.c", "w+");
    if (file && new_file) {
        fprintf(new_file, "%d ", count);
        while ((ch = fgetc(file)) != EOF) {
            fprintf(new_file, "%c", ch);
            if (ch == '\n') {
                count++;
                fprintf(new_file, "%d ", count);
            }
        }

        fclose(file);
        fclose(new_file);
    } else {
        printf("no such file.");
    }
    return (EXIT_SUCCESS);
}