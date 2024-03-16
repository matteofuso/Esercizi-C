#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>

typedef struct
{
    char nome[100];
    char cognome[100];
    int eta;
} Studente;

int main(int argc, char **argv)
{
    int PID;
    // Controllo parametri linea di comando
    if (argc != 3)
    {
        printf("Uso %s [<P2>] [<FIFO>]\n", argv[0]);
        exit(-1);
    }
    // Creazione fork
    PID = fork();
    if (PID < 0)
    {
        printf("Errore nella creazione della fork\n");
        exit(-2);
    }
    if (PID)
    {
        int fifo;
        Studente studente;
        // Padre - Generazione della fifo
        if (mkfifo(argv[2], 0777) == -1)
        {
            if (errno != EEXIST)
            {
                printf("Errore nella creazione della fifo\n");
                exit(-3);
            }
        }
        // Apertura fifo
        fifo = open(argv[2], O_WRONLY);
        if (fifo == -1)
        {
            printf("Errore nell'apertura della fifo\n");
            exit(-4);
        }
        // Inserimento dati studente
        printf("Inserisci il nome dello studente: ");
        scanf("%s", studente.nome);
        printf("Inserisci il cognome dello studente: ");
        scanf("%s", studente.cognome);
        printf("Inserisci l'età dello studente: ");
        scanf("%d", &studente.eta);
        printf("\n");
        // Passaggio informazoni
        write(fifo, &studente, sizeof(Studente));
        close(fifo);
        wait(NULL);
    }
    else
    {
        // Figlio
        execl(argv[1], argv[2], NULL);
        printf("C'è stato un problema nell'esecuzione della execl\n");
        exit(-5);
    }
    return 0;
}