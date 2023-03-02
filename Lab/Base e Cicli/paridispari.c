#include <stdio.h>

void main()
{
    int primo, secondo;
    printf("Inserisci il primo numero: ");
    scanf("%i", &primo);
    printf("Inserisci il secondo numero: ");
    scanf("%i", &secondo);
    printf("I numeri pari sono:");
    if (primo % 2 == 0)
    {
        printf(" Primo");
    }
    if (secondo % 2 == 0)
    {
        printf(" Secondo");
    }
    printf("\n");
}