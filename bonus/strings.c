/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:24:31 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/17 18:05:12 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	mini_count_word(int *i, char *str)
{
	if (str[*i] == 39)
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

int	find_char(char *str, char c, int i)
{
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != 92)
			return (i);
		i++;
	}
	return (-1);
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

void	sing_quo_h(char *str, int *f, char **res, varij *var, int *temp)
{
	if (str[var->i] == 39 && str[var->j - 1] != 92)
	{
		res[var->j] = ft_strtrim2(ft_substr(str, *temp, find_char(str, '\'', var->i + 1) - var->i + 1), "' ");
		var->i = find_char(str, '\'', var->i + 1);
		*temp = var->i + 1;
		var->j++;
		*f = 1;
	}
	else if (str[var->i] == ' ')
	{
		if (!(*f))
		{
			res[var->j] = ft_substr(str, *temp, var->i - *temp);
			var->j++;
			*temp = var->i + 1;
		}
		*f = 0;
	}
}
