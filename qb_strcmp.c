#include <stdio.h>
#include "qbshell.h"

/**
 * qb_strcmp - compares two strings
 * @str1: string 1
 * @str2: string 2
 * Return: integer
 */
int qb_strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
