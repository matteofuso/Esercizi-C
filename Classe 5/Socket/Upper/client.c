/*
    Scrivere Un applicazione Client Server in C o in cui il server
    dopo aver ricevuto una stringa dal Client la restituisce (sempre al Client)
    la stringa in maiuscolo
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define SRV_PORT 2021
#define BUFFERSIZE 1024

int main(int argc, char *argv[])
{
    int socketfd, soa;
    unsigned char buffer[BUFFERSIZE];
    // Creazione del socket
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SRV_PORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("Errore nella creazione del socket");
        exit(1);
    }
    // Connessione al server
    connect(socketfd, (struct sockaddr *)&server, sizeof(server));
    printf("Connessione al server riuscita\n");
    // Invio del messaggio
    printf("Inserisci il messaggio da inviare al server: ");
    scanf(" %[^\n]", buffer);
    write(socketfd, buffer, BUFFERSIZE);
    // Ricezione del messaggio
    read(socketfd, buffer, BUFFERSIZE);
    printf("Messaggio ricevuto: %s\n", buffer);
    close(socketfd);
    return 0;
}