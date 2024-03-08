/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:32:23 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/08 19:54:26 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include <errno.h>

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
	return (command[0] == '/');
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
void	exit_error(char *str, int n, int i, int argc, char c)
{
	if ((i >= argc - 2 && c == 'P') || (i < argc - 2))
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
int	smart_pipe(int fd[2])
{
	int	res;

	res = pipe(fd);
	if (res == -1)
	{
		perror("pipe");
		exit(-1);
	}
	else
		return (res);
}

void helper_function(int fdin, int fdout, int argc, char  *argv[], char *envp[])
{
	char	*path;
	int		fd[argc - 3][2];
	char	**command_args;
	int		i;
	int		status;
	pid_t	pid;
	
	i = 2;
	command_args = NULL;
	path = NULL;
	while (i < argc - 1)
	{
		smart_pipe(fd[i - 2]);
		free2d(command_args);
		free(path);
		command_args = optionSplit((char *)argv[i]);
		path = find_path(command_args[0], get_env(envp));
		pid = smart_fork();
		if (pid == 0)
		{
			if (i == 2)
				start_pipe(fdin, fd[i - 2][1]);
			else if (i < argc - 2)
				middle_pipe(fd[i - 3][0], fd[i - 2][1]);
			else
				last_pipe(fdout, fd[i - 3][0]);
			if (execve(path, command_args, envp) == -1)
				exit_error(command_args[0], 127, i, argc, 'C');
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, 0);
			if (WEXITSTATUS(status) != 0 && i >= argc - 2)
				exit_error(command_args[0], 127, i, argc, 'P');
		}
		close(fd[i - 2][1]);
		i++;
	}
}
 int main(int argc, char  *argv[], char *envp[])
{
		char	*path;
		int		fd[argc - 3][2];
		int		fdin;
		int		fdout;
		char	**command_args;
		int		i;
		int		status;
		int		j;
		pid_t	pid;

		i = 2;
		command_args = NULL;
		path = NULL;
		if (argc >= 4)
		{
			fdout = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
			fdin = open(argv[1], O_RDWR);
			if (fdout == -1 || fdin == -1)
				exit_error("FILE", 1, i, argc, 'P');
			helper_function(fdin, fdout, argc, argv, envp);
			// while (i < argc - 1)
			// {
			// 	j = pipe(fd[i - 2]);
			// 	free2d(command_args);
			// 	free(path);
			// 	command_args = optionSplit((char *)argv[i]);
			// 	path = find_path(command_args[0], get_env(envp));
			// 	pid = fork();
			// 	if (pid == -1 || j == -1)
			// 		perror("FORK ");
			// 	if (pid == 0)
			// 	{
			// 		if (i == 2)
			// 			start_pipe(fdin, fd[i - 2][1], i);
			// 		else if (i < argc - 2)
			// 			middle_pipe(fd[i - 3][0], fd[i - 2][1]);
			// 		else
			// 			last_pipe(fdout, fd[i - 3][0]);
			// 		if (execve(path, command_args, envp) == -1)
			// 			exit_error(command_args[0], 127, i, argc, 'C');
			// 	}
			// 	else if (pid > 0)
			// 	{
			// 		waitpid(pid, &status, 0);
			// 		if (WEXITSTATUS(status) != 0 && i >= argc - 2)
			// 			exit_error(command_args[0], 127, i, argc, 'P');
			// 	}
			// 	close(fd[i - 2][1]);
			// 	i++;
			// }
		}
	return (0);
}
