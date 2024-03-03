#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"
#include <errno.h>

// char **singleQuoteHandle(char *str)
// {
// 	int		i;
// 	char	**res;
// 	int		j;
//     int temp;
	
// 	i = 0;
//     temp = 0;
// 	j = 0;
//     res = malloc(1000 * sizeof(char *));
// 	while (str[i])
// 	{
// 		if (str[i] == 39)
// 		{
// 			res[j] = ft_strtrim(ft_substr(str, temp, ft_strlen(str)), "\'");   
//             res[j + 1] = NULL;
// 			return (res);
// 		}
// 		else if (str[i] == ' ')
// 		{
// 			res[j] = ft_substr(str, temp, i - temp);
//             j++;
//             temp = i + 1;
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }
void test_exit()
{
	exit(77);
}
int main(int argc, char const *argv[])
{
    int i = 0;
    
    // char **str = singleQuoteHandle(argv[1]);
    // if (!str)
    //     return 99;
	test_exit();
    // ecxecv
    // while (str[i] != NULL)
    // {
    //     printf("%s\n", str[i]);
    //     i++;
    // }
    // ft_printf("%s", ft_strtrim("'{printf $hf}'", "'"));
    return 0;
}
