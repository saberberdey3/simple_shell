#include "shell.h"

/**
 * env - prints the current environment
 * @tokenized_command: command entered
 *
 * Return: void
 */
void env(char **tokenized_command __attribute__((unused))) 
{
int i;

for (i = 0; environ[i] != NULL; i++) {
printf("%s\n", environ[i]);
}
}

/**
 * quit - exits the shell
 * @tokenized_command: command entered
 *
 * Return: void
 */
void quit(char **tokenized_command)
{
int num_token = 0, arg;

	for (; tokenized_command[num_token] != NULL; num_token++)
	;
	if (num_token == 1)
{
free(tokenized_command);
exit(status);
}
	else if (num_token == 2)
	{
	arg = atoi(tokenized_command[1]);
	if (arg == -1)
	{
	printf("%s: 1: exit: Illegal number: %s\n", shell_name, tokenized_command[1]);
	status = 2;
	}
	else
	{
	exit(arg);
	}
	}
else
{
	printf("$: exit doesn't take more than one argument\n");
	}
}
