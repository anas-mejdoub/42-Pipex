/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:32:23 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/10 17:49:45 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int count_word(char *str)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] !=  ' ' && str[i])
        {
            count++;
            if (str[i] == 39)
            {
                i++;
                while (str[i] && str[i] != 39)
                {
                    if (str[i] == 92 && str[i + 1] == 39)
                        i+=2;
					else
						i++;
                }
                i++;
            }
            else
            {
                while(str[i] !=  ' ' && str[i])
                    i++;
            }
        }
    }
    return (count);
}

int find_char(char *str, char c, int i)
{

	while (str[i])
	{
		if (str[i] == c && str[i - 1] != 92)
			return (i);
		i++;
	}
	return (-1);
}
int containsSingleQ(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == 39 && str[i - 1] != 92)
			count++;
		i++;
	}
	return (count);
}
char	*ft_strtrim2(char *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	y;

	if (!s1 || !set)
		return (free(s1), NULL);
	y = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
		i++;
	while (y > 0 && ft_strchr(set, s1[y - 1]) != NULL)
    {
        if (s1[y - 1] == 39)
        {
            y--;
            break;
        }
		--y;
    }
	if (i >= y)
		return (free(s1), ft_strdup(""));
	res = ft_substr(s1, i, y - i);
	free(s1);
	return (res);
}
char **singleQuoteHandle(char *str)
{
	int		i;
	char	**res;
	int		j;
    int temp;
	int f;

	f = 0;
	i = 0;
    temp = 0;
	j = 0;
    res = malloc((count_word(str) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] == 39 && str[i - 1] != 92)
		{
			res[j] = ft_strtrim2(ft_substr(str, temp, find_char(str, '\'', i + 1) - i + 1), "' ");
			i = find_char(str, '\'', i + 1);
            temp = i + 1;
			j++;
			f = 1;
		}
		else if (str[i] == ' ')
		{
			if (!f)
			{
				res[j] = ft_substr(str, temp, i - temp);
				j++;
				temp = i + 1;
			}
			f = 0;
		}
		i++;
	}
	return (res[j] = NULL, res);
}

int checker_(char *command)
{
	return (command[0] == '/' || command[0] == '.');
}
void free2d(char **res)
{
	int	i;

	i = 0;
	if (res != NULL)
	{
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
	}
}
char *find_path(char *command, char *envp)
{
		char	**paths;
		int		i;
		char	*res;

		i = 0;
		res = NULL;
		paths = ft_split(envp, ':');
		free(envp);
		if (checker_(command))
			return (command);
		while (paths[i])
		{
			paths[i] = ft_strjoin2(paths[i], "/");
			i++;
		}
		i = 0;
		while(paths[i] != NULL)
		{
			free(res);
			res = ft_strjoin(paths[i], command);
			if (access(res, F_OK) == 0)
				return (free2d(paths), res);
			i++;
		}
		return (NULL);
}
void	exit_error(char *str, int n)
{
	perror(str);
	exit(n);
}
char *get_env(char *envp[])
{
	while(*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			return (ft_substr(*envp, 6, ft_strlen(*envp) - 6));
		envp++;
	}
	return (NULL);
}
char **optionSplit(char *str)
{
	if (containsSingleQ(str) > 1)
		return (singleQuoteHandle(str));
	else
		return (ft_split(str, ' '));
	return (NULL);
}
void start_pipe(int fdin, int fd)
{
	dup2(fdin, STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
}
void middle_pipe(int fd1, int fd2)
{
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
}
void last_pipe(int fdout, int fd1)
{
	dup2(fd1, STDIN_FILENO);
	dup2(fdout, STDOUT_FILENO);
}
pid_t smart_fork()
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(-1);
	}
	else
		return (pid);
}




void close_fd(int **fd, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		close(fd[i][0]);
		close(fd[i][1]);
		i++;
	}
}
int **malloc_2d(int **fd, int rows)
{
	int	i;

	i = 0;
	fd = malloc(rows * sizeof(int *));
	if (fd == NULL)
		return (NULL);
	while (i < rows)
	{
		fd[i] = malloc(2 * sizeof(int));
		if (fd[i] == NULL)
			return (NULL);
		i++;
	}
	return (fd);
}
int *malloc_int_arr(int *fd, int n)
{
	fd = malloc(n * sizeof(int));
	if (fd == NULL)
		return (NULL);
	return (fd);
}
void smart_pipe(int **fd, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = pipe(fd[i]);
		if (j == -1)
			exit_error("PIPE", 1);
		i++;
	}
}
void pipes_level(int argc, int i, variables var ,commands_ command, char *envp[])
{
	if (i == 2)
		start_pipe(var.fdin, var.fd[i - 2][1]);
	else if (i < argc - 2)
		middle_pipe(var.fd[i - 3][0], var.fd[i - 2][1]);
	else
		last_pipe(var.fdout, var.fd[i - 3][0]);
	close_fd(var.fd, argc - 4);
	if (execve(command.path, command.command_args, envp) == -1)
				exit_error(command.command_args[0], 127);
}
void parent_helper(variables var, int argc, int *status)
{
	int	i;

	close_fd(var.fd, argc - 4);
	i = 0;
	while (i < argc - 3)
	{
		waitpid(var.pids[i], status, 0);
		i++;
	}
}
int helper_function(variables var, int argc, char  *argv[], char *envp[])
{
	commands_ command;
	int		i;
	int		status;

	i = 2;
	command.command_args = NULL;
	command.path = NULL;
	while (i < argc - 1)
	{
		free2d(command.command_args);
		free(command.path);
		command.command_args = optionSplit((char *)argv[i]);
		command.path = find_path(command.command_args[0], get_env(envp));
		var.pid = fork();
		if (var.pid == -1)
			perror("FORK ");
		if (var.pid == 0)
			pipes_level(argc, i, var, command, envp);
		else
			var.pids[i - 2] = var.pid;
		i++;
	}
	if (var.pid > 0)
		parent_helper(var, argc, &status);
	return (status);
}

int main(int argc, char  *argv[], char *envp[])
{
		int		status;
		variables var;
		
		if (argc >= 4)
		{
			var.fd = malloc_2d(var.fd, argc - 4);
			var.pids = malloc_int_arr(var.pids, argc - 3);
			var.fdout = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
			var.fdin = open(argv[1], O_RDWR);
			if (var.fdout == -1 || var.fdin == -1)
				exit_error("FILE", 1);
			smart_pipe(var.fd, argc - 4);
			status = helper_function(var, argc, argv, envp);
		}
	return (WEXITSTATUS(status));
}
