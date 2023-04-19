/*
    Scrivere un programma in C che dopo aver inserito 2 stringhe visualizzi
    a video le lettere comuni ad entrambe.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LETTERSALPHA 26
#define LOWERLETTERSTART 97

int main(int argc, char *argv[])
{
    int i, letterePrima[LETTERSALPHA] = {0}, lettereSeconda[LETTERSALPHA] = {0};
    char prima[100], seconda[100];
    bool entrato = false;
    printf("Inserisci la prima stringa: ");
    scanf("%s", prima);
    printf("Inserisci la seconda stringa: ");
    scanf("%s", seconda);
    for (i = 0; i < strlen(prima); i++)
    {
        if (isalpha(prima[i]))
        {
            letterePrima[tolower(prima[i] - LOWERLETTERSTART)]++;
        }
    }
    for (i = 0; i < strlen(seconda); i++)
    {
        if (isalpha(seconda[i]))
        {
            lettereSeconda[tolower(seconda[i] - LOWERLETTERSTART)]++;
        }
    }
    printf("Ecco le lettere in comune: \n");
    for (i = 0; i < LETTERSALPHA; i++)
    {
        if (letterePrima[i] && lettereSeconda[i]) // 0 = False, Altri = True
        {
            entrato = true;
            printf("%c\n", i + LOWERLETTERSTART);
        }
    }
    if (!entrato)
    {
        printf("Scherzavo, non ci sono lettere in comune\n");
    }
    return 0;
}