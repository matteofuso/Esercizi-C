/*
    Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in input 1 stringa,
    e dopo aver effettuato gli eventuali ed opportuni controlli (se necessari), rispedisce al Client la stringa
    ordinata alfabeticamente (eliminando i caratteri speciali).
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdbool.h>

#define SRV_PORT 5555
#define STRLEN 128

void strSort(char *str, int strlen)
{
    bool sorted = false;
    for (int i = 0; i < strlen - 1 && !sorted; i++)
    {
        sorted = true;
        for (int j = 0; j < strlen - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                char c = str[i];
                str[i] = str[j];
                str[j] = c;
                sorted = false;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    struct sockaddr_in server;
    int serverfd, len = sizeof(struct sockaddr_in);
    char buffer[STRLEN];
    // Controllo argomenti
    if (argc != 2)
    {
        printf("Uso: %s <string>\n", argv[0]);
        exit(-1);
    }
    // Creazione Socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SRV_PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-1);
    }
    // Connessione
    if (connect(serverfd, (struct sockaddr *)&server, len) < 0)
    {
        printf("Impossibile connettersi al server\n");
        exit(-2);
    }
    // Invio stringa
    write(serverfd, argv[1], sizeof(argv[1]));
    len = read(serverfd, buffer, sizeof(argv[1]));
    if (len != STRLEN)
    {
        buffer[len] = '\0';
    }
    printf("La stringa ordinata è: %s\n", buffer);
    // Chiusura
    close(serverfd);
}