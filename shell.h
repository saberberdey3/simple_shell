#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>

/* Constants */
#define EXTERNAL_COMMAND 1
#define INTERNAL_COMMAND 2
#define PATH_COMMAND 3
#define INVALID_COMMAND -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 * Struct command_map - a struct that maps a command name to a function
 *
 * @command_name: name of the command
 * @function: the function that executes the command
 */
typedef struct command_map {
    char *command_name;
    void (*function)(char **command);
} command_map;

extern char **environ;
extern char *line;
extern char **commands;
extern char *shell_name;
extern int status;

/* Helpers */
void print_message(char *message, int length);
char **tokenize_string(char *string, char *delimiter);
void remove_newline_character(char *string);
int string_length(char *string);
void copy_string(char *destination, char *source);

/* Helpers2 */
int compare_strings(char *string1, char *string2);
char *concatenate_strings(char *string1, char *string2);
int string_span(char *string, char *charset);
int string_cspan(char *string, char *charset);
char *find_character(char *string, char character);

/* Helpers3 */
char *tokenize_string_r(char *string, char *delimiter, char **save_pointer);
int string_to_integer(char *string);
void *reallocate_memory(void *pointer, unsigned int old_size, unsigned int new_size);
void ctrl_c_handler(int signal);
void remove_comments(char *string);

/* Utilities */
int parse_command(char *command);
void execute_command(char **command, int type);
char *find_command_path(char *command);
void (*get_function(char *command))(char **);
char *get_environment_variable(char *variable_name);

/* Built-in Commands */
void display_environment(char **command);
void quit_shell(char **command);

/* Main */
extern void run_shell_non_interactively(void);
extern void initialize_shell(char **current_command, int type_command);

#endif /* SHELL_H */
