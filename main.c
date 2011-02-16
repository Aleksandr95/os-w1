#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    pid_t pid = fork();
    printf("Main process with pid=%d\n", pid);
}

