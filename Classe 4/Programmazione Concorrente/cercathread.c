/*
    Creare un programma che:
    1 - crea un array di 10 numeri (tra questi inserire il numero otto in una posizione qualsiasi);
    2 - crea un thread per ricercare il numero otto nella prima metà dell'array;
    3 - crea un altro thread per ricercare il numero otto nella seconda metà dell'array.
    Il thread che trova il numero otto deve stampare la posizione che occupa nell'array.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    int *numeri;
    int partenza;
    int fine;
} Parametri;

void *Ricerca(void *args)
{
    Parametri *parametri = (Parametri *)args;
    for (int i = parametri->partenza; i <= parametri->fine; i++)
    {
        if (parametri->numeri[i] == 8)
        {
            printf("Il numero 8 è stato trovato nella posizione %d\n", i + 1);
        }
    }
    return NULL;
}

void InserimentoNumeri(int *numeri, int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        printf("Inserisci il %d numero: ", i + 1);
        scanf("%d", numeri + i);
    }
}

int main(int argc, char *argv[])
{
    pthread_t threadPrimaMeta, threadSecondaMeta;
    int numeri[10];
    InserimentoNumeri(numeri, 10);
    // Preparazione parametri
    Parametri primaMeta, secondaMeta;
    primaMeta.numeri = numeri;
    primaMeta.partenza = 0;
    primaMeta.fine = 5;
    secondaMeta.numeri = numeri;
    secondaMeta.partenza = 6;
    secondaMeta.fine = 9;
    // Creazione thread
    pthread_create(&threadPrimaMeta, NULL, &Ricerca, &primaMeta);
    pthread_create(&threadSecondaMeta, NULL, &Ricerca, &secondaMeta);
    // Chiusura
    pthread_join(threadPrimaMeta, NULL);
    pthread_join(threadSecondaMeta, NULL);
    return 0;
}