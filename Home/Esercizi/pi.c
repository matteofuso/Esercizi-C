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
    int scelta, iterazioni;
    double pi, raggio;
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
    if (scelta == 1)
    {
        // Formula di Leibniz
        // pi = 4/1 - 4/3 + 4/5 - 4/7 + 4/9 - ...
        for (int i = 0; i < iterazioni; i++)
        {
            // Alterno somma e sottrazione
            if (i % 2 == 0)
            {
                // Somma
                pi += 4 / (double)(2 * i + 1);
            }
            else
            {
                // Sottrazione
                pi -= 4 / (double)(2 * i + 1);
            }
        }
    }
    else
    {
        // Formula di Nilakantha
        // pi = 3 + 1/(1*2*3) - 1/(2*3*5) + 1/(3*4*7) - 1/(4*5*9)
        pi = 3;
        for (int i = 1; i < iterazioni; i++)
        {
            // Alterno somma e sottrazione
            if (i % 2 == 1)
            {
                // Somma
                pi += (double)1 / (i * (i + 1) * (2 * i + 1));
            }
            else
            {
                // Sottrazione
                pi -= (double)1 / (i * (i + 1) * (2 * i + 1));
            }
        }
    }
    printf("Il valore del pi greco calcolato è: %lf\n\n", pi);
    printf("Inserisci il raggio del cerchio: ");
    scanf("%lf", &raggio);
    printf("Il valore dell'area è %.2lf\n", pi * raggio * raggio);
    printf("Il valore della circonferenza è %.2lf\n\n", 2 * pi * raggio);
    return 0;
}