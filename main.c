#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "fork: %s", strerror(errno));
        return 1;
    }

    if (pid == 0)
    {
        pid = getpid();
        printf("Child process with pid=%d\n", pid);
        return 0;
    }

    printf("Main process with pid=%d\n", pid);
}

