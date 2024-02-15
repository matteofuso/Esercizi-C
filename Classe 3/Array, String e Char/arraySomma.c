// Inserimento vettore e visualizzazione elementi + somma e media

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i, somma = 0, v[100];
    float media;
    do
    {
        printf("Quanti elementi vuoi inserire? ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    for (i = 0; i < n; i++)
    {
        printf("Inserire un numero alla posizione %d: ", i + 1);
        scanf("%d", &v[i]);
        somma += v[i];
    }
    media = (float)somma / n;
    printf("Il vettore inserito è il seguente: [ %d", v[0]);
    for (i = 1; i < n; i++)
    {
        printf(", %d", v[i]);
    }
    printf(" ]\n");
    printf("La somma del vettore è %d\n", somma);
    printf("La media del vettore è %.2f\n\n", media);
    return 0;
}