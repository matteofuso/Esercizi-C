/*
    Dato N un numero intero positivo, generare e visualizzare in ordine
    crescente i numeri compresi maggiori uguali di -N e minori uguali di N.
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
    printf("Ecco i numeri compresi tra -%d e %d:\n", N, N);
    for (int i = -N; i <= N; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}