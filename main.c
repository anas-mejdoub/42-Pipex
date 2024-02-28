/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:32:23 by amejdoub          #+#    #+#             */
/*   Updated: 2024/02/28 14:21:04 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

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
char *find_path(char *command, char *envp)
{
		char **paths = ft_split(envp, ':');
		int	i;

		i = 0;
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
		int fd[2];
		
		char **command_args = ft_split(argv[1], ' ');
		if (pipe(fd) == -1)
			perror("pipe");
		
		if (!command_args)
			return 2;
		path = find_path(command_args[0], get_env(envp));
		if (path != NULL)
		{
			pid_t pid;
			pid = fork();
			if (pid == 0)
			{
				dup2(fd[1], STDOUT_FILENO);
				// close(fd[1]);
				close(fd[0]);
				if (execve(path, (char *const *)command_args, envp) == -1)
					perror("COMMAND");
				exit(0);
			}
			else if (pid > 0)
			{
				
				int status;
				char *args[] = {"/usr/bin/wc", "-l", NULL};
				wait(&status);
				dup2(fd[0], STDIN_FILENO);
				close(fd[1]);
				if (execve("/usr/bin/wc", (char *const *)args, envp) == -1)
					perror("COMMAND");
			}
		}
		else
			perror("COMMAND NOT FOUND !");
	return 0;
}
