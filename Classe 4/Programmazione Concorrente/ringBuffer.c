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
pthread_cond_t condFill, condEmpty;
pthread_mutex_t critical;

void *Lettura(void *args)
{
    FILE *file = (FILE *)args;

    do
    {
        pthread_mutex_lock(&critical);
        // Aspetto il thread di scrittura
        if (readPosition == writePosition + BLOCKS)
        {
            pthread_cond_wait(&condFill, &critical);
        }
        buffer[readPosition % BLOCKS].n = fread(buffer[readPosition % BLOCKS].buffer, sizeof(char), BUFFER_SIZE, file);
        pthread_cond_signal(&condEmpty);
        pthread_mutex_unlock(&critical);
    } while (buffer[(readPosition++) % BLOCKS].n > 0);

    pthread_exit(NULL);
}

void *Scrittura(void *args)
{
    FILE *file = (FILE *)args;

    do
    {
        pthread_mutex_lock(&critical);
        // Aspetto che ci sia il dato
        if (readPosition == writePosition)
        {
            pthread_cond_wait(&condEmpty, &critical);
        }
        fwrite(buffer[writePosition % BLOCKS].buffer, sizeof(char), buffer[writePosition % BLOCKS].n, file);
        pthread_cond_signal(&condFill);
        pthread_mutex_unlock(&critical);
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
        fclose(origine);
        return -1;
    }

    // Creazione thread e sezioni critiche
    pthread_mutex_init(&critical, NULL);
    pthread_cond_init(&condFill, NULL);
    pthread_cond_init(&condEmpty, NULL);
    
    pthread_create(&lettura, NULL, &Lettura, origine);
    pthread_create(&scrittura, NULL, &Scrittura, destinazione);
    pthread_join(lettura, NULL);
    pthread_join(scrittura, NULL);

    pthread_mutex_destroy(&critical);
    pthread_cond_destroy(&condFill);
    pthread_cond_destroy(&condEmpty);

    // Chiusura file
    fclose(origine);
    fclose(destinazione);
    return 0;
}