/*
    Leggi una stringa (scanf) e un carattere e, se il carattere è presente
    nella stringa, conta quante volte quel carattere è contenuto nella stringa.
*/

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Errore negli argomenti\n");
        return 0;
    }
    if (strlen(argv[2]) != 1)
    {
        printf("Il secondo argomento deve essere un carattere\n");
        return 0;
    }
    int i, trovato = 0;
    for (i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] == argv[2][0])
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