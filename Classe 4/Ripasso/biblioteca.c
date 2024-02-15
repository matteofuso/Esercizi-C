#include <stdio.h>
#include <stdlib.h>

#define LIBRI 3

typedef struct
{
    char titolo[20];
    char autore[20];
    double prezzo;
} Biblioteca;

void Inserimento(Biblioteca *biblioteca)
{
    printf("Inserisci il titolo del libro: ");
    scanf("%s", biblioteca->titolo);
    printf("Inserisci l'autore del libro: ");
    scanf("%s", biblioteca->autore);
    printf("Inserisci il prezzo del libro: ");
    scanf("%lf", &biblioteca->prezzo);
}

void Stampa(Biblioteca **biblioteca)
{
    printf("Ecco la lista dei libri:\n");
    for (int i = 0; i < LIBRI; i++)
    {
        printf("Libro %d:\n", i + 1);
        printf("Titolo: %s\n", biblioteca[i]->titolo);
        printf("Autore: %s\n", biblioteca[i]->autore);
        printf("Prezzo: %.2lf\n", biblioteca[i]->prezzo);
        printf("\n");
    }
}

void Sconta(Biblioteca **biblioteca, double *sconto)
{
    for (int i = 0; i < LIBRI; i++)
    {
        biblioteca[i]->prezzo -= biblioteca[i]->prezzo * *sconto / 100;
    }
}

int main(int argc, char *argv[])
{
    double sconto;
    Biblioteca *biblioteca[LIBRI];
    for (int i = 0; i < LIBRI; i++)
    {
        biblioteca[i] = (Biblioteca *)malloc(sizeof(Biblioteca));
        Inserimento(*(biblioteca + i));
        printf("\n");
    }
    Stampa(biblioteca);
    printf("Inserisci lo sconto da applicare: ");
    scanf("%lf", &sconto);
    Sconta(biblioteca, &sconto);
    Stampa(biblioteca);
    for (int i = 0; i < LIBRI; i++)
    {
        free(*(biblioteca + i));
    }
    return 0;
}