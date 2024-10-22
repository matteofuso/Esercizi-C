/*
    Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve
    in input 1 stringa e un carattere,e dopo aver effettuato gli eventuali ed opportuni
    controlli (se necessari), rispedisce al Client il numero di occorrenze del carattere
    nella stringa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define PORT 3333
#define BUFFERSIZE 128

struct Richiesta
{
    char stringa[BUFFERSIZE];
    char carattere;
};

int contaCorrispondenze(struct Richiesta richiesta)
{
    int count = 0, len = strlen(richiesta.stringa);
    for (int i = 0; i < len; i++)
    {
        if (richiesta.stringa[i] == richiesta.carattere)
        {
            count++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    struct Richiesta richiesta;
    struct sockaddr_in client, server;
    int serverfd, clientfd, corrispondenze, socketlen = sizeof(struct sockaddr_in);
    // Creazione della socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = ntohl(INADDR_ANY);
    server.sin_port = ntohs(PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-1);
    }
    // Creazione del canale
    bind(serverfd, (struct sockaddr *)&server, socketlen);
    listen(serverfd, 10);
    printf("Server in ascolto alla porta %d\n\n", PORT);
    // Accettazione delle connessioni
    while (1)
    {
        clientfd = accept(serverfd, (struct sockaddr *)&client, &socketlen);
        if (clientfd < 0)
        {
            printf("Tentativo di connessione interrotto\n");
            continue;
        }
        printf("Connessione accettata\n");
        // Elaborazione della richiesta
        read(clientfd, &richiesta, sizeof(struct Richiesta));
        printf("Ricevuta la stringa \"%s\" e il carattere \"%c\"\n", richiesta.stringa, richiesta.carattere);
        corrispondenze = contaCorrispondenze(richiesta);
        write(clientfd, &corrispondenze, sizeof(int));
        printf("Inviato il numero di occorrenze (%d), chiusura connessione\n\n", corrispondenze);
        close(clientfd);
    }
    close(serverfd);
    return 0;
}