/*
    Dato N un numero intero positivo, calcolare e visualizzare la somma dei
    primi N numeri interi.
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
    while (N > 0)
    {
        somma += N;
        N--;
    }
    printf("La somma dei numeri precedenti è: %d\n", somma);
    return 0;
}