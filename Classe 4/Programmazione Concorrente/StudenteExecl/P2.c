#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct
{
    char nome[100];
    char cognome[100];
    int eta;
} Studente;

int main(int argc, char **argv)
{
    int fifo;
    Studente studente;
    // Controllo parametri linea di comando
    if (argc != 1)
    {
        printf("Utilizzo [<FIFO>]\n");
        exit(-1);
    }
    // Apertura fifo
    fifo = open(argv[0], O_RDONLY);
    if (fifo == -1)
    {
        printf("Errore nell'apertura della fifo\n");
        exit(-2);
    }
    // Lettura informazoni
    read(fifo, &studente, sizeof(Studente));
    // Scrittura dati letti
    printf("Dati letti dello studente:\n");
    printf("Nome: %s\n", studente.nome);
    printf("Cognome: %s\n", studente.cognome);
    printf("Eta: %d\n", studente.eta);
    close(fifo);
    return 0;
}