#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void dump(void*, size_t, int);
int main() {
    char *text = "I love to break free";
    dump(text, strlen(text) + 1, 5);
    
    int array[] = { 7, 3, 2, 10, -5 };
    size_t size = sizeof(array) / sizeof(int);
    dump(array, size * sizeof(int), 4);

    return 0;
}

void dump(void* ptr, size_t size, int length){
    char* charPtr = ptr;
    int i;
    for (i = 0; i < size; i++) {
        if(i%length == 0){
            printf("\n%p ", (charPtr+i));
        }
        printf("%02hhx ", *(charPtr+i));
    }

}