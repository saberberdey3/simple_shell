#include "my_shell.h"

/**
 * my_non_interactive_mode - runs the program in non-interactive mode.
 */
void my_non_interactive_mode(void)
{
	char *line;
	char **cmds;
	int err_check = 0;
	int running = 1;

	while (1)
	{
		line = my_read_stream();
		cmds = my_tokeniz(line);
		err_check = my_executcmd(cmds);
		if (err_check > 0)
		{
			my_error(err_check, cmds, running);
		}
		free(line);
		free(cmds);
	}
}

int main(void)
{
	my_non_interactive_mode();
	return 0;
}
