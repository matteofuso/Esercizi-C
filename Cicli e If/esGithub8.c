#include <stdio.h>
#include <math.h>

/*
    Progettare un algoritmo che risolve il seguente problema. Si desidera
    calcolare la somma delle radici quadrate di N valori numerici inseriti
    dall’utente, con N inserito in input.
    L’algoritmo deve stampare la somma calcolata. L’algoritmo deve terminare
    con un messaggio di errore quando viene inserito un numero che non
    permette di effettuare il calcolo (nel dominio dei numeri reali).
*/

int main(int argc, char *argv[])
{
    int n;
    float num, sum = 0;
    printf("Inserisci quanti numeri vuoi chiedere: ");
    scanf("%i", &n);
    for (int i = 1; i <= n; i++)
    {
        printf("Inserisci il numero %i: ", i);
        scanf("%f", &num);
        if (num < 0)
        {
            printf("Impossibile fare la radice di %f", num);
            num = -1;
            break;
        }
        sum += sqrt(num);
    }
    if (num != -1)
    {
        printf("La somma delle radici dei numeri inseriti è %.2f\n", sum);
    }
    return 0;
}