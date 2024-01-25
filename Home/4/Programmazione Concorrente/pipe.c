#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define NUMBERS 5

int main(int argc, char **argv)
{
    int fd[2], p;
    // Create the PIPE
    if (pipe(fd) < 0)
    {
        printf("Error calling the pipe() API\n");
        exit(-1);
    }
    // Create the child process
    p = fork();
    if (p < 0)
    {
        printf("Error calling the fork() API\n");
        close(fd[0]);
        close(fd[1]);
        exit(-1);
    }
    // Child process
    if (!p)
    {
        int numeri[NUMBERS];
        close(fd[0]);
        // Identification
        printf("I'm the child process, my PID is %d and my parent's one is %d\n", getpid(), getppid());
        // Read the numbers
        printf("Please insert %d numbers: \n", NUMBERS);
        for (int *p = numeri; p < numeri + NUMBERS; p++)
        {
            printf("Insert a number: ");
            scanf("%d", p);
        }
        // Send the number through the pipe
        if (write(fd[1], numeri, sizeof(int) * NUMBERS) < 0)
        {
            printf("Error calling the write() API\n");
            close(fd[1]);
            exit(-1);
        }
        close(fd[1]);
        exit(0);
    }
    // Parent process
    close(fd[1]);
    int numeri[NUMBERS], n;
    // Identification
    printf("I'm the parent process, my PID is %d and my child's one is %d\n", getpid(), p);
    // Reading the numbers from the pipe
    if (read(fd[0], numeri, sizeof(int) * NUMBERS) < 0)
    {
        printf("Error calling the read() API\n");
        close(fd[0]);
        exit(-1);
    }
    // Ask for the multiplier
    printf("Insert the multiplier: ");
    scanf("%d", &n);
    // Multiply the numbers
    for (int *p = numeri; p < numeri + NUMBERS; p++)
    {
        *p *= n;
    }
    // Print the numbers
    printf("The numbers are:\n");
    for (int *p = numeri; p < numeri + NUMBERS; p++)
    {
        printf("%d\n", *p);
    }
    close(fd[0]);
    wait(NULL);
    return 0;
}