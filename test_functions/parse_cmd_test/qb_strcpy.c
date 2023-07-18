#include "main.h"
#include <string.h>

/**
 * qb_strcpy - This fucntions copies a string from @src to @dest
 * @dest: This is a pointer to the destination buffer
 * @src: This is a pointer to the string source
 * Return: This is a pointer
 */

char *qb_strcpy(char *dest, const char *src)
{
	char *dest_start = dest;

	while ((*dest++ = *src++))
		;
	return (dest_start);
}
