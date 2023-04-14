/*
    Leggere in input da tastiera due numeri maggiori di 0 e farne la somma.
*/

#include <stdio.h>

int somma(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    int a, b;
    do
    {
        printf("Inserisci il primo numero (Maggiore di 0): ");
        scanf("%d", &a);
    } while (a <= 0);
    do
    {
        printf("Inserisci il secondo numero (Maggiore di 0): ");
        scanf("%d", &b);
    } while (b <= 0);
    printf("La somma è %d\n", somma(a, b));
    return 0;
}