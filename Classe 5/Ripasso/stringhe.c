/*
    Scrivere un programma in C che dopo aver inserito una stringa a piacere
    determini e o verifichi:
    1) Che contenga solo lettere;
    2) Il conteggio di una lettera (se presente) scelta dall’utente;
    3) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari;
    la 2° le lettere di posizione dispari;
    4) Verifichi se contiene doppie.
    Inserita una 2° stringa determinare:
    1) Quale delle 2 è più lunga e più corta;
    2) Quali sono le lettere contenute in ambedue le stringhe;
    3) Quale delle 2 stringhe contiene più vocali;
    4) Quale delle 2 stringhe contiene più consonanti;
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define STRLEN 100

bool onlyLetter(char *string)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (!isalpha(string[i]))
        {
            return false;
        }
    }
    return true;
}

int count(char *string, char letter)
{
    int count = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == letter)
        {
            count++;
        }
    }
    return count;
}

void EvenOddString(char *string, char *stringEven, char *stringOdd)
{
    int j = 0, k = 0;
    for (int i = 0; i < strlen(string); i++)
    {
        if (i % 2 == 0)
        {
            stringEven[j++] = string[i];
        }
        else
        {
            stringOdd[k++] = string[i];
        }
    }
    stringEven[j] = '\0';
    stringOdd[k] = '\0';
}

void strToAlpha(char *string, char *alpha)
{
    for (int i = 0; i < strlen(string); i++)
    {
        if (isalpha(string[i]))
        {
            alpha[tolower(string[i]) - 'a']++;
        }
    }
}

int main(int argc, char **argv)
{
    char string[STRLEN], string2[STRLEN];
    char stringEven[STRLEN], stringOdd[STRLEN];
    char alpha[26] = {0}, alpha2[26] = {0};
    char letter;
    int times;
    // Chiedo di inserire la prima stringa
    printf("Inserisci una stringa: ");
    scanf("%s", string);
    // Controllo se la stringa contiene solo lettere
    if (onlyLetter(string))
    {
        printf("La stringa contiene solo lettere\n");
    }
    else
    {
        printf("La stringa contiene caratteri fuori dall'alfabeto\n");
    }
    // Conteggio lettere
    printf("Inserisci una lettera: ");
    do
    {
        scanf(" %c", &letter);
    } while (!isalpha(letter));
    times = count(string, letter);
    printf("La lettera %c è presente %d volte\n", letter, times);
    // Creo le stringhe pari e dispari
    EvenOddString(string, stringEven, stringOdd);
    printf("Stringa con lettere di posizione pari: %s\n", stringEven);
    printf("Stringa con lettere di posizione dispari: %s\n", stringOdd);
    // Controllo se contiene doppie
    strToAlpha(string, alpha);
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > 1)
        {
            printf("La lettera %c è presente %d volte\n", i + 'a', alpha[i]);
        }
    }
    // Chiedo all'utente di inserire un'altra stringa
    printf("Inserisci la seconda stringa: ");
    scanf("%s", string2);
    // Controllo la lunghezza delle stringhe
    if (strlen(string) > strlen(string2))
    {
        printf("La prima stringa è più lunga della seconda\n");
    }
    else if (strcmp(string, string2) < 0)
    {
        printf("La prima stringa è più corta della seconda\n");
    }
    else
    {
        printf("Le stringhe sono lunghe uguali\n");
    }
    // Controllo le lettere comuni
    strToAlpha(string2, alpha2);
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] > 0 && alpha2[i] > 0)
        {
            printf("La lettera %c è presente in entrambe le stringhe, nella prima %d volte, nella seconda %d volte\n", i + 'a', alpha[i], alpha2[i]);
        }
    }
    return 0;
}