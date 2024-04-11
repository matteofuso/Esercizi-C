#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Dimensione del buffer per la copia
#define BLOCK_DIM 1024

// Nome del programma da chiamare
#define PROGRAM "writer"

/// @brief Funzione che genera un processo
/// @param program Nome dell'eseguibile
/// @param argument Parametri da passare
/// @return Stato della fork ( -1 per errori, 0 senza errori )
int spawn(char program[], char *argument[])
{
    // PID del processo generato
    int pid;

    // Eseguo la fork
    pid = fork();
    // Se ci sono errori ritorno -1
    if (pid < 0)
        return -1;
    // Se non ci sono errori ritorno 0
    if (pid > 0)
        return 0;
    // Eseguo il programma dato con gli armenti dati, il processo figlio andrà quindi sostituito con il processo eseguito
    execv(program, argument);
    // Se arriva a questa riga, ci sono stati errori nell'eseguire il programma, genera quindi un core-dumped
    abort();
}

/// @brief Punto di ingresso del programma
/// @param argc Numeri di parametri passati
/// @param argv Parametri passati
/// @return Stato di chiusura del programma ( 0 per errori, 1 senza errori )
int main(int argc, char *argv[])
{
    // File di origine
    FILE *file;

    // File descriptor della fifo
    int fifo;

    // Buffer per la copia
    unsigned char buffer[BLOCK_DIM];

    // Caratteri letti dal file
    int n;
    
    // Argomenti da passare al nuovo processo
    char *arg[3];

    // Controllo che il numero di argomenti sia corretto
    if (argc != 3)
    {
        // Stampo l'uso corretto ed esco
        printf("Uso: %s file-origine file-destinazione\r\n", argv[0]);
        return 0;
    }
    // Preparo l'array con i parametri da passare al secondo processo
    // Mi preparo un'array di caratteri della lunghezza della stringa PROGRAM
    arg[0] = (char *)malloc(strlen(PROGRAM) + 1);
    // Copio quindi la stringa
    strcpy(arg[0], PROGRAM);
    // Alloco lo spazio per il nome del file di destinazione e ci copio il contenuto di argv[2]
    arg[1] = (char *)malloc(strlen(argv[2]) + 1);
    strcpy(arg[1], argv[2]);
    // Definisco la fine dell'array
    arg[2] = NULL;

    // Genero il secondo processo e controllo non ci siano errori 
    if (spawn(PROGRAM, arg) < 0)
    {
        // Stampo l'errore, libero lo heap ed esco
        printf("Errore creazione processo\r\n");
        free(arg[0]);
        free(arg[1]);
        return 0;
    }

    // Apro la fifo in modalità scrittura
    fifo = open("my_fifo", O_WRONLY);
    // Controllo per errori
    if (fifo < 0)
    {
        // Stampo l'errore, libero lo heap ed esco
        printf("Errore apertura FIFO\r\n");
        free(arg[0]);
        free(arg[1]);
        return 0;
    }

    // Apro il file di origine in modalità lettura binaria
    file = fopen(argv[1], "rb");
    // Controllo per errori
    if (file == NULL)
    {
        // Stampo l'errore, libero lo heap, chiudo la fifo ed esco
        printf("Errore apertura file \"%s\"\r\n", argv[1]);
        close(fifo);
        free(arg[0]);
        free(arg[1]);
        return 0;
    }
    // Leggo un massimo di sizeof(buffer) caratteri dal file di origine e li salvo sul buffer
    while ((n = fread(buffer, 1, sizeof(buffer), file)) > 0)
        // Invio il contenuto del buffer nella fifo
        write(fifo, buffer, n);
    // Libero lo heap e chiudo la fifo ed il file, poi esco
    fclose(file);
    close(fifo);
    free(arg[0]);
    free(arg[1]);
    return 1;
}
