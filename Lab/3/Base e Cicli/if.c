#include <stdio.h>
#include <math.h>

void main()
{
    int primo, secondo, scambio;
    printf("Inserisci il primo numero: ");
    scanf("%i", &primo);
    printf("Inserisci il secondo numero: ");
    scanf("%i", &secondo);
    if (secondo > primo)
    {
        scambio = primo;
        primo = secondo;
        secondo = scambio;
    }
    printf("Il numero maggiore è (%i) ed il minore (%i)\n", primo, secondo);
}