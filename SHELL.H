#ifndef SHELL_H
#define SHELL_H

/*
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
*/

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <string.h>


#define USE_GETLINE 0
#define USE_STRTOK 0

#define CMD_NORM        0
#define CMD_OR          1
#define CMD_AND         2
#define CMD_CHAIN       3

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2


#define HIST_FILE	"simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * struct liststr --- individual linked list.
 * @num: the field of nmbr.
 * @str: A string.
 * @next: indicates the following node.
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_x;

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * struct passinfo --- incorporates fictitious arguments to enter a function,
 * enabling a function pointer struct with a standardized prototype.
 * @arg: a string produced by getline that contains arguments.
 * @argv:a string array produced using arg.
 * @path: a route in strings for the active command.
 * @argc: the number of arguments.
 * @line_count: the incorrect count.
 * @err_num: the exit() error code.
 * @linecount_flag: if this line of input is counted.
 * @fname: The name of the program's file.
 * @env: environ is a linked list local copy.
 * @environ: a customized copy of environ derived from LL env.
 * @history: the history node.
 * @alias: the node with the alias.
 * @env_changed: If the environment was altered.
 * @status: The return status of the most recently executed command.
 * @cmd_buf: If chaining, the address of the pointer to cmd_buf.
 * @cmd_buf_type:CMD_category||,&&,;.
 * @readfd: The file descriptor from which to read line input.
 * @histcount: the historical line number count.
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	char **environ;
	list_x *env;
	list_x *history;
	list_x *alias;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} inf_y;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 * Code by: BADAR BENAMI & MANEL KHARBOUT.
 * structbuiltin---There is a built-in string and a related function.
 * @type:builtin command flag.
 * @func:the operation.
 */
typedef struct builtin
{
	char *type;
	int (*func)(inf_y *);
} builtin_table;



int ft_is_cmd(inf_y *, char *);
char *ft_dup_chars(char *, int, int);
char *ft_find_path(inf_y *, char *, char *);

int ft_loophsh(char **);

void ft_errputs(char *);
int ft_errputchar(char);
int ft_putfd(char c, int fd);
int ft_putsfd(char *str, int fd);

int ft_strlen(char *);
int ft_strcmp(char *, char *);
char *ft_starts_with(const char *, const char *);
char *ft_strcat(char *, char *);

char *ft_strcpy(char *, char *);
char *ft_strdup(const char *);
void ft_puts(char *);
int ft_putchar(char);

int ft_hsh(inf_y *, char **);
int ft_find_builtin(inf_y *);
void ft_find_cmd(inf_y *);
void ft_fork_cmd(inf_y *);

char *ft_strncpy(char *, char *, int);
char *ft_strncat(char *, char *, int);
char *ft_strchr(char *, char);

char **ft_strtow(char *, char *);
char **ft_strtow2(char *, char);

char *ft_memset(char *, char, unsigned int);
void ft_ffree(char **);
void *ft_realloc(void *, unsigned int, unsigned int);

int ft_bfree(void **);

int ft_interactive(inf_y *);
int ft_is_delim(char, char *);
int ft_isalpha(int);
int ft_atoi(char *);

int ft_erratoi(char *);
int ft_print_d(int, int);
void ft_print_error(inf_y *, char *);
char *ft_convert_number(long int, int, int);
void ft_remove_comments(char *);

int ft_myexit(inf_y *);
int ft_mycd(inf_y *);
int ft_myhelp(inf_y *);

int ft_myhistory(inf_y *);
int ft_myalias(inf_y *);

ssize_t ft_get_input(inf_y *);
int ft_getline(inf_y *, char **, size_t *);
void ft_sigintHandler(int);

void ft_clear_info(inf_y *);
void ft_set_info(inf_y *, char **);
void ft_free_info(inf_y *, int);

char *ft_getenv(inf_y *, const char *);
int ft_myenv(inf_y *);
int ft_populate_env_list(inf_y *);
int ft_mysetenv(inf_y *);
int ft_myunsetenv(inf_y *);

char **ft_get_environ(inf_y *);
int ft_unsetenv(inf_y *, char *);
int ft_setenv(inf_y *, char *, char *);

int ft_is_chain(inf_y *, char *, size_t *);
void ft_check_chain(inf_y *, char *, size_t *, size_t, size_t);
int ft_replace_alias(inf_y *);
int ft_replace_vars(inf_y *);
int ft_replace_string(char **, char *);

char *ft_get_history_file(inf_y *info);
int ft_write_history(inf_y *info);
int ft_read_history(inf_y *info);
int ft_build_history_list(inf_y *info, char *buff, int count_len);
int ft_renumber_history(inf_y *info);

list_x *ft_add_node(list_x **, const char *, int);
list_x *ft_add_node_end(list_x **, const char *, int);
size_t ft_print_list_str(const list_x *);
int ft_delete_node_at_index(list_x **, unsigned int);
void ft_free_list(list_x **);

size_t ft_list_len(const list_x *);
char **ft_list_to_strings(list_x *);
size_t ft_print_list(const list_x *);
list_x *ft_node_starts_with(list_x *, char *, char);
ssize_t ft_get_node_index(list_x *, list_x *);


#endif
