#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NUMBER_SIZE 2
#define MAX_MESSAGE_SIZE 100

void int_to_bin(unsigned int n, char* buffer);
int main(int argc, char** argv) {
    char n[MAX_NUMBER_SIZE + 2];
    fgets(n, MAX_NUMBER_SIZE + 2, stdin);
    int base = atoi(n);
    
    char str[MAX_MESSAGE_SIZE + 2];
    fgets(str, MAX_MESSAGE_SIZE + 2, stdin);
    int len = strlen(str);
    if(str[len-1] == '\n'){
        str[len-1] = '\0';
    }
    
    unsigned int sum = 0;
   
    int i;
    for (i = 0; i < len; i++) {
        char ch = tolower(str[i]);
        if(isalpha(ch)){
             sum+=ch-96;
        }
        else {
            sum+= ch;
        }
    }
    i = 0;
    char digits[33];
    int reminder;
    while(sum > 0){
        reminder = sum % base;
        digits[i] = reminder;
        sum = sum / base;
        i++;
    }
    printf("%d", base);
    printf("%lu", strlen(str));
    
    i--;
    while (i >= 0)
    {
        printf("%d", digits[i]);
        i--;
    }

    return (EXIT_SUCCESS);
}
