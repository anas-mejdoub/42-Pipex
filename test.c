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

int count_word(char *str)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while (str[i])
    {
        while (str[i] == ' ')
            i++;
        if (str[i] !=  ' ' && str[i])
        {
            count++;
            if (str[i] == 39)
            {
                i++;
                while (str[i] && str[i] != 39)
                    i++;
                i++;
            }
            else
            {
                while(str[i] !=  ' ' && str[i])
                    i++;
            }
        }
    }
    return (count);
}
// void test_exit()
// {
// 	exit(77);
// }
int main(int argc, char *argv[])
{
    int i = count_word(argv[1]);
    printf("%d\n", i);
    
    // char **str = singleQuoteHandle(argv[1]);
    // if (!str)
    //     return 99;
	// test_exit();
    // ecxecv
    // while (str[i] != NULL)
    // {
    //     printf("%s\n", str[i]);
    //     i++;
    // }
    // ft_printf("%s", ft_strtrim("'{printf $hf}'", "'"));
    return 0;
}
