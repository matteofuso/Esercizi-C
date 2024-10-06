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
#include <string.h>
#include <strings.h>

#define CSVFILE "libreria_libri.csv"
#define BUFFERSIZE 1024
#define STDSTRLEN 50
#define LISTLENSTART 8

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
    int dimensioneLibri;
} Categoria;

// Struttura dati per la libreria
typedef struct
{
    Categoria *categorie;
    int numeroCategorie;
    int dimensioneCategorie;
} Libreria;

// Struttura dati per la posizione di un libro
typedef struct
{
    int indiceCategoria;
    int indiceLibro;
} PosizioneLibro;

// Mostra un menù e chiede di inserire una scelta valida, ritorna l'indice dell'opzione scelta
int menu(char *opzioni[], int numeroOpzioni)
{
    int scelta;
    for (int i = 0; i < numeroOpzioni; i++)
    {
        printf("%d - %s\n", i + 1, opzioni[i]);
    }
    do
    {
        printf("Inserisci un valore corretto: ");
        scanf("%d", &scelta);
    } while (scelta < 1 || scelta > numeroOpzioni);
    return scelta - 1;
}

// Crea una nuova categoria nella libreria, ritorna l'indice della nuova categoria o -1 in caso di errore
int creaCategoria(Libreria *libreria, char *nome)
{
    // Assicura che ci sia spazio per la nuova categoria
    if (libreria->numeroCategorie >= libreria->dimensioneCategorie)
    {
        Categoria *nuovaCategoria = (Categoria *)realloc(libreria->categorie, 2 * libreria->dimensioneCategorie * sizeof(Categoria));
        if (nuovaCategoria == NULL)
        {
            return -1;
        }
        libreria->categorie = nuovaCategoria;
        libreria->dimensioneCategorie *= 2;
    }
    // Inizializza la nuova categoria
    strcpy(libreria->categorie[libreria->numeroCategorie].Nome, nome);
    libreria->categorie[libreria->numeroCategorie].numeroLibri = 0;
    libreria->categorie[libreria->numeroCategorie].libri = (Libro *)malloc(LISTLENSTART * sizeof(Libro));
    // Controlla se l'allocazione è andata a buon fine
    if (libreria->categorie[libreria->numeroCategorie].libri == NULL)
    {
        return -1;
    }
    libreria->categorie[libreria->numeroCategorie].dimensioneLibri = LISTLENSTART;
    libreria->numeroCategorie++;
    return libreria->numeroCategorie - 1;
}

// Cerca la posizione di una categoria nella libreria e ritorna l'indice o -1 se non trovata
int cercaCategoria(Libreria libreria, char *nome)
{
    for (int i = 0; i < libreria.numeroCategorie; i++)
    {
        if (strcasecmp(libreria.categorie[i].Nome, nome) == 0)
        {
            return i;
        }
    }
    return -1;
}

// Importa un libro nella libreria, ritorna -1 in caso di errore
int importaLibro(Libreria *libreria, Libro libro, char *categoria)
{
    Categoria *categoriaLibri;
    // Cerca la categoria, se non esiste la crea
    int posizioneCategoria = cercaCategoria(*libreria, categoria);
    if (posizioneCategoria == -1)
    {
        posizioneCategoria = creaCategoria(libreria, categoria);
        // Controlla se la categoria è stata creata correttamente
        if (posizioneCategoria == -1)
        {
            return -1;
        }
    }
    categoriaLibri = &libreria->categorie[posizioneCategoria];
    // Assicura che ci sia spazio per il nuovo libro
    if (categoriaLibri->numeroLibri >= categoriaLibri->dimensioneLibri)
    {
        Libro *nuovoLibro = (Libro *)realloc(categoriaLibri->libri, 2 * categoriaLibri->dimensioneLibri * sizeof(Libro));
        if (nuovoLibro == NULL)
        {
            return -1;
        }
        categoriaLibri->libri = nuovoLibro;
        categoriaLibri->dimensioneLibri *= 2;
    }
    // Aggiunge il libro alla categoria
    categoriaLibri->libri[categoriaLibri->numeroLibri] = libro;
    categoriaLibri->numeroLibri++;
    return 0;
}

