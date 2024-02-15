/*
    Dato N un numero intero positivo, generare e visualizzare in ordine crescente i primi N numeri
    interi positivi.
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
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", i);
    }
    return 0;
}