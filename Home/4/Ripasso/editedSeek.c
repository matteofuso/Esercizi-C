#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_DIM 1024

int main(int argc, char *argv[])
{
    int len, posizione; // len è la lunghezza dell'array, posizione è la posizione dell'alunno da stampare
    typedef struct      // Definisco un nuovo tipo di dato di tipo struct
    {
        char name[20];         // Questo tipo di dato contiene un array di 20 caratteri, un nome
        char lastname[20];     // Questo tipo di dato contiene un array di 20 caratteri, un cognome
        int gradePointAverage; // Questo tipo di dato contiene un intero, il media dei voti

    } student; // Il nome del tipo di dato è student

    do // Chiedo la grandezza della classe
    {
        printf("Inserisci il numero di alunni della classe: ");
        scanf("%d", &len);
    } while (len < 1);

    student class[len]; // Creo un'array di studenti

    for (int i = 0; i < len; i++) // Chiedo i dati dell'alunno
    {
        printf("Inserisci il nome del %d° studente: ", i + 1);
        scanf("%s", class[i].name);
        printf("Inserisci il cognome del %d° studente: ", i + 1);
        scanf("%s", class[i].lastname);
        printf("Inserisci la media del %d° studente: ", i + 1);
        scanf("%d", &class[i].gradePointAverage);
        printf("\n");
    }

    FILE *contieneStudenti;                 // Creo un puntatore a file
    contieneStudenti = fopen(argv[1], "w"); // Apro il file il cui percorso è specificato in argv[1] in modalità scrittura
    if (contieneStudenti == NULL)           // Controlla se il file è stato aperto
    {
        printf("errore apertura file destinazione %s", argv[1]); // Stampa che non è stato possibile aprire il file
        return 0;                                                // Esce dal programma con il codice 0
    }

    fwrite(class, sizeof(student), len, contieneStudenti); // Scrivo un massimo di 3 studenti sul file appena aperto
    fclose(contieneStudenti);                              // Chiudo il file per salvare le modifiche
    contieneStudenti = fopen(argv[1], "r");                // Riapro il file
    student secondClass[len];                              // Creo una seconda classe, un array di studenti
    printf("Ecco la classe inserita:\n");
    fread(secondClass, sizeof(student), len, contieneStudenti); // Leggo dal file appena scritto 3 studenti e la salvo sul nuovo array
    for (int i = 0; i < len; i++)                               // Per ogni studente del secondo array
    {
        printf("%d - Nome:%s\n", i + 1, secondClass[i].name);      // Stampo il nome
        printf("Cognome: %s\n", secondClass[i].lastname);          // Stampo il cognome
        printf("Media: %d\n\n", secondClass[i].gradePointAverage); // Stampo la media
    }
    printf("------------------------\n"); // Stampo un separatore

    do // Chiedo l'alunno da stampare
    {
        printf("Inserisci il numero dell'alunno da stampare: ");
        scanf("%d", &posizione);
    } while (posizione < 1 || posizione > len);

    fseek(contieneStudenti, sizeof(student) * (posizione - 1), SEEK_SET); // Mi sposto nel file dall'inizio di 2 elementi, arrivando all'ultimo
    student stud;                                                         // Creo uno studente
    fread(&stud, sizeof(student), 1, contieneStudenti);                   // Leggo un massimo di 3 studenti dal file, salvo quindi l'ultimo sulla variabile appena creata
    printf("Nome:%s\n", stud.name);                                       // Stampo il nome
    printf("Cognome: %s\n", stud.lastname);                               // Stampo il cognome
    printf("Media: %d\n", stud.gradePointAverage);                        // Stampo la media
    fclose(contieneStudenti);                                             // Chiudo il file
    return 0;                                                             // Definisco la media del primo studente
}