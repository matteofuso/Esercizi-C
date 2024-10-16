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

#define PORT 2021
#define BUFFERSIZE 1024

int upperString(char *str)
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = toupper(str[i]);
    }
}

int main(int argc, char *argv[])
{
    unsigned char buffer[BUFFERSIZE];
    // Creazione del socket
    struct sockaddr_in server, client;
    int socketfd, soa, len = sizeof(client);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        perror("Errore nella creazione del socket");
        exit(1);
    }
    // Bind del socket
    bind(socketfd, (struct sockaddr *)&server, sizeof(server));
    listen(socketfd, 10);
    printf("Server in ascolto\n\n");
    // Accettazione della connessione
    while (1)
    {
        soa = accept(socketfd, (struct sockaddr *)&client, &len);
        printf("Connessione accettata\n");
        read(soa, buffer, BUFFERSIZE);
        printf("Messaggio ricevuto: %s\n", buffer);
        upperString(buffer);
        printf("Messaggio inviato: %s\n", buffer);
        write(soa, buffer, BUFFERSIZE);
        close(soa);
        printf("Connessione chiusa\n\n");
    }
    return 0;
}