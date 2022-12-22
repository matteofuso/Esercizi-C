#include <stdio.h>

void main()
{
    /*
    Esercizio 2: Dopo aver letto in input il valore di un lato di un quadrato,
    calcolare il perimetro e l'area, visualizzando a video i risultati
    */
    float lato;
    printf("Inserisci il lato del quadrato: ");
    scanf("%f", &lato);
    printf("L'area e': %.2f\n", lato * lato);
    printf("Il perimetro e': %.2f\n", 4 * lato);
}