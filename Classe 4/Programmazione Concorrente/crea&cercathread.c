/*
    -creare un array di mille numeri con valori compresi nell'intervallo 1-500;
    -ricercare un numero inserito nell'array distribuendo in maniera equa il carico di lavoro a quattro processi;
    - se il numero è nell'array stampare la posizione, altrimenti stampare "numero non trovato".
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define DIMENSIONE 1000
#define NUMERO_THREAD 4

int numeri[DIMENSIONE];
int occorrenzeNumero = 0;
int numeroDaCercare;

typedef struct
{
    int inizio; // Incluso nella ricerca
    int fine;   // Escluso nella ricerca
} Parametri;

void *Ricerca(void *args)
{
    Parametri *parametri = (Parametri *)args;

    for (int i = parametri->inizio; i < parametri->fine; i++)
    {
        if (numeri[i] == numeroDaCercare)
        {
            printf("Il numero %d è stato trovato nella posizione %d\n", numeroDaCercare, i);
            occorrenzeNumero++;
        }
    }
    pthread_exit(NULL);
}

void RiempiVettore(int *numeri, int dimensione)
{
    for (int i = 0; i < dimensione; i++)
    {
        numeri[i] = rand() % 500 + 1;
    }
}

int main(int argc, char *argv[])
{
    pthread_t threadRicerca[NUMERO_THREAD];
    Parametri parametriThread[NUMERO_THREAD];
    int restoNumeri;

    // Inizializzazione numeri
    srand(time(NULL));
    RiempiVettore(numeri, DIMENSIONE);

    // Inserimento numero da cercare
    printf("Inserisci il numero da cercare: ");
    scanf("%d", &numeroDaCercare);

    // Preparazione parametri per i thread e creazione
    restoNumeri = DIMENSIONE % NUMERO_THREAD;
    for (int i = 0; i < NUMERO_THREAD; i++)
    {
        if (i == 0)
        {
            parametriThread[i].inizio = 0;
        }
        else
        {
            parametriThread[i].inizio = parametriThread[i - 1].fine;
        }

        if (restoNumeri == 0)
        {
            parametriThread[i].fine = parametriThread[i].inizio + (DIMENSIONE / NUMERO_THREAD);
        }
        else
        {
            parametriThread[i].fine = parametriThread[i].inizio + (DIMENSIONE / NUMERO_THREAD) + 1;
            restoNumeri--;
        }
        pthread_create(&threadRicerca[i], NULL, &Ricerca, &parametriThread[i]);
    }

    // Chiusura thread
    for (int i = 0; i < NUMERO_THREAD; i++)
    {
        pthread_join(threadRicerca[i], NULL);
    }

    // Stampo se non ci sono state occorrenze
    if (occorrenzeNumero == 0)
    {
        printf("Numero non trovato\n");
    }
    return 0;
}
