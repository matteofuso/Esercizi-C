/*
    Dato un numero intero positivo N verificare se N è un numero primo.
*/

#include <stdio.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int N;
    do
    {
        printf("Inserisci un numero intero positvo: ");
        scanf("%d", &N);
    } while (N < 0);
    for (int i = 1; i < N; i++)
    {
        if (N % i == 0)
        {
            printf("Il numero non è primo.\n");
            return 0;
        }
    }
    printf("Il numero è primo.\n");
    return 0;
}