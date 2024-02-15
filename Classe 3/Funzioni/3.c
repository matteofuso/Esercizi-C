/*
    Si crei un programma che nel momento dell'esecuzione popoli l'array
    argv[] con una serie di numeri. Esempio: $ ./a.out 1 5 9 6
    Il programma deve quindi chiedere in input un numero e deve cercarlo
    all'interno dell'array argv.
    Se il numero è presente il programma deve dare un messaggio positivo
    e deve mostrare la posizione dell'elemento, altrimenti deve stampare a
    video: "numero non presente"
    Suggerimento: si usi una funzione per ricercare la posizione dell'
    elemento. Tale funzione deve tornare la posizione oppure -1.
*/

#include <stdio.h>
#include <stdlib.h>

int in(int argc, char *argv[], int n, int start)
{
    for (int i = start; i < argc; i++)
    {
        if (atoi(argv[i]) == n)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    int n;
    printf("Inserisci il numero da cercare nell'array: ");
    scanf("%d", &n);
    n = in(argc, argv, n, 1);
    if (n == -1)
    {
        printf("Numero non trovato\n");
    }
    else
    {
        printf("Numero trovato in posizione %d\n", n);
    }
    return 0;
}