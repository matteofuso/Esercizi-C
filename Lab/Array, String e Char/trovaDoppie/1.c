/*
    Leggi una stringa e verifica se contiene doppie
    (sempre con il doppio metodo di lettura descritto nel esercizio 1)
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char str[100];
    int doppie = 0;
    printf("Inserisci la stringa da controllare: ");
    scanf("%s", str);
    for (int i = 0; i < strlen(str) - 1; i++)
    {
        if (str[i] == str[i + 1] && str[i] != str[i - 1])
        {
            doppie++;
        }
    }
    if (doppie != 0)
    {
        printf("Nella stringa %s ci sono %d doppie\n", str, doppie);
    }
    else
    {
        printf("Nella stringa %s non ci sono doppie\n", str);
    }
    return 0;
}