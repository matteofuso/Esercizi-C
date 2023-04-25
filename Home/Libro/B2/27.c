/*
    Codificare una funzione in linguaggio C che copi il contenuto di una stringa al termine
    del contenuto di un'altra stringa (concatenazione) utilizzando i puntatori invece che l'indicizzazione.
    Realizzare un programma in linguaggio C che fornisca in output dopo averla costruita invocando la
    funzione precedente la concatenazione di due stringhe fornite in input.
*/

#include <stdio.h>
#include <string.h>

void concat(char *p, char *s)
{
    int i = strlen(p);
    while (*s != 0)
    {
        *(p + i) = *s;
        s++;
        i++;
    }
}

int main(int argc, char *argv[])
{
    char p[200] = {0}, s[100];
    printf("Inserisci la prima stringa: ");
    scanf("%s", p);
    printf("Inserisci la seconda stringa: ");
    scanf("%s", s);
    concat(p, s);
    printf("Le stringhe concatenate sono: %s\n", p);
    return 0;
}