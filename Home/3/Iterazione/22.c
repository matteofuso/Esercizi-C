/*
    Dato un numero N calcolare e visualizzare tutte le coppie di numeri minori di N che
    danno per somma il numero stesso. Non considerare la proprietà commutativa.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int N;
    do
    {
        printf("Inserisci un numero intero positvo: ");
        scanf("%d", &N);
    } while (N < 0);
    for (int i = 0; i < N / 2 + 1; i++)
    {
        printf("%d + %d = %d\n", i, N - i, N);
    }
    return 0;
}