#include <stdio.h>


int main(int argc, char const *argv[])
{
    /* code */
    int i = 0;
    // char str = '$';
    // printf("%c\n", str);
    while (i < argc)
    {
        // if (argv[i][0] == 36)
        //     printf("test\n");
        // else
        //     printf("test2\n");
        printf("%s\n", argv[i]);
        i++;
    }
    return 0;
}
