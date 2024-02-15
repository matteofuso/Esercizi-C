/*
    Scrivi il codice sorgente di un programma che genera un processo
    PRODUTTORE, il quale
    _ genera cinque numeri interi random, compresi tra 0 e 99 incluso
    _ inserisce i numeri random in un vettore
    _ comunica il contenuto del vettore ad un processo CONSUMATORE
    attraverso una FIFO denominata sum
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

#define SIZE 5

int main(int argc, char **argv)
{
    // Apertura fifo
    int fifo = open("sum", O_WRONLY);
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

    // Tempo corrente come seed
    srand(time(NULL));

    // Generazione numeri
    printf("Invio dati\n");
    printf("DEC  HEX  CHAR\n");
    for (int *i = numeri; i - numeri < SIZE; i++)
    {
        *i = rand() % 100;
        printf("%02d   %02x   %c\n", *i, *i, *i);
    }

    // Invio dati
    if (write(fifo, numeri, sizeof(int) * SIZE) == -1)
    {
        printf("Errore durante la scrittura nella FIFO\n");
        exit(-3);
    }

    // Chiusura
    close(fifo);
    free(numeri);
    return 0;
}