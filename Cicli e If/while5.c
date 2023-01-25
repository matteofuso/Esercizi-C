#include <stdio.h>

void main()
{
    /*
        Scrivi un programma in C che dopo aver letto N numeri calcoli
        la somma e la media dei numeri maggiori di 5
    */
    float numero, somma = 0;
    int i, conunter = 0, maggiori = 0;
    printf("Quanti numeri vuoi leggere? ");
    scanf("%i", &i);
    printf("\n");
    do
    {
        i--;
        conunter++;
        printf("Inserici il %i° numero: ", conunter);
        scanf("%f", &numero);
        if (numero > 5){
            maggiori++;
            somma = somma + numero;
        }
    } while (i > 0);
    printf("\nLa somma è dei numeri maggiori di 5 (%i/%i) è : %.2f\n", maggiori, conunter, somma);
    printf("La media è delli stessi è: %.2f\n", somma / maggiori);
}