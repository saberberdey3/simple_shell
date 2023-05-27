#include "shell.h"

/* by SN */

/**
 * tokenizer - Tokenizes input and stores it into an array.
 * @input_string: Input to be parsed.
 * @delim: Delimiter to be used (a single character string).
 *
 * Return: Array of tokens.
 */
char **tokenizer(char *input_string, char *delim)
{
	int num_delim = 0;
	char **av = NULL;
	char *token = NULL;
	char *save_ptr = NULL;

	token = _strtok_r(input_string, delim, &save_ptr);

	while (token != NULL)
	{
		av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
		av[num_delim] = token;
		token = _strtok_r(NULL, delim, &save_ptr);
		num_delim++;
	}

	av = _realloc(av, sizeof(*av) * num_delim, sizeof(*av) * (num_delim + 1));
	av[num_delim] = NULL;

	return (av);
}

/**
 * print - Prints a string to stdout.
 * @string: String to be printed.
 * @stream: Stream to print out to.
 *
 * Return: void (no return value).
 */
void print(char *string, int stream)
{
	int i = 0;

	for (; string[i] != '\0'; i++)
		write(stream, &string[i], 1);
}

/**
 * remove_newline - Removes newline from a string.
 * @str: String to be modified.
 *
 * Return: void (no return value).
 */
void remove_newline(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}

/**
 * _strcpy - Copies a string to another buffer.
 * @source: Source to copy from.
 * @dest: Destination to copy to.
 *
 * Return: void (no return value).
 */
void _strcpy(char *source, char *dest)
{
	int i = 0;

	for (; source[i] != '\0'; i++)
		dest[i] = source[i];
	dest[i] = '\0';
}

/**
 * _strlen - Counts string length.
 * @string: String to be counted.
 *
 * Return: Length of the string.
 */
int _strlen(char *string)
{
	int len = 0;

	if (string == NULL)
		return (len);
	for (; string[len] != '\0'; len++)
		;

	return (len);
}
