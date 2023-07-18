#include "qbshell.h"
#include <stdio.h>

/**
 * qb_atoi - conversts the second argument to an integer
 * @str: string
 * Return: integer
 */
int qb_atoi(const char *str)
{
	int res = 0;
	int sign = 1;
	int ans;

	while (*str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= 9)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	ans = res * sign;
	return (ans);
}
