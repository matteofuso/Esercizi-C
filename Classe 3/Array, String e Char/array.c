// Inserimento vettore e visualizzazione elementi

#include <stdio.h>

int main(int argc, char *argv[])
{
    int n, i, v[100];
    do
    {
        printf("Quanti elementi vuoi inserire? ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);
    for (i = 0; i < n; i++)
    {
        printf("Inserire un numero alla posizione %d: ", i + 1);
        scanf("%d", &v[i]);
    }
    printf("Il vettore inserito è il seguente: [ %d", v[0]);
    for (i = 1; i < n; i++)
    {
        printf(", %d", v[i]);
    }
    printf(" ]\n\n");
    return 0;
}