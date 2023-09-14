/*
    Dato N un numero intero positivo, generare e visualizzare in ordine
    decrescente i primi N numeri interi positivi.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int N;
    do
    {
        printf("Inserisci un numero intero positivo: ");
        scanf("%d", &N);
    } while (N <= 0);
    printf("Ecco i primi %d numeri interi positivi in ordine decrescente:\n", N);
    do
    {
        printf("%d\n", N);
        N--;
    } while (N > 0);
    return 0;
}