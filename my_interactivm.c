#include "my_shell.h"

/**
 * signal_handler - function that handles terminal signals.
 * @signal_num: signal number.
 */
void signal_handler(int signal_num)
{
	(void)signal_num;
	write(STDOUT_FILENO, "\n", 2);
	write(STDOUT_FILENO, "#cisfun$ ", 10);
}

/**
 * my_interactive_mode - runs the program in interactive mode.
 */
void my_interactive_mode(void)
{
	char *line;
	char **cmds;
	int err_check = 0;
	int running = 1;

	signal(SIGINT, signal_handler);
	while (1)
	{
		write(STDOUT_FILENO, "#cisfun$ ", 10);
		line = my_read_stdin();
		if (line != NULL)
		{
			cmds = my_tokeniz(line);
			err_check = my_executcmd(cmds);
			if (err_check > 0)
			{
				my_error(err_check, cmds, running);
			}
			free(line);
			free(cmds);
		}
		running++;
	}
}

int main(void)
{
	my_interactive_mode();
	return 0;
}
