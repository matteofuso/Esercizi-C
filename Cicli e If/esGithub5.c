#include <stdio.h>

/*
    Progettare un algoritmo che effettui le seguenti operazioni:
    • continui a leggere da tastiera una serie di terne di valori interi A ,
    B e C finchè non vengono inseriti dei valori tali per cui A + B < C
    • conteggi il numero di volte in cui la differenza tra A e B è pari, dispari, e quando è nulla
    • prima di terminare, visualizzi il valore dei valori conteggiati
*/

int main(int argc, char *argv[])
{
    int primo, secondo, terzo, diff;
    int counterPari = 0, counterDispari = 0, counterZero = 0, counter = 0;
    do
    {
        printf("Inserisci una terna di valori separati da un -:\n");
        scanf("%i-%i-%i", &primo, &secondo, &terzo);
        diff = primo - secondo;
        counter++;
        if (diff == 0)
        {
            counterZero++;
        }
        else
        {
            if (diff % 2 == 0)
            {
                counterPari++;
            }
            else
            {
                counterDispari++;
            }
        }
    } while (primo + secondo >= terzo);
    printf("Della differenza tra il primo ed il secondo nelle %i terne:\n-%i volte è pari\n-%i volte è dispari\n- %i volte è nulla\n", counter, counterPari, counterDispari, counterZero);
    return 0;
}