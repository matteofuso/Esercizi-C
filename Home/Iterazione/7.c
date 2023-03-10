/*
    Dato N un numero intero positivo maggiore di 1, generare e visualizzare
    il numero precedente.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int N;
    do
    {
        printf("Inserisci un numero intero maggiore o uguale di 1: ");
        scanf("%d", &N);
    } while (N <= 0);
    N--;
    printf("Il numero precedente è %d\n", N);
    return 0;
}