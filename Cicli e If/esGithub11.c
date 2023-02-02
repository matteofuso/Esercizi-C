#include <stdio.h>
#include <stdlib.h>

/*
    Scrivi un programma che legge da argv[1] un numero intero positivo (N) e poi
    disegna a terminale un quadrato vuoto composto di asterischi (‘*’)
    con il lato lungo N:

    Per N pari a 3 il programma stampa:

    ***
    * *
    ***
    Per N pari a 5 il programma stampa:

    *****
    *   *
    *   *
    *   *
    *****
*/

int main(int argc, char *argv[])
{
    int N;
    const char carattere = '*';
    if (argc != 2)
    {
        printf("Errore negli argomenti dati. Ne hai inseriti %d invede ci 1!\n", argc--);
        return 0;
    }
    N = atoi(argv[1]);
    if (N <= 0)
    {
        printf("Impossibile stampare un quadrato con lati minori o uguali a zero\n");
        return 0;
    }
    // Print top base
    for (int i = 0; i < N; i++)
    {
        printf("%c", carattere);
    }
    printf("\n");
    // Print sides
    for (int i = 0; i < N - 2; i++)
    {
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
            {
                printf("%c", carattere);
            }
            else if (i != N - 1)
            {
                printf(" ");
            }
            else
            {
                printf("%c", carattere);
            }
        }
        printf("\n");
    }
    // Print bottom faces
    for (int i = 0; i < N; i++)
    {
        printf("%c", carattere);
    }
    printf("\n");
    return 0;
}