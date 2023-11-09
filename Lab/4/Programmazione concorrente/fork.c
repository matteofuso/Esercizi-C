#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/// @brief Integer variable used to manage parent and child process.
/// p with Parent = PID of the Child,
/// p with Child = 0
int p;

/// @brief Entry point
/// @param argc Elements of argv
/// @param argv Parameters
/// @return Status
int main(int argc, char *argv[])
{
    p = fork(); // Parent generate a child process
    if (p < 0)
    {
        printf("Can't fork!\n");
    }
    else if (p != 0) // Parent
    {
        printf("I'm your parent (p = %d) (PID = %d) (pPID = %d)\n", p, getpid(), getppid());
    }
    else // Child
    {
        printf("I'm the child (p = %d) (pid= %d) (pPID = %d)\n", p, getpid(), getppid());
    }
    return 0;
}