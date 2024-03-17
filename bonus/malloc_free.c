/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:22:47 by amejdoub          #+#    #+#             */
/*   Updated: 2024/03/17 15:23:58 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	**malloc_2d(int **fd, int rows)
{
	int	i;

	i = 0;
	fd = malloc(rows * sizeof(int *));
	if (fd == NULL)
		return (NULL);
	while (i < rows)
	{
		fd[i] = malloc(2 * sizeof(int));
		if (fd[i] == NULL)
			return (NULL);
		i++;
	}
	return (fd);
}

int	*malloc_int_arr(int *fd, int n)
{
	fd = malloc(n * sizeof(int));
	if (fd == NULL)
		return (NULL);
	return (fd);
}

void	free2d(char **res)
{
	int	i;

	i = 0;
	if (res != NULL)
	{
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
	}
}

int	checker_(char *command)
{
	return (access(command, F_OK) == 0);
}