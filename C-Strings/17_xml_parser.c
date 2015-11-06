/* 
 * File:   17_xml_parser.c
 * Author: Toni
 *
 * Created on November 5, 2015, 1:49 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* extract_xml(char* line);

int main(int argc, char** argv) {
    char* line = NULL;
    size_t size = 0;
    getline(&line, &size, stdin);
    int i;
    for (i = 0; i < 3; i++) {
        char* xml = extract_xml(line);
        if(!xml){
            printf("Invalid data.\n");
        } else{
            printf("%s\n", xml);
        }
        free(xml);
        getline(&line, &size, stdin);
    }
    
    free(line);
    return (EXIT_SUCCESS);
}

char* extract_xml(char* line) {

    char* first_opening = strchr(line, '<');
    if (!first_opening) return NULL;
    char* first_closing = strchr(first_opening + 1, '>');
    if (!first_closing) return NULL;
    char* second_opening = strstr(first_closing + 1, "</");
    if (!second_opening) return NULL;
    char* second_closing = strchr(second_opening + 1, '>');
    if (!second_closing) return NULL;

    char* first_tag = first_opening + 1;
    first_closing[0] = '\0';

    char* second_tag = second_opening + 2;
    second_closing[0] = '\0';

    int equal_tags = (strcmp(first_tag, second_tag) == 0);
    if (!equal_tags) {
        return NULL;
    }
    second_opening[0] = '\0';
    char* data = first_closing + 1;
    first_tag[0] = toupper(first_tag[0]);

    char* result = malloc(strlen(first_tag) + strlen(data) + 3);
    sprintf(result, "%s: %s", first_tag, data);

    return result;

}