#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
    Scrivi il codice sorgente di un programma in cui solo il processo padre genera due processi figli.
    Il padre visualizza il proprio PID e il PID dei suoi due figli.
    Ciascun figlio visualizza il Proprio PID e il PID del padre.
    Manda in esecuzione più volte e osserva il comportamento del programma in esecuzione.
*/

int pidChildFirst, pidChildSecond;

int main(int argc, char *arv[])
{
    pidChildFirst = fork();
    if (pidChildFirst)
    {
        pidChildSecond = fork();
        if (pidChildSecond)
        {
            // Eseguito dal padre
            printf("Sono il processo padre, il mio pid è %d ed i pid dei miei due figli sono %d e %d\n", getpid(), pidChildFirst, pidChildSecond);
            return 0;
        }
    }
    if (!pidChildFirst)
    {
        // Eseguito dal primo figlio
        printf("Sonno il primo figlio, il mio pid è %d ed il pid di mio padre è %d\n", getpid(), getppid());
        return 0;
    }
    // Eseguito dal secondo figlio
    printf("Sono il secondo figlio, il mio pid è %d ed il pid di mio padre è %d\n", getpid(), getppid());
    return 0;
}