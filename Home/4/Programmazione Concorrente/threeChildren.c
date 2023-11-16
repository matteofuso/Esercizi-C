#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
    Scrivi il codice sorgente di un programma in cui il processo padre
    genera tre processi figli: Qui, Quo, Qua.
    Ciascun processo dovrà visualizzare sullo schermo, rispettivamente:
    _"Sono il padre A, il mio PID = …"
    _"Sono il figlio QUI, il mio PID = …"
    _"Sono il figlio QUO, il mio PID = …"
    _"Sono il figlio QUA, il mio PID = …"
    Manda in esecuzione più volte e osserva il comportamento del programma in esecuzione.
*/

int pidChildFirst, pidChildSecond, pidChildThird;

int main(int argc, char *arv[])
{
    pidChildFirst = fork();
    if (pidChildFirst)
    {
        pidChildSecond = fork();
        if (pidChildSecond)
        {
            pidChildThird = fork();
            if (pidChildThird)
            {
                // Eseguito dal padre
                printf("Sono il padre A, il mio PID = %d\n", getpid());
                return 0;
            }
        }
    }
    if (!pidChildFirst)
    {
        // Eseguito dal primo figlio
        printf("Sono il figlio QUI, il mio PID = %d\n", getpid());
        return 0;
    }
    if (!pidChildSecond)
    {
        // Eseguito dal secondo figlio
        printf("Sono il figlio QUO, il mio PID = %d\n", getpid());
        return 0;
    }
    // Eseguito dal terzo figlio
    printf("Sono il figlio QUA, il mio PID = %d\n", getpid());
    return 0;
}