/*
    Esercizio 1
    Progettare un algoritmo che effettui la lettura da tastiera di una serie di coppie di valori numerici.
    L’algoritmo deve calcolare e stampare il rapporto tra il valore minore e quello maggiore dei due. Il
    programma termina quando uno dei due valori o entrambi sono uguali a zero.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    float primo, secondo, rapporto, temp;
    do
    {
        printf("Inserisci il primo numero: ");
        scanf("%f", &primo);
        printf("Inserisci il secondo numero: ");
        scanf("%f", &secondo);
        if (secondo < primo)
        {
            temp = primo;
            primo = secondo;
            secondo = temp;
        }
        rapporto = primo / secondo;
        printf("Il rapporto tra il maggiore ed il minore è di: %.2f\n\n", rapporto);
    } while (primo != 0 && secondo != 0);
    printf("Hai inserito 0\n");
    return 0;
}