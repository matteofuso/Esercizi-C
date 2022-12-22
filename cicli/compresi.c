#include <stdio.h>

void main()
{
    /*
        Dopo aver letto N numeri reali calcolare la somma e la media dei numeri compresi tra 4 e 8
        estremi inclusi visualizzand a video i risulatati.
    */
    float numero, somma = 0;
    int i, conunter = 0, compresi = 0;
    printf("Quanti numeri vuoi leggere? ");
    scanf("%i", &i);
    printf("\n");
    do
    {
        i--;
        conunter++;
        printf("Inserici il %i° numero: ", conunter);
        scanf("%f", &numero);
        if (numero > 4 && numero < 8){
            compresi++;
            somma = somma + numero;
        }
    } while (i > 0);
    printf("\nLa somma è dei numeri compresi tra 4 e 8 (%i/%i) è : %.2f\n", compresi, conunter, somma);
    printf("La media è delli stessi è: %.2f\n", somma / compresi);
}