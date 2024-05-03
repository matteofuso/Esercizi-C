#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define BLOCKS 8

typedef struct
{
    char buffer[BUFFER_SIZE];
    int n;
} Block;

Block buffer[BLOCKS];
int readPosition = 0;
int writePosition = 0;

void *Lettura(void *args)
{
    FILE *file = (FILE *)args;

    do
    {
        // Aspetto il thread di scrittura
        while (readPosition == writePosition + BLOCKS);
        buffer[readPosition % BLOCKS].n = fread(buffer[readPosition % BLOCKS].buffer, sizeof(char), BUFFER_SIZE, file);
    } while (buffer[(readPosition++) % BLOCKS].n > 0);

    pthread_exit(NULL);
}

void *Scrittura(void *args)
{
    FILE *file = (FILE *)args;

    do
    {
        // Aspetto che ci sia il dato
        while (readPosition == writePosition);
        fwrite(buffer[writePosition % BLOCKS].buffer, sizeof(char), buffer[writePosition % BLOCKS].n, file);
    } while (buffer[(writePosition++) % BLOCKS].n > 0);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;
    pthread_t lettura, scrittura;

    // Controllo parametri
    if (argc != 3)
    {
        printf("Uso: %s <file di origine> <file di destinazione>\n", argv[0]);
        return -1;
    }

    // Apertura file
    origine = fopen(argv[1], "r");
    if (origine == NULL)
    {
        printf("Impossibile aprire il file di origine\n");
        return -1;
    }
    destinazione = fopen(argv[2], "w");
    if (destinazione == NULL)
    {
        printf("Impossibile aprire il file di destinazione\n");
        return -1;
    }

    // Creazione thread
    pthread_create(&lettura, NULL, &Lettura, origine);
    pthread_create(&scrittura, NULL, &Scrittura, destinazione);
    pthread_join(lettura, NULL);
    pthread_join(scrittura, NULL);

    // Chiusura file
    fclose(origine);
    fclose(destinazione);
    return 0;
}