/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:32:23 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/17 18:07:44 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void	mini_count_word(int *i, char *str)
// {
// 	if (str[*i] == 39)
// 	{
// 		(*i)++;
// 		while (str[*i] && str[*i] != 39)
// 		{
// 			if (str[*i] == 92 && str[*i + 1] == 39)
// 				(*i) += 2;
// 			else
// 				(*i)++;
// 		}
// 		(*i)++;
// 	}
// }

// int	count_word(char *str)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		while (str[i] == ' ')
// 			i++;
// 		if (str[i] != ' ' && str[i])
// 		{
// 			count++;
// 			mini_count_word(&i, str);
// 			if (str[i] != 39 && str[i])
// 			{
// 				while (str[i] != ' ' && str[i])
// 					i++;
// 			}
// 		}
// 	}
// 	return (count);
// }

// int	find_char(char *str, char c, int i)
// {
// 	while (str[i])
// 	{
// 		if (str[i] == c && str[i - 1] != 92)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
// }

// int	contain_singleq(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == 39 && str[i - 1] != 92)
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

// char	*ft_strtrim2(char *s1, char const *set)
// {
// 	char	*res;
// 	size_t	i;
// 	size_t	y;

// 	if (!s1 || !set)
// 		return (free(s1), NULL);
// 	y = ft_strlen(s1);
// 	i = 0;
// 	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
// 		i++;
// 	while (y > 0 && ft_strchr(set, s1[y - 1]) != NULL)
// 	{
// 		if (s1[y - 1] == 39)
// 		{
// 			y--;
// 			break ;
// 		}
// 		--y;
// 	}
// 	if (i >= y)
// 		return (free(s1), ft_strdup(""));
// 	res = ft_substr(s1, i, y - i);
// 	free(s1);
// 	return (res);
// }

// void	sing_quo_h(char *str, int *f, char **res, varij *var, int *temp)
// {
// 	if (str[var->i] == 39 && str[var->j - 1] != 92)
// 	{
// 		res[var->j] = ft_strtrim2(ft_substr(str, *temp, find_char(str, '\'', var->i + 1) - var->i + 1), "' ");
// 		var->i = find_char(str, '\'', var->i + 1);
// 		*temp = var->i + 1;
// 		var->j++;
// 		*f = 1;
// 	}
// 	else if (str[var->i] == ' ')
// 	{
// 		if (!(*f))
// 		{
// 			res[var->j] = ft_substr(str, *temp, var->i - *temp);
// 			var->j++;
// 			*temp = var->i + 1;
// 		}
// 		*f = 0;
// 	}
// }

// char	**single_quote_handle(char *str)
// {
// 	char	**res;
// 	int		temp;
// 	int		f;
// 	varij	var;

// 	f = 0;
// 	var.i = 0;
// 	temp = 0;
// 	var.j = 0;
// 	res = malloc((count_word(str) + 1) * sizeof(char *));
// 	if (!res)
// 		return (NULL);
// 	while (str[var.i])
// 	{
// 		sing_quo_h(str, &f, res, &var, &temp);
// 		var.i++;
// 	}
// 	return (res[var.j] = NULL, res);
// }

// int	checker_(char *command)
// {
// 	return (access(command, F_OK) == 0);
// }

// void	free2d(char **res)
// {
// 	int	i;

// 	i = 0;
// 	if (res != NULL)
// 	{
// 		while (res[i])
// 		{
// 			free(res[i]);
// 			i++;
// 		}
// 		free(res);
// 	}
// }

// char	*find_path(char *command, char *envp)
// {
// 	char	**paths;
// 	int		i;
// 	char	*res;

// 	i = 0;
// 	res = NULL;
// 	paths = ft_split(envp, ':');
// 	free(envp);
// 	if (checker_(command))
// 		return (ft_strdup(command));
// 	while (paths[i])
// 	{
// 		paths[i] = ft_strjoin2(paths[i], "/");
// 		i++;
// 	}
// 	i = 0;
// 	while (paths[i] != NULL)
// 	{
// 		free(res);
// 		res = ft_strjoin(paths[i], command);
// 		if (access(res, F_OK) == 0)
// 			return (free2d(paths), res);
// 		i++;
// 	}
// 	return (NULL);
// }

// void	exit_error(char *str, int n)
// {
// 	perror(str);
// 	exit(n);
// }

// char	*get_env(char *envp[])
// {
// 	while (*envp != NULL)
// 	{
// 		if (ft_strncmp(*envp, "PATH", 4) == 0)
// 			return (ft_substr(*envp, 6, ft_strlen(*envp) - 6));
// 		envp++;
// 	}
// 	return (NULL);
// }

// char	**option_split(char *str)
// {
// 	if (contain_singleq(str) > 1)
// 		return (single_quote_handle(str));
// 	else
// 		return (ft_split(str, ' '));
// 	return (NULL);
// }

