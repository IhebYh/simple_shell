#include "shell.h"
/**
 * main - entry point
 * @argc : int
 * @argv: char
 * Return: int
 */
int main(void)
{
	char *str = NULL;
	size_t count = 0;
	ssize_t gl = 0;

	while (INFINITE_LOOP)
	{
		write(STDOUT_FILENO, "$ ", 2);
		gl = getline(&str, &count, stdin);

		if (gl == EOF)
		{
			free(str);
			exit(0);
		}
		if (_strcmp(str, "\n"))
		{
			cmd_checker(str);
			str = NULL;
		}
		else
		{
			free(str);
			str = NULL;
		}
	}
		return (0);
}
