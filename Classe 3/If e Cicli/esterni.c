/*
    Dopo aver letto N numeri reali calcolare la somma e la media dei numeri esterni all'intervallo 4 e 8, esterni esclusi
    estremi inclusi visualizzand a video i risulatati.
*/

#include <stdio.h>

void main()
{
    float num, somma = 0, media;
    int n, cont = 1, compresi = 0;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    while (cont <= n)
    {
        printf("Inserisci il %d numero: ", cont);
        scanf("%f", &num);
        if (num < 4 || num > 8)
        {
            compresi++;
            somma = somma + num;
        }
        cont++;
    }
    if (compresi == 0)
    {
        printf("Non ci sono numeri esterni all'intervallo 4 e 8\n");
    }
    else
    {
        media = somma / compresi;
        printf("\nLa somma è dei numeri esterni all'intervallo tra 4 e 8 è: %.2f\n", somma);
        printf("La media è delli stessi è: %.2f\n", media);
    }
}