// void	start_pipe(int fdin, int fd)
// {
// 	dup2(fd, STDOUT_FILENO);
// 	dup2(fdin, STDIN_FILENO);
// }

// pid_t	smart_fork(void)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork");
// 		exit(-1);
// 	}
// 	else
// 		return (pid);
// }

// void	close_fd(int **fd, int n)
// {
// 	int	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		close(fd[i][0]);
// 		close(fd[i][1]);
// 		i++;
// 	}
// }

// int	**malloc_2d(int **fd, int rows)
// {
// 	int	i;

// 	i = 0;
// 	fd = malloc(rows * sizeof(int *));
// 	if (fd == NULL)
// 		return (NULL);
// 	while (i < rows)
// 	{
// 		fd[i] = malloc(2 * sizeof(int));
// 		if (fd[i] == NULL)
// 			return (NULL);
// 		i++;
// 	}
// 	return (fd);
// }

// int	*malloc_int_arr(int *fd, int n)
// {
// 	fd = malloc(n * sizeof(int));
// 	if (fd == NULL)
// 		return (NULL);
// 	return (fd);
// }

// void	smart_pipe(int **fd, int n)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < n)
// 	{
// 		j = pipe(fd[i]);
// 		if (j == -1)
// 			exit_error("PIPE", 1);
// 		i++;
// 	}
// }

// void	pipes_level(int argc, variables var, commands_ command, char *envp[])
// {
// 	int	j;

// 	if (var.j == 3)
// 		j = 5;
// 	if (var.j == 2)
// 		j = 4;
// 	if (var.i == var.j)
// 		start_pipe(var.fdin, var.fd[var.i - var.j][1]);
// 	else if (var.i < argc - var.j)
// 		start_pipe(var.fd[var.i - var.j - 1][0], var.fd[var.i - var.j][1]);
// 	else
// 		start_pipe(var.fd[var.i - var.j - 1][0], var.fdout);
// 	close_fd(var.fd, argc - j);
// 	if (execve(command.path, command.command_args, envp) == -1)
// 		exit_error(command.command_args[0], 127);
// }

void	parent_helper(variables var, int argc, int *status)
{
	int	i;

	if (var.j == 3)
		close_fd(var.fd, argc - 5);
	else
		close_fd(var.fd, argc - 4);
	i = 0;
	while (i < argc - (var.j) + 1)
	{
		waitpid(var.pids[i], status, 0);
		i++;
	}
}

void	mini_helper(commands_ *command, variables *var, char *argv[], char *envp[])
{
	free2d(command->command_args);
	free(command->path);
	command->command_args = option_split((char *)argv[var->i]);
	command->path = find_path(command->command_args[0], get_env(envp));
	var->pid = fork();
	if (var->pid == -1)
		perror("FORK ");
}

int	helper_function(variables var, int argc, char *argv[], char *envp[])
{
	int			status;
	commands_	command;

	var.i = 2;
	if (var.is_herdoc)
		var.i = 3;
	var.j = var.i;
	status = 0;
	command.command_args = NULL;
	command.path = NULL;
	while (var.i < argc - 1)
	{
		mini_helper(&command, &var, argv, envp);
		if (var.pid == 0)
			pipes_level(argc, var, command, envp);
		else
			var.pids[var.i - var.j] = var.pid;
		var.i++;
	}
	if (var.pid > 0)
		parent_helper(var, argc, &status);
	return (free2d(command.command_args), free(command.path), status);
}

void	here_doc_handler(variables *var, int argc, char **argv)
{
	char	*str;

	var->j = 5;
	var->is_herdoc = 1;
	var->fdin = open("/tmp/pipex.txt", O_RDWR | O_TRUNC | O_CREAT, 0777);
	var->fdout = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND , 0777);

	while (1)
	{
		str = get_next_line(0);
		if (!ft_strncmp(argv[2], str, ft_strlen(argv[2])))
		{
			close(var->fdin);
			var->fdin = open("/tmp/pipex.txt", O_RDWR | O_CREAT, 0777);
			free(str);
			break ;
		}
		write(var->fdin, str, ft_strlen(str));
		free(str);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int			status;
	variables	var;

	status = 0;
	if (argc > 4)
	{
		var.fd = malloc_2d(var.fd, argc - 4);
		var.pids = malloc_int_arr(var.pids, argc - 3);
		var.is_herdoc = 0;
		var.j = 4;
		if (!ft_strncmp(argv[1], "here_doc", 8))
			here_doc_handler(&var, argc, argv);
		else
		{
			var.fdin = open(argv[1], O_RDWR);
			var.fdout = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT);
		}
		if (var.fdout == -1 || var.fdin == -1)
			exit_error("FILE", 1);
		smart_pipe(var.fd, argc - var.j);
		status = helper_function(var, argc, argv, envp);
	}
	unlink("pipex.txt");
	return (WEXITSTATUS(status));
}
