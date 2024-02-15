/*
    Leggere in input da tastiera due numeri maggiori di 0 e farne la somma.
*/

#include <stdio.h>

int input(char num[])
{
    int n;
    do
    {
        printf("Inserisci il %s numero (Maggiore di 0): ", num);
        scanf("%d", &n);
    } while (n <= 0);
    return n;
}

int somma(int a, int b)
{
    return a + b;
}

int main(int argc, char *argv[])
{
    printf("La somma è %d\n", somma(input("secondo"), input("primo")));
    return 0;
}