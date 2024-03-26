/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:24:31 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/26 17:27:05 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	mini_count_word(int *i, char *str)
{
	if (str[*i] == 39 && str[*i + 1] != 39)
	{
		(*i)++;
		while (str[*i] && str[*i] != 39)
		{
			if (str[*i] == 92 && str[*i + 1] == 39)
				(*i) += 2;
			else
				(*i)++;
		}
		(*i)++;
	}
}

int	count_word(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == 39 && str[i + 1] == 39)
			i+=2;
		if (str[i] != ' ' && str[i])
		{
			count++;
			mini_count_word(&i, str);
			if (str[i] != 39 && str[i])
			{
				while (str[i] != ' ' && str[i])
					i++;
			}
		}
	}
	return (count);
}

int	contain_singleq(char *str)
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
			break ;
		}
		--y;
	}
	if (i >= y)
		return (free(s1), ft_strdup(""));
	res = ft_substr(s1, i, y - i);
	free(s1);
	return (res);
}

void	sing_quo_h(char *str, char **res, t_varij *var, int *temp)
{
	int	subhelper;

	subhelper = 0;
	if (str[var->i] == 39 && str[var->i + 1] == 39)
		var->i += 2;
	if (str[var->i] == 39 && str[var->j - 1] != 92)
	{
		subhelper = find_char(str, '\'', var->i);
		res[var->j] = ft_strtrim(ft_substr(str, *temp, subhelper - var->i + 1), "' ");
		var->i = find_char(str, '\'', var->i + 1);
		*temp = var->i + 1;
		var->j++;
		var->f = 1;
	}
	else if (str[var->i] == ' ')
	{
		if (!(var->f))
		{
			res[var->j] = ft_substr(str, *temp, var->i - *temp);
			var->j++;
			*temp = var->i + 1;
		}
		var->f = 0;
	}
}
