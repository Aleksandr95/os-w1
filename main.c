#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main (int argc, char *argv[])
{
    int fd[2];
    size_t size;
    char resstring[14];
    
    if(pipe(fd) < 0)
    {
      printf("Can\'t create pipe\n");
      return 1;
      }
    pid_t pid = fork();

    if (pid < 0)
    {
        fprintf(stderr, "fork: %s", strerror(errno));
         printf("Can not create child");
        return 1;
    }

    if (pid == 0)
    {
        close(fd[1]);
        size = read(fd[0], resstring, 14);
        if (size < 0)
        {
           printf("Can not read\n");
           return -1;
        }
        printf("Yes.Can read. str = %s\n", resstring);
        close(fd[0]);
        return 0;
        }   
        pid = getpid();
        close(fd[0]);
        size = write (fd[1], "hello , world", 14);
        if (size != 14)
        {
        printf("Can not write\n");
        return -1;
    }
    close(fd[1]);
    printf("Yes.Can write\n");
    return 0;
}

