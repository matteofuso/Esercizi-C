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
    Studente *stud = (Studente *)&studente; // Cast suggerito ma non necessario
    strcpy(stud->nome, "Matteo");
    strcpy(stud->cognome, "Fuso");
    stud->media = 8;
    printf("%s %s %d\n", stud->nome, stud->cognome, stud->media);
    return 0;
}