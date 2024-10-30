/*
    Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve
    in input 2 stringhe e, dopo aver effettuato gli eventuali ed opportuni controlli
    (se necessari), rispedisce al Client il messaggio di quale delle due stringhe è più
    lunga o più corta o se sono uguali.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define SRV_PORT 8021
#define MAXLEN 128

int main(int argc, char *argv[])
{
    char buffer[MAXLEN];
    int lendiff;
    int serverfd, clientfd, socketlen = sizeof(struct sockaddr_in);
    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_port = htons(SRV_PORT);
    server.sin_addr.s_addr = INADDR_ANY;
    // Creazione socket
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        printf("Errore creazione socket");
        exit(-1);
    }
    bind(serverfd, (struct sockaddr *)&server, sizeof(server));
    // Server in ascolto
    listen(serverfd, 10);
    printf("Server in ascolto sulla porta %d\n\n", SRV_PORT);
    // Ciclo di accettazione
    while (1)
    {
        clientfd = accept(serverfd, (struct sockaddr *)&client, &socketlen);
        if (clientfd < 0)
        {
            printf("Tentativo di connessione fallito\n\n");
            continue;
        }
        // Lettura stringhe
        read(clientfd, buffer, MAXLEN * sizeof(char));
        printf("Stringa 1: %s\n", buffer);
        lendiff = strlen(buffer);
        read(clientfd, buffer, MAXLEN * sizeof(char));
        printf("Stringa 2: %s\n", buffer);
        lendiff -= strlen(buffer);
        // Invio risultato e chisuura connessione
        printf("Differenza lunghezza: %d\n\n", lendiff);
        write(clientfd, &lendiff, sizeof(int));
        close(clientfd);
    }
    close(serverfd);
    return 0;
}