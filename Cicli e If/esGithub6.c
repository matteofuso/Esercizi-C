#include <stdio.h>

/*
    Progettare un algoritmo che effettui le seguenti operazioni:
    • legga da tastiera una coppia di valori interi A e B con A<B;
    • continui a leggere da tastiera una serie di valori interi, terminando
    quando il valore letto è al di fuori dell’intervallo [A, B];
    • conteggi la media dei valori letti;
    • prima di terminare, stampi il valore calcolato.
*/

int main(int argc, char *argv[])
{
    float a, b, tmp, numero = 0, somma = 0, media;
    int i = 0;
    printf("Inserisci l'intervallo separato da un-:\n");
    scanf("%f-%f", &a, &b);
    if (a > b)
    {
        tmp = b;
        b = a;
        a = tmp;
    }
    while (1)
    {
        printf("Inserisci un numero: ");
        scanf("%f", &numero);
        if (numero > a && numero < b)
        {
            i++;
            somma += numero;
        }
        else
        {
            break;
        }
    }
    if (i == 0)
    {
        printf("Non hai inserito nessun numero nell'intervallo");
    }
    else
    {
        media = somma / i;
        printf("La media dei numeri compresi nell'intervallo %.2f-%.2f è %.2f\n", a, b, media);
    }
    return 0;
}