#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>   //serve per la fork()
#include <sys/wait.h> //serve per la wait()

int p;
int status;

int main()
{
    p = fork();
    if (!p)
    {
        printf("Sono il figlio e il mio PID è %d\n", getpid());
        printf("Sono il figlio e PID di mio padre è %d\n", getppid());
        exit(25);
    }
    else
    {
        printf("4 Sono il padre e il mio PID è %d\n", getpid());
        printf("5 Sono il padre e il PID di mio figlio è %d\n", p);
        printf("Attendo che mio figlio %d termini\n", wait(&status)); // restituisce il PID del figlio che termina
        printf("Il codice di terminazione di mio figlio è WEXITSTATUS(status), cioè %d\n", WEXITSTATUS(status));
        // restituisce il codice  di terminazione del  figlio che termina
        // Attenzione: padre aveva gi� atteso la terminazione del figlio perci� ora non ha pi� figli
        printf("Attendo che mio figlio %d termini\n", wait(&status)); // -1 perch� non ha pi� figli
        /*Poichè padre ha atteso la terminazione del figlio,
          di conseguenza le prossime istruzioni
          verranno eseguite senz'altro DOPO che il figlio è terminato:
          SINCRONIZZAZIONE*/
        printf("Sono il padre PID=%d e vedo ancora il PID di mio figlio anche se è già terminato PID=%d", getpid(), p);
        printf("La exit di mio figlio e\' %d\n", WEXITSTATUS(status));
        printf("La exit di mio figlio e\' %d\n", status);
    }

    return 0;
}