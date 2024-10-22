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

#define SRV_PORT 3333
#define BUFFERSIZE 128

struct Richiesta
{
    char stringa[BUFFERSIZE];
    char carattere;
};

int main(int argc, char *argv[])
{
    struct Richiesta richiesta;
    struct sockaddr_in server;
    int serverfd, clientfd, corrispondenze, socketlen = sizeof(struct sockaddr_in);
    // Controllo argomenti
    if (argc != 3)
    {
        printf("Errore nel numero di argomenti\n");
        printf("Usa %s [stringa] [carattere]\n", argv[0]);
        exit(-1);
    }
    // Creazione della struttura
    strcpy(richiesta.stringa, argv[1]);
    richiesta.carattere = argv[2][0];
    // Creazione della socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = ntohl(INADDR_ANY);
    server.sin_port = ntohs(SRV_PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-2);
    }
    // Connessione al server
    if (connect(serverfd, (struct sockaddr *)&server, socketlen) < 0)
    {
        printf("Errore nella connessione con il server\n");
        exit(-3);
    }
    // Invio della richiesta
    write(serverfd, &richiesta, sizeof(struct Richiesta));
    read(serverfd, &corrispondenze, sizeof(int));
    printf("La stringa contiene %d corrispondenze\n", corrispondenze);
    // Chiusura
    close(serverfd);
    return 0;
}