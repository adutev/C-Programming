#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void slice(const char *sourceFile, const char *destinationFile, size_t parts);
int kill(const char*);

int main(int argc, char** argv) {
    size_t size = 5;
    FILE *src_file = fopen("picture.jpg", "r");
    if (!src_file) {
        kill("No such source file");
    }
    fseek(src_file, 0, SEEK_END);
    unsigned long src_len = ftell(src_file);
    fseek(src_file, 0, SEEK_SET);
    unsigned long parts_size = src_len / size;
    char buffer[4096];
    
    int i;
    for (i = 0; i < size; i++) {
        char name[30];
        sprintf(name, "file-%d.part", i + 1);

        FILE* curr_file = fopen(name, "w");        
        size_t written_bytes = 0;
        while (!feof(src_file) && written_bytes <= parts_size) {
            
            size_t read_bytes = fread(buffer, 1, 4096, src_file);
            fwrite(buffer, 1, read_bytes, curr_file);
            written_bytes += read_bytes;
        }
        fclose(curr_file);
    }
    fclose(src_file);
    
    char* files[5] = {"file-1.part", "file-2.part","file-3.part","file-4.part","file-5.part"};
    FILE* dest_file = fopen("new-picture.jpg", "w");
    for(i = 0; i < size; i++){
        FILE* curr_file = fopen(files[i], "r");        
        size_t written_bytes = 0;
        while(!feof(curr_file) && written_bytes <= parts_size ){
            int read_bytes = fread(buffer, 1, 4096, curr_file);
            fwrite(buffer, 1, read_bytes, dest_file);
            written_bytes += read_bytes;
        }        
        fclose(curr_file);
    }
    fclose(dest_file);
    return 0;
}

void slice(const char *sourceFile, const char *destinationFile, size_t parts) {
    int i;
    for (i = 0; i < parts; i++) {
    }
}

int kill(const char* msg) {
    if (errno) {
        perror(msg);
    } else {
        fprintf(stderr, "%s\n", msg);
    }

    FILE *log_file = fopen("log.txt", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", msg);
    }
    exit(1);
}