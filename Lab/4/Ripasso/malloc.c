#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nome[20];
    char cognome[20];
    int media;
} Studente;

int main(int argc, char *argv[])
{
    Studente studente;
    Studente *stud;
    stud = malloc(sizeof(Studente)); // Memory Allocation --> Puntatore di tipo void
    strcpy(stud->nome, "Matteo");
    strcpy(stud->cognome, "Fuso");
    stud->media = 8;
    printf("%s %s %d\n", stud->nome, stud->cognome, stud->media);
    free(stud);
    return 0;
}