#include "my_shell.h"

/**
 * non_interactive_mode - the program in the non interactive mode.
 *
 * This function handles the non-interactive mode of the shell. It
 * takes a stream of input and executes the commands that are
 * found in the stream.
 */
void my_non_interactive_mode(void)
{
char *line;
char **cmds;
int err_check = 0;

	while (1)
	{
	line = read_stream();
	cmds = tokeniz(line);
	err_check = executcmd(cmds);
	if (err_check > 0)
	{
	error(err_check, cmds, running);
	}
}
free(line);
free(cmds);
}
