/* 
 * File:   09_word_count.c
 * Author: Toni
 *
 * Created on November 4, 2015, 3:07 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int wc(char * input, char delimiter);

int main() 
{
    printf("%d\n", wc("Hard Rock, Hallelujah!", ' '));
    printf("%d\n", wc("Hard Rock, Hallelujah!", ','));
    printf("%d\n", wc("Uncle Sam wants you Man   r    ", ' '));
    printf("%d\n", wc("Beat the beat!", '!'));
    
    return 0;
}

int wc(char * input, char delimiter)
{
    size_t count = 1;
    
    while(*(input)!='\0'){
        if(*input == delimiter && *(input+1) != '\0' && *(input+1) != delimiter){
            count++;
        }
        input++;
    }
    
    return count;
}