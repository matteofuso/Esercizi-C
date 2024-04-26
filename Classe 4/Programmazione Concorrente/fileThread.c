/*
    -copiare il contenuto di un file di testo in un secondo file (i nomi dei file sono inseriti dall'utente quando avvia il programma);
    -le operazioni di lettura e scrittura sono svolte da due thread separati.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

int fd[2];

void *threadLettura(void *args)
{
    FILE *file = (FILE *)args;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0)
    {
        write(fd[1], buffer, n);
    }

    close(fd[1]);
    pthread_exit(NULL);
}

void *threadScrittura(void *args)
{
    FILE *file = (FILE *)args;
    char buffer[BUFFER_SIZE];
    int n;

    while ((n = read(fd[0], buffer, BUFFER_SIZE)) > 0)
    {
        fwrite(buffer, sizeof(char), n, file);
    }

    close(fd[0]);
    pthread_exit(NULL);
}

int main(int argc, char *arv[])
{
    // Controllo parametri
    if (argc != 3)
    {
        printf("Utilizzo: %s <file_input> <file_output>\n", arv[0]);
        return -1;
    }

    pthread_t threadReader, threadWriter;
    FILE *lettura, *scrittura;

    // Apertura file di origine e destinazione
    lettura = fopen(arv[1], "r");
    if (lettura == NULL)
    {
        printf("Errore nell'apertura del file di lettura\n");
        return -2;
    }
    scrittura = fopen(arv[2], "w");
    if (scrittura == NULL)
    {
        printf("Errore nell'apertura del file di scrittura\n");
        fclose(lettura);
        return -3;
    }

    // Apertura di pipe per la comunicazione tra i thread
    if (pipe(fd) == -1)
    {
        printf("Errore nella creazione della pipe\n");
        fclose(lettura);
        fclose(scrittura);
        return -4;
    }

    // Creazione thread
    pthread_create(&threadReader, NULL, &threadLettura, lettura);
    pthread_create(&threadWriter, NULL, &threadScrittura, scrittura);

    // Chiusura thread e file
    pthread_join(threadReader, NULL);
    pthread_join(threadWriter, NULL);
    fclose(lettura);
    fclose(scrittura);
    return 0;
}