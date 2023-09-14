#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int StringNotValid(char string[])
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (!isalpha(string[i]))
        {
            return 1;
        }
    }
    return 0;
}

void GetLess(int counters[], char *lettera)
{
    int min = 100;
    for (int i = 0; i < 26; i++)
    {
        if (counters[i] != 0)
        {
            if (counters[i] <= min)
            {
                min = counters[i];
                *lettera = i;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    char lettera, string[100];
    int counters[26] = {0};
    // Leggo la stringa finchè non è valida
    do
    {
        printf("Inserisci una stringa di lettere: ");
        scanf("%s", string);
    } while (StringNotValid(string));
    // Conto quante volte occorrono le lettere, utilizzo il codice ASCII
    for (int i = 0; i < 26; i++)
    {
        counters[string[i] - 'a']++;
    }
    // Ottengo la lettera presente meno volte
    GetLess(counters, &lettera);
    // Stampo il carattere
    printf("Il carattere %c si ripete meno volte\n", lettera + 'a');
    return 1;
}