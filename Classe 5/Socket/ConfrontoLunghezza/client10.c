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
    int lendiff;
    int serverfd, clientfd, socketlen = sizeof(struct sockaddr_in);
    struct sockaddr_in server, client;
    // Controllo argomenti
    if (argc != 3)
    {
        printf("Uso: %s [stringa1] [stringa2]\n", argv[0]);
        exit(-1);
    }
    server.sin_family = AF_INET;
    server.sin_port = htons(SRV_PORT);
    server.sin_addr.s_addr = INADDR_ANY;
    // Creazione socket
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        printf("Errore creazione socket");
        exit(-2);
    }
    // Connessione al server
    if (connect(serverfd, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("Errore connessione al server\n");
        exit(-3);
    }
    // Invio stringhe
    write(serverfd, argv[1], MAXLEN * sizeof(char));
    write(serverfd, argv[2], MAXLEN * sizeof(char));
    // Ricezione e stampa risultato
    read(serverfd, &lendiff, sizeof(int));
    if (lendiff > 0)
    {
        printf("La prima stringa è più lunga della seconda di %d caratteri\n", lendiff);
    }
    else if (lendiff < 0)
    {
        printf("La seconda stringa è più lunga della prima di %d caratteri\n", -lendiff);
    }
    else
    {
        printf("Le stringhe sono lunghe uguali\n");
    }
    close(serverfd);
    return 0;
}