/*
    Calcolare il Pi Greco:
    Chiedere all'utente con che formula calcolare il pi greco:
    1. Formula di Leibniz
        pi/4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
        Per calcolare il pi greco basterà moltiplicare quindi tutto per 4
        pi = 4/1 - 4/3 + 4/5 - 4/7 + 4/9 - ...
        Da notare come il denominatore aumenta sempre di due e che si alternano somma e sottrazione
    2. Formula di Nilakantha
        pi - 3 = 1/(1*2*3) - 1/(2*3*5) + 1/(3*4*7) - 1/(4*5*9)
        Da cui si ricava
        pi = 3 + 1/(1*2*3) - 1/(2*3*5) + 1/(3*4*7) - 1/(4*5*9)
        Da notare come al denominatore, il primo numero sia uguale a quello centrale della frazione precedente,
        seguito da n+1 e da n+i. Si nota inoltre l'alternarsi di somma e sottrazione
    Chiedere all'utente quante volte eseguire il ciclo

    Infine, dopo aver chiesto all'utente il raggio di un cerchio, calcolane l'area e la circonferenza.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int scelta, iterazioni, n = 1, d, segno = 1;
    double pi = 3, raggio;
    // Stampo i vari metodi disponibili
    printf("Con che metodo vuoi calcolare il pi greco?\n");
    printf("1. Formula di Leibniz\n");
    printf("2. Formula di Nilakantha\n\n");
    // Chiedo quale utilizzare
    do
    {
        printf("Inserisci la scelta: ");
        scanf("%d", &scelta);
    } while (scelta < 1 || scelta > 2);
    // Chiedo il numero di iterazioni
    do
    {
        printf("\nInserisci il numero di volte di esecuzione del ciclo: ");
        scanf("%d", &iterazioni);
    } while (iterazioni < 1);
    // Inizializzo le variabili
    if (scelta == 1)
    {
        n = 4;
        pi = 4;
        d = 3;
        segno = -1;
    }
    // Calcolo il pi greco
    for (int i = 1; i < iterazioni; i++)
    {
        if (scelta == 2)
        {
            d = i * (i + 1) * (2 * i + 1);
        }
        pi += segno * n / (double)d;
        segno *= -1;
        d += 2;
    }
    // Stampo il valore approsimativo del pi greco
    printf("Il valore del pi greco calcolato è: %.15lf\n\n", pi);
    // Chiedo il raggio del cerchio
    do
    {
        printf("Inserisci il raggio del cerchio: ");
        scanf("%lf", &raggio);
    } while (raggio <= 0);
    // Stampo il perimetro e l'area
    printf("Il valore dell'area è %.2lf\n", pi * raggio * raggio);
    printf("Il valore della circonferenza è %.2lf\n\n", 2 * pi * raggio);
    return 0;
}