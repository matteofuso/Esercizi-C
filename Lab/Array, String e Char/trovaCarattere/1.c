/*
    Leggi una stringa (scanf) e un carattere e, se il carattere è presente
    nella stringa, conta quante volte quel carattere è contenuto nella stringa.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char find[1], str[100];
    int i, trovato = 0;
    printf("Inserisci la stringa: ");
    scanf("%s", str);
    printf("Inserisci il carattere da cercare: ");
    scanf("%s", find);
    for (i = 0; i < strlen(str); i++)
    {
        if (str[i] == find[0])
        {
            trovato++;
        }
    }
    if (trovato == 0)
    {
        printf("Non è stato trovato il carattere\n");
    }
    else
    {
        printf("Il carattere è stato trovato %d volte\n", trovato);
    }
    return 0;
}