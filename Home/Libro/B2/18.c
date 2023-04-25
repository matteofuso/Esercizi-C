/*
    Codificare utilizzando i puntatori una funzione in linguaggio C che, a partire
    da due stringhe di caratteri fornite come argomento, copi nella seconda il
    contenuto della prima eliminando tutti gli spazi.
*/

#include <stdio.h>
#include <string.h>

void add(char *str, char c)
{
    int i = strlen(str);
    *(str + i) = *(str + i - 1);
    *(str + i - 1) = c;
}

int main(int argc, char *argv[])
{
    char s[100];
    char *p = argv[1];
    if (argc != 3)
    {
        printf("Errore negli argomenti!\n");
        return 0;
    }
    while (*p != 0)
    {
        if (*p != ' ')
        {
            add(s, *p);
        }
        p++;
    }
    printf("Prima: %s, Seconda: %s\n", argv[1], s);
    return 0;
}