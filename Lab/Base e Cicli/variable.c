#include <stdio.h>

void main()
{
    int numero1, numero2 = 30 /*Inizializzazione: assegnazione durante dichiarazione*/, somma, diff, prodotto, cont = 0;
    float var1, var2, somma2, quoz;
    numero1 = 10;
    somma = numero1 + numero2;
    printf("La somma tra interi e' %d\n", somma);
    // d decimal decimale (int)
    // f float reale (float)
    var1 = 2.75;
    var2 = 3.5;
    somma2 = var1 + var2;
    printf("La somma tra reali e' %.2f\n", somma2);
    quoz = (float)var1 / var2; // Casting
    printf("Il quoziente tra reali e' %.2f\n", quoz);
    diff = numero1 - numero2;
    printf("Il quoziente tra interi e' %d\n", diff);
    prodotto = numero1 * numero2;
    printf("Il prodotto tra interi e' %d\n", prodotto);
    cont++;
    printf("Il contatore è %d\n", cont);
}