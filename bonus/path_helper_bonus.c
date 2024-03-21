/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_helper_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 16:21:02 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/21 16:30:05 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*path_helper(char **paths, char *command)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	while (paths[i] != NULL)
	{
		free(res);
		res = ft_strjoin(paths[i], command);
		if (access(res, F_OK) == 0)
			return (free2d((void **)paths), res);
		i++;
	}
	return (NULL);
}
