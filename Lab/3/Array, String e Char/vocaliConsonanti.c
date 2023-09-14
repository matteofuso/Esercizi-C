/*
    Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
        1)Che contenga solo lettere;
        2)Crei 2 ulteriori stringhe che contengano: la 1° le lettere di posizione pari; la 2° le lettere di posizione dispari;

    Inserita una 2° stringa determinare:
        1)Quale delle 2 è più lunga e più corta;
        2)Quale delle 2 stringhe contiene più vocali;
        3)Quale delle 2 stringhe contiene più consonanti;
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    char prima[100], seconda[100], pari[50], dispari[50];
    int i, voc[2], cons[2];
    voc[0] = voc[1] = cons[0] = cons[1] = 0;
    do
    {
        printf("Inserisci la prima stringa: ");
        scanf(" %s", prima);
        for (i = 0; i < strlen(prima); i++)
        {
            if (!isalpha(prima[i]))
            {
                printf("Inserisci solo caratteri dell'alfabeto. ");
                i = -1;
                break;
            }
            if (i % 2 == 0)
            {
                pari[i / 2] = prima[i];
            }
            else
            {
                dispari[(i - 1) / 2] = prima[i];
            }
            if (
                tolower(prima[i]) == 'a' ||
                tolower(prima[i]) == 'e' ||
                tolower(prima[i]) == 'i' ||
                tolower(prima[i]) == 'o' ||
                tolower(prima[i]) == 'u')
            {
                voc[0]++;
            }
            else
            {
                cons[0]++;
            }
        }
    } while (i == -1);
    printf("Inserisci la seconda stringa: ");
    scanf(" %s", seconda);
    for (i = 0; i < strlen(seconda); i++)
    {
        if (isalnum(seconda[i]))
        {
            if (
                tolower(seconda[i]) == 'a' ||
                tolower(seconda[i]) == 'e' ||
                tolower(seconda[i]) == 'i' ||
                tolower(seconda[i]) == 'o' ||
                tolower(seconda[i]) == 'u')
            {
                voc[1]++;
            }
            else
            {
                cons[1]++;
            }
        }
    }
    printf("Nella prima stringa:\n");
    printf("-Lettere a indice pari: %s\n-Lettere a indice dispari: %s\n", pari, dispari);
    if (strlen(prima) == strlen(seconda))
    {
        printf("Le due stringe hanno la stezza lunghezza\n");
    }
    else if (strlen(prima) > strlen(seconda))
    {
        printf("La prima stringa è più lunga\n");
    }
    else
    {
        printf("La seconda stringa è più lunga\n");
    }
    if (voc[0] == voc[1])
    {
        printf("Le due stringe hanno lo stesso numero di vocali\n");
    }
    else if (voc[0] > voc[1])
    {
        printf("La prima stringa ha più vocali\n");
    }
    else
    {
        printf("La seconda stringa ha più vocali\n");
    }

    if (cons[0] == cons[1])
    {
        printf("Le due stringe hanno lo stesso numero di consonanti\n");
    }
    else if (cons[0] > cons[1])
    {
        printf("La prima stringa ha più consonanti\n");
    }
    else
    {
        printf("La seconda stringa ha più consonanti\n");
    }

    return 0;
}