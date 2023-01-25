/*
    Progettare un algoritmo che effettui la lettura da tastiera di una serie
    di coppie di valori numerici reali (sia positivi che negativi che zero).
    Per ciascuna coppia, l’algoritmo deve calcolare e stampare il valore
    della radice quadrata del rapporto tra il valore maggiore e quello
    minore dei due. Il programma termina quando vengono inseriti dei valori
    che non permettono di svolgere il calcolo nel dominio dei numeri reali.
    Il programma prima di terminare si richiede di stampare un messaggio che indichi la
    ragione per cui non è stato possibile svolgere il calcolo.
*/

#include <stdio.h>
#include <math.h>

int main(int argc, char *argv[])
{
    int primo, secondo, temp, CE;
    double operazione;
    do
    {
        CE = 1;
        printf("Inserisci il primo numero: ");
        scanf("%i", &primo);
        printf("Inserisci il secondo numero: ");
        scanf("%i", &secondo);
        if (secondo > primo)
        {
            temp = primo;
            primo = secondo;
            secondo = temp;
        }
        if (secondo != 0)
        {
            operazione = (float)primo / (float)secondo;
            if (operazione >= 0)
            {
                operazione = sqrt(operazione);
                printf("La radice del rapporto tra maggiore e minore di questa coppia è %.2f\n\n", operazione);
            } else {
                CE = 0;
            }
        }
        else
        {
            CE = 0;
        }
    } while (CE);
    printf("La coppia di numeri che hai inserito non rispetta il dominio.\n");
    return 0;
}