#include <stdio.h>

// Definisco delle costanti con i colori
// https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences#text-formatting
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

int main(int argc, char *argv[])
{
    // Dichiaro e inizializzo le variabili e le costanti
    const int MIN = 30, MAX = 50;
    int limite1, limite2, n[5], somma = 0;
    // Chiedo di inserire i limiti finchè non sono compresi tra MIN e MAX
    do
    {
        // Chiedo i limiti
        printf("Inserisci due numeri interi compresi tra %d e %d\n", MIN, MAX);
        printf("Inserisci il primo limite: ");
        scanf("%d", &limite1);
        printf("Inserisci il secondo limite: ");
        scanf("%d", &limite2);
        printf("\n");
        // Controllo se sono compresi
    } while (limite1 < MIN || limite1 > MAX || limite2 < MIN || limite2 > MAX);
    // Faccio in modo che limite1 sia sempre il minore e che limite2 sia sempre il maggiore
    if (limite1 > limite2)
    {
        // Eseguo lo swap
        n[0] = limite1;
        limite1 = limite2;
        limite2 = n[0];
    }
    // Stampo i limiti
    printf("Limite inferiore = %d\n", limite1);
    printf("Limite inferiore = %d\n\n", limite2);
    // Chiedo di inserire 5 numeri e li salvo nell'array
    printf("Inserisci 5 numeri interi\n\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Inserisci il %d^ numero: ", i + 1);
        scanf("%d", n + i);
        // Controllo se il numero è compreso tra i limiti
        if (n[i] >= limite1 && n[i] <= limite2)
        {
            somma += n[i];
        }
    }
    // Stampo i valori
    printf("\nQuesti sono i valori inseriti:\n");
    for (int *i = n; i < n + 5; i++)
    {
        // Se il numero è compreso tra i limiti lo stampo in verde
        if (*i >= limite1 && *i <= limite2)
        {
            printf(GREEN);
        }
        printf("%d%s\n", *i, RESET);
    }
    // Stampo la somma dei numeri che soddisfano la richiesta
    if (somma != 0)
    {
        printf("Somma dei numeri compresi tra %d e %d è %d\n\n", limite1, limite2, somma);
    }
    else
    {
        printf("Non ci sono numeri compresi tra %d e %d\n\n", limite1, limite2);
    }
    return 0;
}