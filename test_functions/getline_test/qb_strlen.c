#include "qbshell.h"
#include <stddef.h>

/**
 * qb_strlen - functions gets the length of a string.
 * @string: This is the string arguement
 * Return: (length) - function will return the length of the string
 */

int qb_strlen(const char *string)
{
int length = 0;
for (length = 0; *string != '\0'; ++string)
{
	++length;
}
return (length);
}