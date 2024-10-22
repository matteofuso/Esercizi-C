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

#define PORT 5555
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
                char c = str[j];
                str[j] = str[j + 1];
                str[j + 1] = c;
                sorted = false;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    struct sockaddr_in client, server;
    int serverfd, clientfd, socketlen = sizeof(struct sockaddr_in);
    char buffer[STRLEN];
    // Creazione Socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-1);
    }
    // Connessione
    bind(serverfd, (struct sockaddr *)&server, socketlen);
    listen(serverfd, 10);
    printf("Server in ascolto sulla porta %d\n\n", PORT);
    while (1)
    {
        clientfd = accept(serverfd, (struct sockaddr *)&client, &socketlen);
        if (clientfd < 0)
        {
            printf("Tentativo di connessione interrotto\n");
            continue;
        }
        // Elaborazione
        read(clientfd, buffer, STRLEN);
        printf("Stringa ricevuta: %s\n", buffer);
        strSort(buffer, strlen(buffer));
        write(clientfd, buffer, strlen(buffer));
        printf("Chiusura connessione, stringa inviata: %s\n\n", buffer);
        close(clientfd);
    }
    close(serverfd);
}