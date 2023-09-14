#include <stdio.h>
#include <string.h>

int palindromo(char *parola)
{
    int l = strlen(parola);
    for (int i = 0; i < l / 2; i++)
    {
        if (*(parola + i) != *(parola + l - i - 1))
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[])
{
    char parola[100];
    printf("Inserisci la parola: ");
    scanf("%s", parola);
    if (palindromo(parola))
    {
        printf("La parola è palindroma\n");
    }
    else
    {
        printf("La parola non è palindroma\n");
    }
    return 0;
}