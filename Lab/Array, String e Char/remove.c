/*
    Scrivere un programma in C che dopo aver inserito una stringa ed un carattere  da linea comando,
    elimini il carattere inserito dalla stringa stessa (se esistente).
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, j;
    if (argc != 3)
    {
        printf("Errore negli argomenti.\n");
        return 0;
    }
    if (strlen(argv[2]) != 1)
    {
        printf("Il secondo argomento deve essere un carattere.\n");
        return 0;
    }
    for (i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] == argv[2][0])
        {
            for (j = i; j < strlen(argv[1]); j++)
            {
                argv[1][j] = argv[1][j + 1];
            }
            i--;
        }
    }
    printf("La stringa senza il carattere %c è %s\n", argv[2][0], argv[1]);
    return 0;
}