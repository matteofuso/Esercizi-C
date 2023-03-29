/*
    Scrivere un programma in C che dopo aver inserito N numeri interi in un vettore,
    determini:
    1) il massimo ed il minimo dei numeri pari inseriti;
    2) il massimo ed il minimo dei numeri dispari inseriti;
    3) le posizioni di inserimento dei numeri precedentemente determinati.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int N, i, maxPari[2], maxDispari[2], minPari[2], minDispari[2];
    do
    {
        printf("Inserisci quanti elementi vuoi nel vettore: ");
        scanf("%d", &N);
    } while (N < 1);
    int vect[N];
    for (i = 0; i < N; i++)
    {
        printf("Inserisci il %d° numero: ", i + 1);
        scanf("%d", vect + i);
    }
    maxPari[1] = -1;
    maxDispari[1] = -1;
    minPari[1] = -1;
    minDispari[1] = -1;
    for (i = 1; i < N; i++)
    {
        if (N % 2 == 0)
        {
            if (maxPari[1] == -1)
            {
                maxPari[0] = vect[i];
                maxPari[1] = i;
                minPari[0] = vect[i];
                minPari[1] = i;
            }
            else
            {
                if (vect[i] > maxPari[0])
                {
                    maxPari[0] = vect[i];
                    maxPari[1] = i;
                }
                else if (vect[i] < minPari[0])
                {
                    minPari[0] = vect[i];
                    minPari[1] = i;
                }
            }
        }
        else
        {
            if (maxDispari[1] == -1)
            {
                maxDispari[0] = vect[i];
                maxDispari[1] = i;
                minDispari[0] = vect[i];
                minDispari[1] = i;
            }
            if (vect[i] > maxDispari[0])
            {
                minPari[0] = vect[i];
                minPari[1] = i;
            }
            else if (vect[i] < minDispari[0])
            {
                minDispari[0] = vect[i];
                minDispari[1] = i;
            }
        }
    }
    printf("Il numero pari minore è %d e si trova alla posizione %d", minPari[0], minPari[1]);
    printf("Il numero pari maggiore è %d e si trova alla posizione %d", maxPari[0], maxPari[1]);
    printf("Il numero dispari minore è %d e si trova alla posizione %d", minDispari[0], minDispari[1]);
    printf("Il numero dispari maggiore è %d e si trova alla posizione %d", maxDispari[0], maxDispari[1]);
    return 0;
}