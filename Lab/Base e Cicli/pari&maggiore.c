/*
    Dopo aver letto N numeri reali calcolare la somma e la media dei
    numeri pari maggiori di 5 visualizzando a video i risultati.
*/

#include <stdio.h>

void main()
{
    int times, num, somma = 0, i = 1, soddisfanti = 0;
    float media;
    printf("Inserisci quanti numeri leggere: ");
    scanf("%i", &times);
    while (i <= times)
    {
        printf("Inserisci il %i numero: ", i);
        scanf("%i", &num);
        if (num % 2 == 0 && num > 5)
        {
            somma += num;
            soddisfanti++;
        }
        i++;
    }
    if (soddisfanti == 0)
    {
        printf("Non hai inserito numeri pari e maggiori di 5\n");
    }
    else
    {
        media = somma / soddisfanti;
        printf("Hai inserito %i numeri su %i che sono pari e maggiori di 5.\n", soddisfanti, i);
        printf("Di questi la somma è %i e la media è %.2f\n", somma, media);
    }
}