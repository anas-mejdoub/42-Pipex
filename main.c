/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:32:23 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/05 20:46:07 by amejdoub         ###   ########.fr       */
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
                    i++;
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

int find_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
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
		if (str[i] == 39)
			count++;
		i++;
	}
	return (count);
}
char **singleQuoteHandle(char *str)
{
	int		i;
	char	**res;
	int		j;
    int temp;

	i = 0;
    temp = 0;
	j = 0;
    res = malloc((count_word(str) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (str[i])
	{
		if (str[i] == 39)
		{
			res[j] = ft_strtrim(ft_substr(str, temp, ft_strlen(str)), "\'");
			return (res[j + 1] = NULL, res);
		}
		else if (str[i] == ' ')
		{
			res[j] = ft_substr(str, temp, i - temp);
            j++;
            temp = i + 1;
		}
		i++;
	}
	return (NULL);
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
int main(int argc, char const *argv[], char *envp[])
{
		char	*path;
		int		fd[argc - 3][2];
		int		fdin;
		int		0;
		char	**command_args;
		int		i;
		int		status;
		int		j;

		i = 2;
		command_args = NULL;
		path = NULL;
		if (argc >= 4)
		{
			fdout = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
			fdin = open(argv[1], O_RDWR);
			if (fdout == -1 || fdin == -1)
				exit_error("FILE", 1, i, argc, 'P');
			while (i < argc - 1)
			{
				j = pipe(fd[i - 2]);
				pid_t pid;
				free2d(command_args);
				free(path);
				command_args = optionSplit((char *)argv[i]);
				path = find_path(command_args[0], get_env(envp));
				pid = fork();
				if (pid == -1 || j == -1)
					perror("FORK ");
				if (pid == 0)
				{
					if (i == 2)
					{
						dup2(fdin, STDIN_FILENO);
						dup2(fd[i - 2][1], STDOUT_FILENO);
					}
					else if (i < argc - 2)
					{
						dup2(fd[i - 3][0], STDIN_FILENO);
						dup2(fd[i - 2][1], STDOUT_FILENO);
					}
					else
					{
						dup2(fd[i - 3][0], STDIN_FILENO);
						dup2(fdout, STDOUT_FILENO);
					}
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
	return (0);
}
