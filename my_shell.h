#ifndef MY_SHELL_H
#define MY_SHELL_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* Modes */
void my_interactive_mode(void);
void my_non_interactive_mode(void);

/* Macros */
extern char **environ;
#define MAX_NUM 10
#define MAX_LENGHT 256
#define BUFFER_SIZE 1024

/* Prototypes */
char *my_read_stdin(void);
char *my_read_stream(void);
char **my_tokeniz(char *line);
int my_executcmd(char **cmd);
void my_errors(char *s);
char *my_strdup(char *s);
int my_strlen(const char *s);
int my_strncmp(const char *str1, const char *str2, int n);
char *my_getenv(const char *name);
void my_error(int status, char **s, int running);
void my_itoa(int num, char *str);
char *my_strcat(char *dest, char *src);
int my_end(char **cmd);
char *my_strcpy(char *dest, char *src);
int my_env(char **cmd);
char *my_strtok(char *str, char *delim);

/* Structures */
/**
 * struct built - structure for builtins.
 * @name: name of the builtin.
 * @f: function prototype.
 */
typedef struct built
{
	char *name;
	int (*f)(char **);
} built_in;

#endif
