/*
    Creare un programma in C che genera una sequenza di 10.000 numeri casuali e li memorizza in un array;
    i numeri generati devono appartenere all’intervallo 1-500.
    Nel programma il processo padre genera due figli e la suddivisione dei compiti deve essere come segue:
        - Il padre genera i 10.000 numeri casuali.
        - Il padre salva tutti i numeri casuali in un file con il formato indice_array : valore
        - Il padre ricerca all’interno dei primi 2000 numeri dell’array un numero X inserito
            dall’utente a linea di comando e stampa a video la coppia indice_array : valore per tutte le coppie trovate;
            la stampa di ogni coppia deve essere preceduta dal pid del processo.
        - I due figli svolgono lo stesso compito del punto precedente dividendosi il lavoro a metà (4000 ricerche ciascuno).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define NUMERI 10000

void Popola(int *array, int l)
{
    for (int i = 0; i < l; i++)
    {
        *(array + i) = rand() % 500 + 1;
    }
}

void Salva(int *array, int l, FILE *f)
{
    for (int i = 0; i < l; i++)
    {
        fprintf(f, "%d : %d\n", i, *(array + i));
    }
}

int InserimentoNumero(int min, int max, int *n, char *testo)
{
    do
    {
        printf("%s", testo);
        scanf("%d", n);
    } while (*n < min || *n > max);
}

void Cerca(int *array, int start, int end, int n)
{
    for (int i = start; i < end; i++)
    {
        if (*(array + i) == n)
        {
            printf("%d : %d (%d)\n", i, n, getpid());
        }
    }
}

int main(int argc, char *argv[])
{
    srand(time(0));
    int numeri[NUMERI];
    int PID1, PID2;
    int n = atoi(argv[2]);
    if (argc != 3)
    {
        printf("Errore negli argomenti");
        exit(0);
    }
    FILE *f = fopen(argv[1], "w+");
    if (f == NULL)
    {
        printf("Impossibile aprire il file");
        exit(0);
    }
    Popola(numeri, NUMERI);
    Salva(numeri, NUMERI, f);
    PID1 = fork();
    if (PID1)
    {
        PID2 = fork();
    }
    if (!PID1)
    {
        // F1
        Cerca(numeri, 2000, 6000, n);
    }
    else if (!PID2)
    {
        // F2
        Cerca(numeri, 6000, 10000, n);
    }
    else
    {
        Cerca(numeri, 0, 2000, n);
    }
    fclose(f);
    return 0;
}