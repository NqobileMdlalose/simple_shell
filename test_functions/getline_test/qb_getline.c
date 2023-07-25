#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stddef.h>
#include "qbshell.h"

#define BUFFER_SIZE 1024


int qb_getline(char** line, size_t* len, FILE* stream) 
{
    /*Ensure that line and len are valid pointers */ 
    if (line == NULL || len == NULL) {
        return -1;
    }

    ssize_t chars_read = getline(line, len, stream);
    if (chars_read == -1) {
        perror("Error reading input");
        return -1;
    }

    return chars_read;
}