#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
    Scrivi il codice sorgente di un programma che permette al processo padre di generare un processo figlio.
    Sia il processo padre e sia il processo figlio visualizzano ciascuno il proprio PID e il PID del proprio parente.
    Padre conta da 0 a 19.
    Figlio conta da 0 a 9.
    Manda in esecuzione più volte e osserva il comportamento del programma in esecuzione.
*/

int pid;

int conta(int times)
{
    for (int i = 1; i <= times; i++)
    {
        printf("%d (%d)\n", i, pid);
    }
}

int main(int argc, char *argv[])
{
    pid = fork();
    if (pid < 0)
    {
        printf("Impossibile eseguire la fork\n!");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("Sono il figlio, il mio PID è %d, il PID di mio padre è %d\n", getpid(), getppid());
        conta(70);
        return 0;
    }
    printf("Sono il padre, il mio PID è %d, il PID di mio figlio è %d, il PID di mio padre è %d\n", getpid(), pid, getppid());
    conta(70);
    return 0;
}