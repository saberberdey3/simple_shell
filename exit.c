#include "shell.h"

/* ... */

/**
 * builtin_exit - built-in command to exit the shell
 * @command: array of command arguments
 */
void builtin_exit(char **command)
{
    int status = 0;

    if (command[1] != NULL)
        status = _atoi(command[1]);

    exit(status);
}

/* ... */

int main(void)
{
    /* ... */

    /* Create a mapping for the "exit" command */
    function_map exit_map = {"exit", builtin_exit};

    /* ... */

    while (1)
    {
        /* ... */

        if (parse_command(line) == INTERNAL_COMMAND)
        {
            /* ... */

            /* Check if the command is the "exit" command */
            if (_strcmp(commands[0], exit_map.command_name) == 0)
            {
                /* Call the function associated with the "exit" command */
                exit_map.func(commands);

                /* The shell will exit if the "exit" command is executed */
            }

            /* ... */
        }
        else
        {
            /* ... */
        }

        /* ... */
    }

    /* ... */
}
