#include <stdio.h>

void main()
{
    /*
        Scrivere un programma in c che dopo aver richiesto all'utente quanti numeri inserire,
        ne calcola la somma e la visualizza a video
    */
    float numero, somma = 0;
    int i, conunter = 0;
    printf("Quanti numeri vuoi leggere? ");
    scanf("%i", &i);
    printf("\n");
    do
    {
        i--;
        conunter++;
        printf("Inserici il %i° numero: ", conunter);
        scanf("%f", &numero);
        somma = somma + numero;
    } while (i > 0);
    printf("\nLa somma è di: %.2f\n", somma);
    printf("La media è di %.2f\n", somma / conunter);
}