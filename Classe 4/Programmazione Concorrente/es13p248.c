/*
    Codificare un programma in linguaggio C che crea due thread:
    il primo genera una sequenza di N numeri casuali, con N fornito come argomento da riga di comando,
    e li inserisce singolarmente in un ring-buffer, il secondo preleva i numeri dal ring-buffer condiviso e li visualizza.
    La codifica del programma dovrà prevedere la necessaria sincronizzazione tra thread produttore e thread consumatore
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define BLOCKS 8

typedef struct
{
    int min;
    int max;
} Intervallo;

int buffer[BLOCKS];
int N;
int readIndex, writeIndex;
pthread_cond_t condFull, condEmpty;
pthread_mutex_t critical;

void *Produttore(void *args)
{
    Intervallo intervallo = *((Intervallo *)args);
    for (; writeIndex < N; writeIndex++)
    {
        pthread_mutex_lock(&critical);
        // Aspetto che ci sia spazio per scrivere
        if (writeIndex == readIndex + BLOCKS)
        {
            pthread_cond_wait(&condFull, &critical);
        }
        // Generazione numero casuale e inserimento nel buffer
        buffer[writeIndex % BLOCKS] = rand() % (intervallo.max - intervallo.min + 1) + intervallo.min;
        pthread_cond_signal(&condEmpty);
        pthread_mutex_unlock(&critical);
    }
    pthread_exit(NULL);
}

void *Consumatore(void *args)
{
    FILE *f = (FILE *)args;
    for (; readIndex < N; readIndex++)
    {
        pthread_mutex_lock(&critical);
        // Aspetto che ci sia un numero da leggere
        if (readIndex == writeIndex)
        {
            pthread_cond_wait(&condEmpty, &critical);
        }
        // Stampa del numero letto
        fprintf(f, "%d\n", buffer[readIndex % BLOCKS]);
        pthread_cond_signal(&condFull);
        pthread_mutex_unlock(&critical);
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    pthread_t produttore, consumatore;
    Intervallo intervallo;
    // Controllo argomenti
    if (argc != 4)
    {
        printf("Uso: %s [<elementi da generare>] [<min>] [<max>]\n", argv[0]);
        return -1;
    }
    // Inizializzazione variabili e seed per rand
    N = atoi(argv[1]);
    intervallo.min = atoi(argv[2]);
    intervallo.max = atoi(argv[3]);
    if (intervallo.min > intervallo.max)
    {
        int temp = intervallo.min;
        intervallo.min = intervallo.max;
        intervallo.max = temp;
    }
    srand(time(NULL));
    // Creazione thread e variabili di condizione e mutex
    pthread_mutex_init(&critical, NULL);
    pthread_cond_init(&condFull, NULL);
    pthread_cond_init(&condEmpty, NULL);

    pthread_create(&produttore, NULL, Produttore, &intervallo);
    pthread_create(&consumatore, NULL, Consumatore, stdout);
    pthread_join(produttore, NULL);
    pthread_join(consumatore, NULL);

    pthread_mutex_destroy(&critical);
    pthread_cond_destroy(&condFull);
    pthread_cond_destroy(&condEmpty);
    return 0;
}