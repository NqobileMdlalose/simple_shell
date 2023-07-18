#include <stdio.h>
#include <stdlib.h>
#include "qbshell.h"

int main(void)
{
    char *args[] = {"exit", "42"};

    qb_exit(args);
    return (0);
}
