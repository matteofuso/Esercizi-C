/*
    Scrivere un programma in C che dopo aver inserito N numeri interi in un vettore,
    alterni (o scambi ) a due a due le posizioni del vettore. Esempio:
    vettore inserito: 1,2,3,4  vettore alternato: 2,1,4,3.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i, temp;
    printf("Inserisci la lunghezza del vettore da inserire: ");
    scanf("%d", &n);
    int vect[n];
    for (i = 0; i < n; i++)
    {
        printf("Inserisci il numero in posizione %d: ", i + 1);
        scanf("%d", vect + i);
    }
    for (i = 0; i < n - n % 2; i += 2)
    {
        temp = vect[i];
        vect[i] = vect[i + 1];
        vect[i + 1] = temp;
    }
    for (i = 0; i < n; i++)
    {
        printf("L'array in posizione %d ha ora: %d\n", i + 1, vect[i]);
    }
    return 0;
}