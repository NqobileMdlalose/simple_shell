#include "qbshell.h"
#include <stdio.h>

/**
 * qb_strchr - iterates through the string until it finds the charactor
 * @str: sting
 * @chr: charactor
 * Return: charactor
 */
char *qb_strchr(char *str, int chr)
{
	while (*str != '\0')
	{
		if (*str == chr)
			return (str);
		str++;
	}
	return (NULL);
}
