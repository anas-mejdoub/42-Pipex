/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:32:23 by amejdoub          #+#    #+#             */
/*   Updated: 2024/02/27 15:37:35 by amejdoub         ###   ########.fr       */
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

		// argv +=1;
		char **command_args = ft_split(argv[1], ' ');
		path = find_path(command_args[0], get_env(envp));
		if (path != NULL)
		{
			pid_t pid;
			pid = fork();
			if (pid == 0)
			{
				ft_printf("%s\n", argv[1]);
				if (execve(path, (char *const *)command_args, envp) == -1)
					perror("COMMAND");
				exit(0);
			}
			else
			{
				int status;
				wait(&status);
			}
		}
		else
		{
			perror("COMMAND NOT FOUND !");
		}
	return 0;
}
