#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include <errno.h>
// int find_char(char *str, char c, int i)
// {

// 	while (str[i])
// 	{
// 		if (str[i] == c && str[i - 1] != 92)
// 			return (i);
// 		i++;
// 	}
// 	return (-1);
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
//     {
//         if (s1[y - 1] == 39)
//         {
//             y--;
//             break;
//         }
// 		--y;
//     }
// 	if (i >= y)
// 		return (free(s1), ft_strdup(""));
// 	res = ft_substr(s1, i, y - i);
// 	free(s1);
// 	return (res);
// }
// int count_word(char *str)
// {
//     int i;
//     int count;

//     count = 0;
//     i = 0;
//     while (str[i])
//     {
//         while (str[i] == ' ')
//             i++;
//         if (str[i] !=  ' ' && str[i])
//         {
//             count++;
//             if (str[i] == 39)
//             {
//                 i++;
//                 while (str[i] && str[i] != 39)
//                 {
//                     if (str[i] == 92 && str[i + 1] == 39)
//                         i+=2;
// 					else
// 						i++;
//                 }
//                 i++;
//             }
//             else
//             {
//                 while(str[i] !=  ' ' && str[i])
//                     i++;
//             }
//         }
//     }
//     return (count);
// }
// char **singleQuoteHandle(char *str)
// {
// 	int		i;
// 	char	**res;
// 	int		j;
//     int temp;
// 	int f;

// 	f = 0;
// 	i = 0;
//     temp = 0;
// 	j = 0;
//     res = malloc((count_word(str) + 1) * sizeof(char *));
// 	if (!res)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		if (str[i] == 39 && str[i - 1] != 92)
// 		{
// 			res[j] = ft_strtrim2(ft_substr(str, temp, find_char(str, '\'', i + 1) - i + 1), "' ");
// 			i = find_char(str, '\'', i + 1);
//             temp = i + 1;
// 			j++;
// 			f = 1;
// 		}
// 		else if (str[i] == ' ')
// 		{
// 			if (!f)
// 			{
// 				res[j] = ft_substr(str, temp, i - temp);
// 				j++;
// 				temp = i + 1;
// 			}
// 			f = 0;
// 		}
// 		i++;
// 	}
// 	return (res[j] = NULL, res);
// }
// int containsSingleQ(char *str)
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

int main(int argc, char *argv[])
{

    // printf("%s");
    // char **str = singleQuoteHandle(argv[1]);
    // int i = 0;
    // while (str[i] != NULL)
    // {
    //     printf("%s\n", str[i]);
    //     i++;
    // }
    // char **str = ft_split("./test.sh" , ' ');
    // if (execve("./test.sh", str, NULL))
    // {
    //     printf("Error: %s\n", strerror(errno));
    // }
    // int fd = open("in", O_RDONLY);
    // char *str = get_next_line(0);
    // printf("%s", str);
    // int fd = open("/tmp/pipex.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
    // printf("%d\n", fd);
    // char buffer[100];
    // int a = read(fd, buffer, 100);
    // printf("%s", buffer);
    // a = write(fd, "Hello", 5);
    // printf("%d\n", a);
	// return(0);
    // return 0;
}
