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
    char origine[100], pari[50], dispari[50];
    int i, voc[2], cons[2];
    do
    {
        printf("Inserisci una stringa: ");
        scanf(" %[^\n]s", origine);
        for (i = 0; i < strlen(origine); i++)
        {
            if (origine[i] != ' ' && !isalpha(origine[i]))
            {
                printf("Inserisci solo caratteri dell'alfabeto. ");
                i = -1;
                break;
            }
            if (i % 2 == 0)
            {
                pari[i / 2] = origine[i];
            }
            else
            {
                dispari[(i - 1) / 2] = origine[i];
            }
        }
    } while (i == -1);
    printf("%d -Indice Pari: %s \nIndice Dispari: %s\n", i, pari, dispari);
    return 0;
}