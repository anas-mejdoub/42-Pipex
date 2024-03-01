/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:32:23 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/01 18:26:09 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include <errno.h>

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
int checker_(char *command, char *paths)
{
	return (command[0] == '/');
}
char *find_path(char *command, char *envp)
{
		char **paths = ft_split(envp, ':');
		int	i;

		i = 0;
		if (checker_(command, envp))
			return (command);
		while (paths[i])
		{
			paths[i] = ft_strjoin(paths[i], "/");
			
			i++;
		}
		i = 0;
		while(paths[i] != NULL)
		{
			if (access(ft_strjoin(paths[i], command), F_OK) == 0)
			{
				return (ft_strjoin(paths[i], command));
			}
			i++;
		}
		return (NULL);
}
int exit_error(char *str, int n)
{
	perror(str);
	return (n);
}
char *get_env(char *envp[])
{
	while(*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
		{
			return (ft_substr(*envp, 6, ft_strlen(*envp) - 6));
		}
		envp++;
	}
	return (NULL);
}

int main(int argc, char const *argv[], char *envp[])
{
		char *path;
		int fd[argc - 3][2];
		int fdin;
		int fdout;
		char **command_args;
		int i;
		int status;
		
		i = 2;
		if (argc >= 5)
		{
			fdout = open(argv[argc - 1], O_RDWR | O_TRUNC);
			fdin = open(argv[1], O_RDWR);
			if (fdout == -1 || fdin == -1)
				return(exit_error("FILE", 1));
			while (i < argc - 1)
			{
				int j = pipe(fd[i - 2]);
				pid_t pid;
				command_args = ft_split(argv[i], ' ');
				path = find_path(command_args[0], get_env(envp));
				pid = fork();
				if (pid == -1 || j == -1)
					perror("FORK");
				if (pid == 0)
				{
					if (i == 2)
					{
						dup2(fdin, STDIN_FILENO);
						dup2(fd[i - 2][1], STDOUT_FILENO);
						if (execve(path, command_args, envp) == -1)
							return (exit_error("COMMAND1", 127));
					}
					else if (i < argc - 2)
					{
						dup2(fd[i - 3][0], STDIN_FILENO);
						dup2(fd[i - 2][1], STDOUT_FILENO);
						if (execve(path, command_args, envp) == -1)
								return (exit_error("COMMAND2", 127));
					}			
					exit(0);
				}
				else if (pid > 0 && i >= argc - 2)
				{
					int k = waitpid(pid, &status, 0);
					if (WEXITSTATUS(status) != 0)
						return (exit_error("COMMAND3", 127));
					dup2(fd[i - 3][0], STDIN_FILENO);
					dup2(fdout, STDOUT_FILENO);
					if (execve(path, command_args, envp) == -1)
						return (exit_error("COMMAND", 127));
				}
				
				close(fd[i - 2][1]);
				i++;
			}
		}
	return (0);
}
