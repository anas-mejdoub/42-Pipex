#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>  // Include the <fcntl.h> header file

int main(int argc, char const *argv[])
{
    if (access("main.c", X_OK) == 0 )
        printf("yes");
    else
        printf("no");
    return 0;
}
