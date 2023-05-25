#include "my_shell.h"

/**
* main - Entry Point.
*
* by Saber&Nissrin
*
* Return: 0 always Success.
*/
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		my_intercative_mode(void);
	}
	else
	{
		my_non_interactive_mode(void);
	}
	return (0);
}
