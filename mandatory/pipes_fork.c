/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:18:33 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/20 16:58:24 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipes_level(int argc, t_variables var, t_commands_ command
, char *envp[])
{
	int	j;

	if (var.j == 3)
		j = 5;
	if (var.j == 2)
		j = 4;
	if (var.i == var.j)
		start_pipe(var.fdin, var.fd[var.i - var.j][1]);
	else if (var.i < argc - var.j)
		start_pipe(var.fd[var.i - var.j - 1][0], var.fd[var.i - var.j][1]);
	else
		start_pipe(var.fd[var.i - var.j - 1][0], var.fdout);
	close_fd(var.fd, argc - j);
	if (execve(command.path, command.command_args, envp) == -1)
		exit_error(command.command_args[0], 127);
}

void	smart_pipe(int **fd, int n)
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

void	start_pipe(int fdin, int fd)
{
	dup2(fd, STDOUT_FILENO);
	dup2(fdin, STDIN_FILENO);
}

void	close_fd(int **fd, int n)
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
