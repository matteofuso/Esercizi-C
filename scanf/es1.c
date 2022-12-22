#include <stdio.h>

void main()
{
    /*
    Esercizio 1: Dopo aver letto in input il valore della base e dell'altezza
    di un rettangolo, calcolare il perimetro e l'area, visualizzando a video i risultati
    */
    float base, altezza;
    printf("Inserisci la base: ");
    scanf("%f", &base);
    printf("Inserisci l'altezza: ");
    scanf("%f", &altezza);
    printf("L'area e': %.2f\n", base * altezza);
    printf("Il perimetro e': %.2f\n", (base + altezza) * 2);
}