// Importa i libri da un file CSV
void importaCSV(Libreria *libreria, char *nomeFile)
{
    FILE *file;
    Libro libro;
    char categoria[STDSTRLEN];
    char riga[BUFFERSIZE];
    // Controlla se il file è stato aperto correttamente
    file = fopen(nomeFile, "r");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file\n");
        return;
    }
    // Salto la prima riga
    fgets(riga, BUFFERSIZE, file);
    // Legge i libri dal file
    while (fgets(riga, BUFFERSIZE, file) != NULL)
    {
        if (sscanf(riga, "%[^,],%[^,],%d,%f,%[^\r\n]", libro.titolo, libro.autore, &libro.annoPubblicazione, &libro.prezzo, categoria) == 5)
        {
            importaLibro(libreria, libro, categoria);
        }
        else
        {
            printf("Errore nel formato della riga: %s\n", riga);
        }
    }
    fclose(file);
}

// Esporta i libri in un file CSV
void esportaCSV(Libreria libreria, char *nomeFile)
{
    FILE *file;
    // Controlla se il file è stato aperto correttamente
    file = fopen(nomeFile, "w");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file\n");
        return;
    }
    // Scrive i libri nel file
    fprintf(file, "%s,%s,%s,%s,%s\n", "Titolo", "Autore", "Anno", "Prezzo", "Categoria");
    for (int i = 0; i < libreria.numeroCategorie; i++)
    {
        for (int j = 0; j < libreria.categorie[i].numeroLibri; j++)
        {
            fprintf(file, "%s,%s,%d,%.2f,%s\n", libreria.categorie[i].libri[j].titolo, libreria.categorie[i].libri[j].autore, libreria.categorie[i].libri[j].annoPubblicazione, libreria.categorie[i].libri[j].prezzo, libreria.categorie[i].Nome);
        }
    }
    fclose(file);
}

// Visualizza dei libri
void stampaLibri(Libreria libreria)
{
    printf("%-40s %-35s %-8s %-10s %s\n", "Titolo", "Autore", "Anno", "Prezzo", "Categoria");
    for (int i = 0; i < libreria.numeroCategorie; i++)
    {
        for (int j = 0; j < libreria.categorie[i].numeroLibri; j++)
        {
            printf("%-40s %-35s %-8d €%-9.2f %s\n", libreria.categorie[i].libri[j].titolo, libreria.categorie[i].libri[j].autore, libreria.categorie[i].libri[j].annoPubblicazione, libreria.categorie[i].libri[j].prezzo, libreria.categorie[i].Nome);
        }
    }
}

// Cerca la posizione di un libro, dato il suo titolo, nella libreria
PosizioneLibro cercaLibro(Libreria libreria, char *titolo)
{
    PosizioneLibro posizione = {-1, -1};
    for (int i = 0; i < libreria.numeroCategorie; i++)
    {
        for (int j = 0; j < libreria.categorie[i].numeroLibri; j++)
        {
            if (strcasecmp(libreria.categorie[i].libri[j].titolo, titolo) == 0)
            {
                posizione.indiceCategoria = i;
                posizione.indiceLibro = j;
                return posizione;
            }
        }
    }
    return posizione;
}

// Elimina un libro dalla libreria, dato la sua posizione
void eliminaLibro(Libreria *libreria, PosizioneLibro libro)
{
    for (int i = libro.indiceLibro; i < libreria->categorie[libro.indiceCategoria].numeroLibri - 1; i++)
    {
        libreria->categorie[libro.indiceCategoria].libri[i] = libreria->categorie[libro.indiceCategoria].libri[i + 1];
    }
    libreria->categorie[libro.indiceCategoria].numeroLibri--;
}

// Modifica dei campi di un libro
void modificaLibro(Libreria *libreria, PosizioneLibro posizioneLibro, int campo, void *valore)
{
    Libro *libro = &libreria->categorie[posizioneLibro.indiceCategoria].libri[posizioneLibro.indiceLibro];
    switch (campo)
    {
    case 0:
        strcpy(libro->titolo, (char *)valore);
        break;
    case 1:
        strcpy(libro->autore, (char *)valore);
        break;
    case 2:
        libro->annoPubblicazione = *(int *)valore;
        break;
    case 3:
        libro->prezzo = *(float *)valore;
        break;
    case 4:
        importaLibro(libreria, *libro, (char *)valore);
        eliminaLibro(libreria, posizioneLibro);
        break;
    }
}

