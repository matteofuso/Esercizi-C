/*
    Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve
    in input 1 stringa e, dopo aver effettuato gli eventuali ed opportuni controlli (se necessari),
    rispedisce al Client il messaggio se è palindroma oppure non lo è.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define SRV_PORT 3333
#define BUFFERSIZE 128

int main(int argc, char *argv[])
{
    bool risultato;
    int serverfd;
    struct sockaddr_in server;
    // Controllo argomenti
    if(argc != 2)
    {
        printf("Uso: %s <string>\n", argv[0]);
        exit(-1);
    }
    // Creazione Socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SRV_PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-1);
    }
    // Connessione
    if(connect(serverfd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Impossibile connettersi al server\n");
        exit(-2);
    }
    // Invio stringa
    write(serverfd, argv[1], BUFFERSIZE);
    // Ricezione risultato
    read(serverfd, &risultato, sizeof(bool));
    printf("La stringa %s palindroma\n", risultato ? "è" : "non è");
    // Chiusura
    close(serverfd);
    return 0;
}