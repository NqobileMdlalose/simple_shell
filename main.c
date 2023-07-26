#include "qbshell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc >= 2)
		handle_non_interactive(argv, argc);
	else
		run_shell(argc, argv);
	return (0);
}
