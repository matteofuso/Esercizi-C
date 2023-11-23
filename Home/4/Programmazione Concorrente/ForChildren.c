#include <stdio.h>
#include <unistd.h>

#define CHILDREN 4

int main(int argc, char *argv[])
{
    int pid;
    char *nomi[] = {"QUI", "QUO", "QUA"};
    printf("Sono il padre, il mio PID è %d e quello del mio parente è %d\n", getpid(), getppid());
    for (int i = 0; i < CHILDREN; i++)
    {
        pid = fork();
        if (!pid)
        {
            printf("Sono %s, il mio PID è %d e quello del mio parente è %d\n", nomi[i], getpid(), getppid());
            return 0;
        }
    }
    
    return 0;
}