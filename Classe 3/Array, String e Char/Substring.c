/*
    Scrivere un programma in C che dopo averinserito una stringa crei 2
    ulteriori stringhe contenenti, la prima i caratterispeciali e la seconda
    lettere ordinate in ordine alfabetico.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define LETTERSALPHA 26
#define UPPERLETTERSTART 65
#define LOWERLETTERSTART 97

int main(int argc, char *argv[])
{
    int i, j, letters[2 * LETTERSALPHA] = {0};
    char special[100], str[100];
    bool again;
    printf("Inserisci la stringa: ");
    scanf("%s", str);
    for (i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            if (str[i] >= 'a')
            {
                letters[str[i] - LOWERLETTERSTART]++;
            }
            else
            {
                letters[str[i] + LETTERSALPHA - UPPERLETTERSTART]++;
            }
        }
        else
        {
            again = false;
            for (j = 0; j < strlen(special); j++)
            {
                if (special[j] == str[i])
                {
                    again = true;
                    break;
                }
            }
            if (!again)
            {
                special[strlen(special)] = str[i];
            }
        }
    }
    printf("Ecco le lettere: ");
    for (i = 0; i < 2 * LETTERSALPHA; i++)
    {
        if (letters[i])
        {
            if (i < LETTERSALPHA)
            {
                printf("%c ", i + LOWERLETTERSTART);
            }
            else
            {
                printf("%c ", i + UPPERLETTERSTART - LETTERSALPHA);
            }
        }
    }
    printf("\nEcco i caratteri speciali: %s\n", special);
    return 0;
}