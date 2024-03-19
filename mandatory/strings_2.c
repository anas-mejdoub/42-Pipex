/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 18:06:29 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/19 14:55:15 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**single_quote_handle(char *str)
{
	char	**res;
	int		temp;
	t_varij	var;

	var.f = 0;
	var.i = 0;
	temp = 0;
	var.j = 0;
	res = malloc((count_word(str) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	while (str[var.i])
	{
		sing_quo_h(str, res, &var, &temp);
		var.i++;
	}
	return (res[var.j] = NULL, res);
}

char	*find_path(char *command, char *envp)
{
	char	**paths;
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	paths = ft_split(envp, ':');
	free(envp);
	if (checker_(command))
		return (ft_strdup(command));
	while (paths[i])
	{
		paths[i] = ft_strjoin2(paths[i], "/");
		i++;
	}
	i = 0;
	while (paths[i] != NULL)
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

char	*get_env(char *envp[])
{
	while (*envp != NULL)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			return (ft_substr(*envp, 6, ft_strlen(*envp) - 6));
		envp++;
	}
	return (NULL);
}

char	**option_split(char *str)
{
	if (contain_singleq(str) > 1)
		return (single_quote_handle(str));
	else
		return (ft_split(str, ' '));
	return (NULL);
}
