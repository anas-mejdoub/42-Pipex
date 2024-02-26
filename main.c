/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejdoub <amejdoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:32:23 by amejdoub          #+#    #+#             */
/*   Updated: 2024/02/26 19:45:59 by amejdoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> // Include the <fcntl.h> header file
#include "libft/libft.h"

char *find_path(char *command)
{
		char *paths[] = {"/bin/","/usr/bin/","/usr/local/bin/","/sbin/","/usr/sbin/","/usr/local/sbin/", NULL};
		int	i;

		i = 0;
		while(paths[i] != NULL)
		{
			if (access(ft_strjoin(paths[i], command), F_OK) == 0)
                return (ft_strjoin(paths[i], command));
            i++;
		}
        return (NULL);
}
int main(int argc, char const *argv[])
{
        char *path;
        
        argv +=1;
        path = find_path((char *)argv[0]);
        if (path != NULL)
        {
            if (execve(path, (char *const *)argv, NULL) == -1)
                perror("COMMAND");
        }
        else
        {
            perror("COMMAND NOT FOUND !");
        }
    return 0;
}
