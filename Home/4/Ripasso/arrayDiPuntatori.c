/*
    Avvalendoti del linguaggio C e utilizzando la funzione MALLOC , scrivi il codice
    sorgente di un programma che:
    _ crea una struttura student_ t costituita dai campi: cognome, nome, media
    _ crea un array di tre puntatori a struct di tipo student_t
    _ chiede all’utente di inserire i dati dei tre studenti e memorizzarli nell’array
    _ stampa il contenuto delle tre strutture referenziate dall’array
    _ stampa il contenuto dell’array (i tre indirizzi di memoria che puntano ai tre
    studenti)
    _ libera l’area di memoria occupata dalla malloc.
*/

#include <stdio.h>
#include <stdlib.h>

#define STUDENTI 3

typedef struct
{
    char nome[20];
    char cognome[20];
    float media;
} student_t;

int main(int argc, char *argv[])
{
    student_t *studenti[STUDENTI];
    // Alloco la memoria e assegno i valori nella struct
    for (int i = 0; i < STUDENTI; i++)
    {
        studenti[i] = malloc(sizeof(student_t));
        printf("Inserisci il nome del %d studente: ", i + 1);
        scanf("%s", studenti[i]->nome);
        printf("Inserisci il cognome del %d studente: ", i + 1);
        scanf("%s", studenti[i]->cognome);
        printf("Inserisci la media del %d studente: ", i + 1);
        scanf("%f", &studenti[i]->media);
        printf("\n");
    }
    // Stampo i valori inseriti
    printf("Ecco gli studenti inseriti:\n");
    for (int i = 0; i < STUDENTI; i++)
    {
        printf("Nome: %s, Cognome: %s, Media: %.2lf\n", studenti[i]->nome, studenti[i]->cognome, studenti[i]->media);
    }
    // Stamppo il contenuto dell'array
    printf("\nEcco il continuto dell'array:\n");
    for (int i = 0; i < STUDENTI; i++)
    {
        printf("studenti[%d] --> %p\n", i, studenti[i]);
    }
    // Libero la memoria
    for (int i = 0; i < STUDENTI; i++)
    {
        free(studenti[i]);
    }
    return 0;
}