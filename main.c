#include "qbshell.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */
int main(int argc, char *argv[])
{
	if (argc == 1)
		run_shell(argc, argv);
	else
		handle_non_interactive(argv, argc);
	return (0);
}
