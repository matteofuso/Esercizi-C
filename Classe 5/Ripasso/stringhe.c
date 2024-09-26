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

// Controlla se la stringa contiene solo lettere
bool onlyLetter(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (!isalpha(string[i]))
        {
            return false;
        }
    }
    return true;
}

// Conta quante volte è presente una lettera
int count(char *string, char letter)
{
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == letter)
        {
            count++;
        }
    }
    return count;
}

// Crea due stringhe con le lettere di posizione pari e dispari
void EvenOddString(char *string, char *stringEven, char *stringOdd)
{
    int j = 0, k = 0;
    for (int i = 0; string[i] != '\0'; i++)
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

// Conta le lettere presenti nella stringa
void strToAlpha(char *string, char *alpha)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (isalpha(string[i]))
        {
            alpha[tolower(string[i]) - 'a']++;
        }
    }
}

// Controlla se la stringa contiene vocali
bool isVowel(char letter)
{
    letter = tolower(letter);
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

// Confronta il numero di vocali e consonanti tra due stringhe
void compareVowelsConsonants(const char *string1, const char *string2, int *outVowels, int *outConsonants)
{
    *outVowels = 0;
    *outConsonants = 0;
    for (int i = 0; string1[i] != '\0'; i++)
    {
        if (isalpha(string1[i]))
        {
            if (isVowel(string1[i]))
            {
                (*outVowels)++;
            }
            else
            {
                (*outConsonants)++;
            }
        }
    }
    for (int i = 0; string2[i] != '\0'; i++)
    {
        if (isalpha(string2[i]))
        {
            if (isVowel(string2[i]))
            {
                (*outVowels)--;
            }
            else
            {
                (*outConsonants)--;
            }
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
    int vowels, consonants;
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
    else if (strlen(string) < strlen(string2))
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
    // Stringa con più vocali e consonanti
    compareVowelsConsonants(string, string2, &vowels, &consonants);
    if (vowels > 0)
    {
        printf("La prima stringa contiene più vocali\n");
    }
    else if (vowels < 0)
    {
        printf("La seconda stringa contiene più vocali\n");
    }
    else
    {
        printf("Le stringhe contengono lo stesso numero di vocali\n");
    }
    if (consonants > 0)
    {
        printf("La prima stringa contiene più consonanti\n");
    }
    else if (consonants < 0)
    {
        printf("La seconda stringa contiene più consonanti\n");
    }
    else
    {
        printf("Le stringhe contengono lo stesso numero di consonanti\n");
    }
    return 0;
}