#include <stdio.h>

int main(int argc, char *argv[])
{
    // Dichiaro e inizializzo le variabili e le costanti
    const int MIN = 30, MAX = 50;
    int limite1, limite2, n, somma = 0;
    // Chiedo di inserire i limiti finchè non sono compresi tra MIN e MAX
    do
    {
        // Chiedo i limiti
        printf("Inserire 2 numeri interi compresi tra limite 1 = %d e limite2 = %d\n", MIN, MAX);
        printf("Inserire il primo limite: limite1 >> ");
        scanf("%d", &limite1);
        printf("Inserire il secondo limite: limite2 >> ");
        scanf("%d", &limite2);
        printf("\n");
        // Controllo se sono compresi
    } while (limite1 < MIN || limite1 > MAX || limite2 < MIN || limite2 > MAX);
    // Faccio in modo che limite1 sia sempre il minore e che limite2 sia sempre il maggiore
    if (limite1 > limite2)
    {
        // Eseguo lo swap
        n = limite1;
        limite1 = limite2;
        limite2 = n;
    }
    // Stampo i limiti
    printf("Limite inferiore = %d\n", limite1);
    printf("Limite inferiore = %d\n\n", limite2);
    // Chiedo di inserire 5 numeri
    printf("Inserire 5 numeri interi\n\n");
    printf("Se saranno compresi tra il limite inferiore = %d e il limite superiore = %d, allora verranno sommati tra loro\n\n", limite1, limite2);
    for (int i = 1; i <= 5; i++)
    {
        printf("Inserire il %d^ numero intero >> ", i);
        scanf("%d", &n);
        printf("\n");
        // Controllo se il numero è compreso tra i limiti
        if (n >= limite1 && n <= limite2)
        {
            somma += n;
        }
    }
    // Stampo la somma dei numeri che soddisfano la richiesta
    printf("Somma dei numeri compresi tra %d e %d = %d\n", limite1, limite2, somma);
    return 0;
}