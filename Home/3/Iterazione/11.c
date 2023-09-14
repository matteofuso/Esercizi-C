/*
    Dato N un numero intero positivo, calcolare e visualizzare la somma dei
    primi N numeri dispari.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int N, somma = 0;
    do
    {
        printf("Inserisci un numero intero positvo: ");
        scanf("%d", &N);
    } while (N < 0);
    for (int i = 0; i < N; i++)
    {
        somma += 2 * i + 1;
    }
    printf("La somma vale %d\n", somma);
    return 0;
}