#include <stdio.h>
#include <string.h>

int indexOf(char *stringa, char carattere)
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == carattere)
        {
            return i;
        }
    }
    return -1;
}

int main(int argc, char *argv[])
{
    char stringa[100], carattere;
    int i;
    printf("Inserisci la stringa: ");
    scanf("%s", stringa);
    printf("Inserisci il carattere da cercare: ");
    scanf(" %c", &carattere);
    i = indexOf(stringa, carattere);
    if (i != -1)
    {
        printf("Il carattere è presente alla posizione %d\n", i);
    }
    else
    {
        printf("Il carattere non è presente\n");
    }
    return 0;
}