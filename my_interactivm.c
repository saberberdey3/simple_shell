#include "my_shell.h"

/**
 * signal_handler - function that handles terminal signals.
 * @signal_num: signal number.
 */
void signal_handler(int signal_num)
{
	(void)signal_num;
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, "#ShellSN$ ", 10);
}

/**
 * my_interactive_mode - the program in interactive mode.
 *
 * This function handles the interactive mode of the shell. It
 * continuously prompts the user for input and executes the
 * commands that the user enters.
 */
void my_interactive_mode(void)
{
char *line;
char **cmds;
int err_check = 0;
int running = 1;

	signal(SIGINT, signal_handler);
	while (running)
	{
		write(STDOUT_FILENO, "#ShellSN$ ", 10);
		line = read_stdin();
		if (line != NULL)
		{
		cmds = tokeniz(line);
		err_check = executcmd(cmds);
		if (err_check > 0)
		{
		error(err_check, cmds, running);
		}
		free(line);
		free(cmds);
	}
	running++;
	}
	free(line);
}
