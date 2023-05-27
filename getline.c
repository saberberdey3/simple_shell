#include "shell.h"

/**
 * custom_getline - reads a line of input from stdin
 * @line: pointer to store the read line
 *
 * Return: number of characters read (including newline), or -1 on failure
 */
ssize_t custom_getline(char **line)
{
    static char buffer[READ_BUF_SIZE];
    static size_t buffer_index = 0;
    static ssize_t buffer_size = 0;

    ssize_t line_length = 0;

    if (line == NULL)
        return -1;

    if (buffer_index >= (size_t)buffer_size) {
        buffer_size = read(STDIN_FILENO, buffer, READ_BUF_SIZE);
        if (buffer_size < 0)
            return buffer_size;
        buffer_index = 0;
    }

    while (buffer_index < (size_t)buffer_size) {
        if (buffer[buffer_index] == '\n') {
            (*line) = malloc((line_length + 1) * sizeof(char));
            if ((*line) == NULL)
                return -1;
            memcpy((*line), buffer, line_length);
            (*line)[line_length] = '\0';
            buffer_index++;
            return line_length;
        }
        line_length++;
        buffer_index++;
    }

    return line_length;
}

