/*
    L'obiettivo è quello di creare una rappresentazione per i e le a cui appartengono. 
    Ogni libro avrà diverse informazioni e sarà assegnato a una categoria specifica.

    Implementa un programma in linguaggio C che gestisce i libri di una libreria. 
    Ogni libro è identificato da titolo, autore, anno di pubblicazione e prezzo. 
    I libri sono organizzati per categoria (ad esempio, narrativa, saggistica, scienze, arte), 
    e ogni categoria può avere più libri.
    Immaginate di dover gestire questi raccolta di libri, suddivisi per categorie, e di dover
    trovare un modo per tenere traccia delle informazioni di ciascun libro. Ogni libro 
    dovrà avere un titolo, che lo identificherà, un autore, che ci dirà chi ha scritto il libro,
    l'anno di pubblicazione, che ci permetterà di sapere quando è stato pubblicato, e infine un
    prezzo, per indicare quanto costa.
    Dovrete anche pensare a come suddividere questi libri in categorie. Ogni categoria avrà
    un nome, che indicherà di che tipo di libri stiamo parlando, come "Narrativa" o "Scienze", 
    e conterrà una lista di libri che appartengono a quella specifica categoria.
    Il vostro compito sarà trovare il modo migliore per organizzare e gestire tutte queste
    informazioni. Inoltre, dovrete scrivere delle funzioni che vi permettano di stampare tutti
    i libri che appartengono a una determinata categoria, cercare un libro specifico in base
    al titolo e trovare tutti i libri che rientrano in una certa categoria.
    Sarà vostro compito decidere come rappresentare questi dati e implementare
    le funzioni necessarie per far funzionare il programma.

    Buon lavoro!La consegna dovrà contenere il codice (su git) e una relazione dettagliata
    sulla PROGETTAZIONE e sulle firme delle funzioni da realizzare

    In allegato, qui, trovate il file da cui pescare i libri per popolare correttamente
    la libreria.
*/

#include <stdio.h>
#include <stdlib.h>

#define CSVFILE "libreria_libri.txt"
#define LIBRICATEGORIA 30
#define MAXCATEGORIE 10
#define STDSTRLEN 50

// Struttura dati per i libri
typedef struct
{
    char titolo[STDSTRLEN];
    char autore[STDSTRLEN];
    int annoPubblicazione;
    float prezzo;
} Libro;

// Struttura dati per le categorie
typedef struct
{
    char Nome[STDSTRLEN];
    Libro *libri;
    int numeroLibri;
} Categoria;

// Struttura dati per la libreria
typedef struct
{
    Categoria *categorie;
    int numeroCategorie;
} Libreria;

// Struttura dati per la posizione di un libro
typedef struct
{
    int indiceCategoria;
    int indiceLibro;
} PosizioneLibro;

// Mostra un menù e chiede di inserire una scelta valida
int menu(char opzioni[][], int numeroOpzioni);

// Importa un libro nella libreria
void importaLibro(Libreria *libreria, Libro libro, char *categoria);

// Importa i libri da un file CSV
void importaCSV(Libreria libreria, char *nomeFile);

// Esporta i libri in un file CSV
void esportaCSV(Libreria libreria, char *nomeFile);

// Visualizza dei libri
void LeggiLibri(Libreria libreria);

// Cerca la posizione di un libro, dato il suo titolo, nella libreria
PosizioneLibro cercaLibro(Libreria libreria, char *titolo);

// Cerca la posizione di una categoria nella libreria
int cercaCategoria(Libreria libreria, char *nome);

// Modifica dei campi di un libro
void modificaLibro(Libro *libro, int campo, void *valore);

// Elimina un libro dalla libreria, dato la sua posizione
void eliminaLibro(Libreria libreria, PosizioneLibro libro);

int main(int argc, char *argv[])
{
    return 0;
}