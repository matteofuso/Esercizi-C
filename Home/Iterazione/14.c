/*
    Dati due numeri interi positivi N1 ed N2 calcolare, mediante la somma
    ripetuta, il prodotto dei due numeri e visualizzarli.
*/

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int N1, N2, prodotto = 0;
    bool negative;
    printf("Inserisci il primo numero: ");
    scanf("%d", &N1);
    printf("Inserisci il secondo numero: ");
    scanf("%d", &N2);
    if (N1 < 0)
    {
        negative = true;
        N1 = -N1;
    }
    while (N1 != 0)
    {
        prodotto += N2;
        N1--;
    }
    if (negative)
    {
        prodotto = -prodotto;
    }
    printf("Il prodotto vale %d\n", prodotto);
    return 0;
}