#include "shell.h"

/* by SN */

/**
 * initializer - Starts executing the command.
 * @current_command: Current command token.
 * @type_command: Parsed command type.
 *
 * Return: void (no return value).
 */
void initializer(char **current_command, int type_command)
{
	pid_t PID;

	if (type_command == EXTERNAL_COMMAND || type_command == PATH_COMMAND)
	{
	PID = fork();
	if (PID == 0)
		execute_command(current_command, type_command);
	else
	{
		waitpid(PID, &status, 0);
		status >>= 8;
	}
	}
	else
	execute_command(current_command, type_command);
}
