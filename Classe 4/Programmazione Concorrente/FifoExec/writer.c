#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Dimensione del buffer per la copia
#define BLOCK_DIM 1024

/// @brief Punto di ingresso del programma
/// @param argc Numeri di parametri passati
/// @param argv Parametri passati
/// @return Stato di chiusura del programma ( 0 per errori, 1 senza errori )
int main(int argc, char *argv[])
{
     // File di destinazione
     FILE *file;

     // Buffer per la copia
     unsigned char buffer[BLOCK_DIM];

     // Caratteri letti dalla fifo
     int n;

     // File descriptor della fifo
     int fifo;

     // Controllo che il numero di argomenti sia corretto
     if (argc != 2)
     {
          // Stampo l'uso corretto ed esco
          printf("Uso: %s file\r\n", argv[0]);
          return 0;
     }

     // Apro la fifo in modalità lettura
     fifo = open("my_fifo", O_RDONLY);
     // Controllo per errori
     if (fifo < 0)
     {
          // Stampo l'errore ed esco
          printf("Errore apertura FIFO\r\n");
          return 0;
     }

     // Apro il file di origine in modalità scrittura binaria
     file = fopen(argv[1], "wb");
     // Controllo per errori
     if (file == NULL)
     {
          // Stampo l'errore, chiudo la fifo ed esco
          printf("Errore apertura file \"%s\"\r\n", argv[1]);
          close(fifo);
          return 0;
     }

     // Leggo un massimo di sizeof(buffer) caratteri dalla fifo e li salvo sul buffer
     while ((n = read(fifo, buffer, sizeof(buffer))) > 0)
          // Scrivo il contenuto del buffer nel file
          fwrite(buffer, 1, n, file);
     // Chiudo la fifo ed il file, poi esco
     close(fifo);
     fclose(file);
     return 1;
}
