#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_DIM 1024

int main(int argc, char *argv[])
{
    typedef struct // Definisco un nuovo tipo di dato di tipo struct
    {
        char name[20];         // Questo tipo di dato contiene un array di 20 caratteri, un nome
        char lastname[20];     // Questo tipo di dato contiene un array di 20 caratteri, un cognome
        int gradePointAverage; // Questo tipo di dato contiene un intero, il media dei voti

    } student;        // Il nome del tipo di dato è student
    student class[3]; // Creo un'array di studenti

    strcpy(class[0].name, "name1");         // Specifico il nome del primo studente
    strcpy(class[0].lastname, "lastname1"); // Specifico il cognome del primo studente
    class[0].gradePointAverage = 8;         // Definisco la media del primo studente

    strcpy(class[1].name, "name2");         // Specifico il nome del secondo studente
    strcpy(class[1].lastname, "lastname2"); // Specifico il cognome del secondo studente
    class[1].gradePointAverage = 9;         // Definisco la media del secondo studente

    strcpy(class[2].name, "name3");         // Specifico il nome del terzo studente
    strcpy(class[2].lastname, "lastname3"); // Specifico il cognome del terzo studente
    class[2].gradePointAverage = 10;        // Definisco la media del terzo studente

    FILE *contieneStudenti;                 // Creo un puntatore a file
    contieneStudenti = fopen(argv[1], "w"); // Apro il file il cui percorso è specificato in argv[1] in modalità scrittura
    if (contieneStudenti == NULL)           // Controlla se il file è stato aperto
    {
        printf("errore apertura file destinazione %s", argv[1]); // Stampa che non è stato possibile aprire il file
        return 0;                                                // Esce dal programma con il codice 0
    }

    fwrite(class, sizeof(student), 3, contieneStudenti);      // Scrivo un massimo di 3 studenti sul file appena aperto
    fclose(contieneStudenti);                                 // Chiudo il file per salvare le modifiche
    contieneStudenti = fopen(argv[1], "r");                   // Riapro il file
    student secondClass[3];                                   // Creo una seconda classe, un array di studenti
    fread(secondClass, sizeof(student), 3, contieneStudenti); // Leggo dal file appena scritto 3 studenti e la salvo sul nuovo array
    for (int i = 0; i < 3; i++)                               // Per ogni studente del secondo array
    {
        printf("%s\n", secondClass[i].name);              // Stampo il nome
        printf("%s\n", secondClass[i].lastname);          // Stampo il cognome
        printf("%d\n", secondClass[i].gradePointAverage); // Stampo la media
    }
    printf("------------------------\n");                   // Stampo un separatore
    fseek(contieneStudenti, sizeof(student) * 2, SEEK_SET); // Mi sposto nel file dall'inizio di 2 elementi, arrivando all'ultimo
    student stud;                                           // Creo uno studente
    fread(&stud, sizeof(student), 3, contieneStudenti);     // Leggo un massimo di 3 studenti dal file, salvo quindi l'ultimo sulla variabile appena creata
    printf("%s\n", stud.name);                              // Stampo il nome
    printf("%s\n", stud.lastname);                          // Stampo il cognome
    printf("%d\n", stud.gradePointAverage);                 // Stampo la media
    fclose(contieneStudenti);                               // Chiudo il file
    return 0;                                               // Definisco la media del primo studente
}

/*
    Il programma definisce un nuovo tipo di dato, lo studente. Successivamente crea una classe e la riempie di studenti.
    Successivamente salvo la classe nel file e successivamente la leggo dal file e la salvo in un altra classe.
    Stampo a schermo poi la nuova classe. Mi posiziono poi all'ultimo studente del file e lo salvo in una variabile.
    Stampo infine lo studente
*/