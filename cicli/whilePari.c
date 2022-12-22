#include <stdio.h>

void main()
{
    /*
        Scrivi un programma in C che dopo aver letto N numeri calcoli
        la somma dei numeri pari
    */
    int numero, i, somma = 0, conunter = 0, pari = 0;
    printf("Quanti numeri vuoi leggere? ");
    scanf("%i", &i);
    printf("\n");
    do
    {
        i--;
        conunter++;
        printf("Inserici il %i° numero: ", conunter);
        scanf("%i", &numero);
        if (numero % 2 == 0){
            pari++;
            somma = somma + numero;
        }
    } while (i > 0);
    printf("\nLa somma è dei numeri pari (%i/%i) è : %i\n", pari, conunter, somma);
}