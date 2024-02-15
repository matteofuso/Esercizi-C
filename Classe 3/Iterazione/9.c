/*
    Dati due numeri interi e positivi N1 e N2 con N2>N1, generare e
    visualizzare in ordine decrescente i numeri compresi tra N1 e N2.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int N1, N2;
    do
    {
        do
        {
            printf("Inserisci N1, un numero intero positivo: ");
            scanf("%d", &N1);
        } while (N1 <= 0);
        do
        {
            printf("Inserisci N2, un numero intero positivo e maggiore di %d: ", N1);
            scanf("%d", &N2);
        } while (N2 <= 0);
    } while (N1 >= N2);
    do
    {
        N2--;
        printf("%d\n", N2);
    } while (N1 != N2 - 1);
    return 0;
}