int main(int argc, char *argv[])
{
    int scelta;
    char *opzioni[] = {"Visualizza libri", "Cerca libri per categoria", "Cerca libro per titolo", "Aggiungi libro", "Modifica libro", "Elimina libro", "Esci"};
    char *campi[] = {"Titolo", "Autore", "Anno di pubblicazione", "Prezzo", "Categoria", "Esci"};
    char inputSTR[STDSTRLEN];
    int sizeOpzioni = sizeof(opzioni) / sizeof(char *);
    int sizeCampi = sizeof(campi) / sizeof(char *);
    // Inizializzazione della libreria
    Libreria libreria;
    libreria.categorie = (Categoria *)malloc(LISTLENSTART * sizeof(Categoria));
    if (libreria.categorie == NULL)
    {
        printf("Impossibile creare la libreria\n");
        return -1;
    }
    libreria.numeroCategorie = 0;
    libreria.dimensioneCategorie = LISTLENSTART;
    importaCSV(&libreria, CSVFILE);
    // Menu principale
    while (1)
    {
        // Visualizza il menu e chiede di inserire una scelta
        scelta = menu(opzioni, sizeOpzioni);
        // Controlla se l'utente ha scelto di uscire
        if (scelta == sizeOpzioni - 1)
        {
            break;
        }
        // Esegue l'operazione scelta
        switch (scelta)
        {
        case 0:
            stampaLibri(libreria);
            break;
        case 1:
            printf("Inserisci il nome della categoria: ");
            scanf(" %[^\n]", inputSTR);
            // Cerca la categoria e stampa i libri
            scelta = cercaCategoria(libreria, inputSTR);
            if (scelta != -1)
            {
                stampaLibri((Libreria){libreria.categorie + scelta, 1});
            }
            else
            {
                printf("Categoria non trovata\n");
            }
            break;
        case 3:
            Libro nuovoLibro;
            // Chiede all'utente di inserire i dati del nuovo libro
            printf("Inserisci il titolo del libro: ");
            scanf(" %[^\n]", nuovoLibro.titolo);
            printf("Inserisci l'autore del libro: ");
            scanf(" %[^\n]", nuovoLibro.autore);
            printf("Inserisci l'anno di pubblicazione del libro: ");
            scanf("%d", &nuovoLibro.annoPubblicazione);
            printf("Inserisci il prezzo del libro: ");
            scanf("%f", &nuovoLibro.prezzo);
            printf("Inserisci la categoria del libro: ");
            scanf(" %[^\n]", inputSTR);
            // Importa il libro nella libreria e controlla se ci sono stati errori
            if (importaLibro(&libreria, nuovoLibro, inputSTR) == -1)
            {
                printf("Errore nell'importazione del libro\n");
                break;
            }
            printf("Libro aggiunto\n");
            break;
        case 2:
        case 4:
        case 5:
            printf("Inserisci il titolo del libro: ");
            scanf(" %[^\n]", inputSTR);
            // Cerca il libro e esegue continua con l'operazione scelta
            PosizioneLibro libro = cercaLibro(libreria, inputSTR);
            if (libro.indiceCategoria == -1)
            {
                printf("Libro non trovato\n");
                break;
            }
            // Esegue l'operazione scelta
            switch (scelta)
            {
            case 3:
                // Crea una libreria temporanea per la stampa
                Categoria categoria = libreria.categorie[libro.indiceCategoria];
                categoria.libri += libro.indiceLibro;
                categoria.numeroLibri = 1;
                stampaLibri((Libreria){&categoria, 1});
                break;
            case 4:
                // Menu per la scelta della modifica dei campi
                while (1)
                {
                    // Visualizza il menu e chiede di inserire una scelta
                    int scelta = menu(campi, sizeCampi);
                    // Controlla se l'utente ha scelto di uscire
                    if (scelta == sizeCampi - 1)
                    {
                        break;
                    }
                    printf("Inserisci il nuovo valore: ");
                    // Esegue la modifica del campo scelto
                    if (scelta < 2 || scelta == 4)
                    {
                        scanf(" %[^\n]", inputSTR);
                        modificaLibro(&libreria, libro, scelta, inputSTR);
                    }
                    else if (scelta == 2)
                    {
                        int valore;
                        scanf("%d", &valore);
                        modificaLibro(&libreria, libro, scelta, &valore);
                    }
                    else
                    {
                        float valore;
                        scanf("%f", &valore);
                        modificaLibro(&libreria, libro, scelta, &valore);
                    }
                    printf("Libro modificato\n");
                }
                break;
            case 5:
                eliminaLibro(&libreria, libro);
                printf("Libro eliminato\n");
                break;
            }
            break;
        }
        printf("\n");
    }
    // Deallocazione della memoria
    esportaCSV(libreria, CSVFILE);
    for (int i = 0; i < libreria.numeroCategorie; i++)
    {
        free(libreria.categorie[i].libri);
    }
    free(libreria.categorie);
    return 0;
}