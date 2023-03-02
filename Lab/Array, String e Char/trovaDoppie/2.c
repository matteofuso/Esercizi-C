/*
    Leggi una stringa e verifica se contiene doppie
    (sempre con il doppio metodo di lettura descritto nel esercizio 1)
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 2){
        printf("Errore negli argomenti\n");
        return 0;
    }
    int doppie = 0;
    for (int i = 0; i < strlen(argv[1]) - 1; i++)
    {
        if (argv[1][i] == argv[1][i + 1] && argv[1][i] != argv[1][i - 1])
        {
            doppie++;
        }
    }
    if (doppie != 0)
    {
        printf("Nella stringa %s ci sono %d doppie\n", argv[1], doppie);
    }
    else
    {
        printf("Nella stringa %s non ci sono doppie\n", argv[1]);
    }
    return 0;
}