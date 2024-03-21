# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
int main(int argc, char const *argv[])
{
    execve(NULL, NULL, NULL);
    return 0;
}
