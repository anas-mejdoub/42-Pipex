/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 21:30:52 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/17 21:54:13 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H
# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_variables
{
	int		fdin;
	int		fdout;
	int		**fd;
	int		*pids;
	pid_t	pid;
	int		is_herdoc;
	int		j;
	int		i;
}			t_variables;

typedef struct s_commands_variables
{
	char	*path;
	char	**command_args;
}			t_commands_;

typedef struct s_varij
{
	int		i;
	int		j;
	int		f;
}			t_varij;

char		**option_split(char *str);
int			count_word(char *str);
void		mini_count_word(int *i, char *str);
int			find_char(char *str, char c, int i);
int			contain_singleq(char *str);
char		*ft_strtrim2(char *s1, char const *set);
char		**single_quote_handle(char *str);
int			checker_(char *command);
void		free2d(char **res);
char		*find_path(char *command, char *envp);
void		exit_error(char *str, int n);
char		*get_env(char *envp[]);
void		start_pipe(int fdin, int fd);
pid_t		smart_fork(void);
void		close_fd(int **fd, int n);
int			**malloc_2d(int **fd, int rows);
int			*malloc_int_arr(int *fd, int n);
void		smart_pipe(int **fd, int n);
void		pipes_level(int argc, t_variables var, t_commands_ command,
				char *envp[]);
void		parent_helper(t_variables var, int argc, int *status);
int			helper_function(t_variables var, int argc, char *argv[],
				char *envp[]);
void		sing_quo_h(char *str, char **res, t_varij *var, int *temp);
#endif