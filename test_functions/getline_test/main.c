#include <stdio.h>
#include <stdlib.h>
#include "qbshell.h" 

#include <stdio.h>
#include <stdlib.h>

int qb_getline(char** line, size_t* len, FILE* stream);

int main() {
    char* line = NULL;
    size_t len = 0;
    ssize_t chars_read;

    printf("Enter a line of text (press Ctrl+D to exit):\n");

    while ((chars_read = qb_getline(&line, &len, stdin)) != -1) {
        printf("You entered: %s", line);

    
        free(line);
        line = NULL;
        len = 0;
    }

    return 0;
}