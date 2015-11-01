#include <stdio.h>
#include <stdlib.h>

int main() {
    int arr[] = {1, 3, 5, 6, -10, 33, 4};
    int size = sizeof (arr) / sizeof (int);
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", *(arr + i));

    }

    return 0;
}
