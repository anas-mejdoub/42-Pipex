#ifndef PIPEX_H
#define PIPEX_H
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include <errno.h>

typedef struct s_variables
{
	int fdin;
	int fdout;
	int **fd;
	int *pids;
	pid_t pid;
} variables;

typedef struct s_commands_variables
{
  	char	*path;
	char	**command_args;
} commands_;
int count_word(char *str);
int find_char(char *str, char c, int i);
int containsSingleQ(char *str);
char	*ft_strtrim2(char *s1, char const *set);
char **singleQuoteHandle(char *str);
int checker_(char *command);
void free2d(char **res);
char *find_path(char *command, char *envp);
void	exit_error(char *str, int n);
char *get_env(char *envp[]);
char **optionSplit(char *str);
void start_pipe(int fdin, int fd);
pid_t smart_fork();
void close_fd(int **fd, int n);
int **malloc_2d(int **fd, int rows);
int *malloc_int_arr(int *fd, int n);
void smart_pipe(int **fd, int n);
void pipes_level(int argc, int i, variables var ,commands_ command, char *envp[]);
void parent_helper(variables var, int argc, int *status);
int helper_function(variables var, int argc, char  *argv[], char *envp[]);
#endif