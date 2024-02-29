#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>

// Definisco delle costanti con i colori
// https://learn.microsoft.com/en-us/windows/console/console-virtual-terminal-sequences#text-formatting
#define GREEN "\x1b[32m"
#define BLU "\x1b[34m"
#define RESET "\x1b[0m\n"
#define BUFFER_SIZE 2048
#define FIRST_FIFO "first.fifo"
#define SECOND_FIFO "second.fifo"

void CreazioneFifo(char *nome)
{
    if (mkfifo(nome, 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Errore nella creazione della fifo\n");
            exit(-3);
        }
    }
}

int main(int argc, char *argv[])
{
    int fifo, pid, n;
    char buffer[BUFFER_SIZE];
    char canale;
    // Controllo linea di comando
    if (argc != 2)
    {
        printf("Uso %s [<canale>]\n", argv[0]);
        exit(-1);
    }
    if (argv[1][0] != 'p' && argv[1][0] != 's')
    {
        printf("Il canale può essere o \"primo\" o \"secondo\"\n");
        exit(-2);
    }
    canale = argv[1][0];
    // Creo le fifo
    CreazioneFifo(FIRST_FIFO);
    CreazioneFifo(SECOND_FIFO);
    // Creazione processi
    pid = fork();
    if (pid < 0)
    {
        printf("Errore nella creazione della fork\n");
        exit(-4);
    }
    // Differenziazione processi
    if (pid)
    {
        // Apertura fifo e controllo errori
        printf("Attesa dell'apertura dell'altro canale\n");
        if (canale == 'p')
        {
            fifo = open(FIRST_FIFO, O_RDONLY);
        }
        else
        {
            fifo = open(SECOND_FIFO, O_RDONLY);
        }
        if (fifo == -1)
        {
            printf("Impossibile aprire il canale di lettura\n");
            wait(NULL);
            exit(-5);
        }

        if (canale == 'p')
        {
            printf("Chat avviata nel primo canale:\n");
        }
        else
        {
            printf("Chat avviata nel secondo canale:\n");
        }
        while ((n = read(fifo, buffer, BUFFER_SIZE)) > 0 && strcmp(buffer, "HALT"))
        {
            if (n != BUFFER_SIZE)
            {
                buffer[n] = '\0';
            }
            if (canale == 'p')
            {
                printf(GREEN);
                printf("Secondo Canale: %s", buffer);
            }
            else
            {
                printf(BLU);
                printf("Primo Canale: %s", buffer);
            }
            printf(RESET);
        }
        wait(NULL);
        printf("\n");
    }
    else
    {
        // Apertura fifo e controllo errori
        if (canale == 'p')
        {
            fifo = open(SECOND_FIFO, O_WRONLY);
        }
        else
        {
            fifo = open(FIRST_FIFO, O_WRONLY);
        }
        if (fifo == -1)
        {
            printf("Impossibile aprire il canale di scrittura\n");
            exit(-6);
        }
        do
        {
            fgets(buffer, BUFFER_SIZE, stdin);
            if ((strlen(buffer) > 0) && (buffer[strlen(buffer) - 1] == '\n'))
            {
                buffer[strlen(buffer) - 1] = '\0';
            }
            write(fifo, buffer, strlen(buffer));
        } while (strcmp(buffer, "HALT"));
        printf("Attesa della chiusura dell'altro canale . . .");
    }
    close(fifo);
    return 0;
}