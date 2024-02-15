/*
    Dati due numeri interi positivi N1 e N2, verificare se N1 è il quadrato
    di N2.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int N1, N2;
    do
    {
        printf("Inserisci N1, un numero intero positvo: ");
        scanf("%d", &N1);
    } while (N1 < 0);
    do
    {
        printf("Inserisci N2, un numero intero positvo: ");
        scanf("%d", &N2);
    } while (N2 < 0);
    if (N2 * N2 == N1)
    {
        printf("N2 è il quadrato di N1\n");
    }
    else
    {
        printf("N2 non è il quadrato di N1\n");
    }
    return 0;
}