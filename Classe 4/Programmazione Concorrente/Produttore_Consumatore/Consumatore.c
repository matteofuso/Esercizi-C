/*
    Scrivi il codice sorgente di un programma che genera un processo
    CONSUMATORE, il quale
    _ legge il contenuto del vettore
    _ calcola la somma dei numeri del vettore e la visualizza
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

#define SIZE 5

int main(int argc, char **argv)
{
    // Apertura fifo
    int fifo = open("sum", O_RDONLY);
    int somma = 0;
    if (fifo == -1)
    {
        printf("Errore nell'apertura della FIFO\n");
        exit(-1);
    }

    // Allocazione memoria per l'array
    int *numeri = (int *)malloc(sizeof(int) * SIZE);
    if (numeri == NULL)
    {
        printf("Errore nell'allocazione di memoria nell'array\n");
        exit(-2);
    }

    // Ricezione dati e somma
    if (read(fifo, numeri, sizeof(int) * SIZE) == -1)
    {
        printf("Errore durante la lettura nella FIFO\n");
        exit(-3);
    }

    // Lettura numeri
    printf("Ricezione dati\n");
    printf("DEC  HEX  CHAR\n");
    for (int *i = numeri; i - numeri < SIZE; i++)
    {
        somma += *i;
        printf("%02d   %02x   %c\n", *i, *i, *i);
    }
    // Visualizzo la somma
    printf("\nLa somma dei numeri ricevuti è %d\n", somma);

    // Chiusura
    close(fifo);
    free(numeri);
    return 0;
}