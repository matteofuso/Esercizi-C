/*
    Esercizio Struct
    Definisci la struttura dati per la creazione di un punto con le sue coordinate,
    x, y, z, offrendo all’utente la possibilità di vederne visualizzati i valori:
    crea un’apposita funzione stampa_punto().
    Scrivi il codice sorgente di una funzione, punto_modificato(), per la creazione
    di un ulteriore punto le cui coordinate abbiano un valore incrementato di una
    unità rispetto al precedente punto e visualizzale.
    Avvalersi dell’uso delle funzioni e del passaggio di parametri per valore.
*/

#include <stdio.h>

typedef struct
{
    int x;
    int y;
    int z;
} Punto;

void stampa_punto(Punto punto)
{
    printf("x: %d, y: %d, z: %d\n", punto.x, punto.y, punto.z);
}

Punto punto_modificato(Punto punto)
{
    Punto modificato = {punto.x + 1, punto.y + 1, punto.z + 1};
    return modificato;
}

int main(int argc, char *argv[])
{
    Punto punto;
    printf("Inserisci la coordinata X del punto: ");
    scanf("%d", &punto.x);
    printf("Inserisci la coordinata Y del punto: ");
    scanf("%d", &punto.y);
    printf("Inserisci la coordinata Z del punto: ");
    scanf("%d", &punto.z);
    stampa_punto(punto);
    Punto modificato = punto_modificato(punto);
    stampa_punto(modificato);
    return 0;
}