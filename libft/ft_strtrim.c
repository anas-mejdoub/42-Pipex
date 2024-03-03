/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:40:28 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/03 16:02:31 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char const *set)
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
		--y;
	if (i >= y)
		return (free(s1), ft_strdup(""));
	res = ft_substr(s1, i, y - i);
	free(s1);
	return (res);
}
