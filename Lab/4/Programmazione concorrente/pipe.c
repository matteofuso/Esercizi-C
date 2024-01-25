#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int fd[2], p;
    // Check if the pipe is created successfully
    if (pipe(fd) == -1) // Pipe creation using OS API
    {
        printf("There was an error creating the pipe, exiting...\n");
        exit(-1);
    }
    p = fork();
    // Check if the fork is created successfully
    if (p < 0)
    {
        printf("There was an errore in the forking process, exiting...\n");
        exit(-1);
    }

    // Child Process
    if (!p)
    {
        printf("I'm the child process, my PID is %d and my parent's one is %d\n", getpid(), getppid());
        close(fd[1]);
        char buffer[BUFFER_SIZE];
        int n;
        n = read(fd[0], buffer, BUFFER_SIZE);
        if (n == -1)
        {
            printf("Pipe reading error :(\n");
            exit(-1);
        }
        buffer[n] = '\0';
        printf("The value received from the pipe is \"%s\"\n", buffer);
        // Close the pipe and exiting
        close(fd[0]);
        exit(0);
    }

    // Parent Process
    printf("I'm the parent process, my PID is %d, my child's one is %d and my parent's one is %d\n", getpid(), p, getppid());
    close(fd[0]);
    const char *messaggio = "Good luck learning piping :)";
    if (write(fd[1], messaggio, strlen(messaggio)) == -1)
    {
        printf("Pipe writing error :(\n");
        exit(-1);
    }
    // Close the pipe and exiting
    close(fd[1]);
    wait(NULL);
    return 0;
}