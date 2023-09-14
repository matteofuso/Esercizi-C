/*
    La Successione di Fibonacci
    In matematica, la successione di Fibonacci è una successione di numeri interi in cui
    ciascun numero è la somma dei due precedenti, ad eccezione dei primi due, che sono 0 e 1.
    La serie di fibonacci può essere usate per approsimare la conversione tra miglia e km.
    Prendiamo per esempio 5 e 8, 8km = 5mi.

    Sapendo questo chiedi all'utente l'unità di misura di partenza e successivamente trova il numero della serie
    più vicino e stampa la conversione.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int p = 0, s = 1, n;
    char unita[2] = "km";
    // Chiedo l'unità di misura di partenza
    do
    {
        printf("Inserisci l'unità di misura di partenza (km/mi): ");
        scanf("%s", unita);
    } while (strcmp("km", unita) != 0 && strcmp("mi", unita) != 0);
    // Chiedo il numero di km o mi
    do
    {
        printf("Inserisci il numero di %s: ", unita);
        scanf("%d", &n);
    } while (n < 1);
    // Trovo dove n è compreso
    while (p < n && s < n)
    {
        int tmp = p + s;
        p = s;
        s = tmp;
    }
    // Trovo il numero più vicino e lo assegno a p
    if (n - p > s - n)
    {
        int tmp = p + s;
        p = s;
        s = tmp;
    }
    // Stampo la risposta
    if (strcmp("mi", unita) == 0)
    {
        // Da miglia a chilometri, prendo il successivo
        printf("%d %s sono circa %d km\n", n, unita, s);
    }
    else
    {
        // Da chilometri a miglia, prendo il precedente
        printf("%d %s sono circa %d mi\n", n, unita, s - p);
    }
    return 0;
}