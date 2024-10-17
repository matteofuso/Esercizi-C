#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define SRV_PORT 9999
#define BUFFERSIZE 128

struct ConteggioLettere
{
    int vocali;
    int consonanti;
};

int main(int argc, char *argv[])
{
    unsigned char buffer[BUFFERSIZE];
    struct ConteggioLettere conteggio;
    int serverfd, socketsize = sizeof(struct sockaddr_in);
    struct sockaddr_in server;
    // Creazione del socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SRV_PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        perror("Errore nella creazione del socket");
        exit(1);
    }
    // Connessione al server
    if (connect(serverfd, (struct sockaddr *)&server, socketsize) == -1)
    {
        printf("Errore nella connessione al server\n");
        exit(2);
    }
    // Invio del messaggio
    printf("Inserisci il messaggio da inviare al server: ");
    fgets(buffer, BUFFERSIZE, stdin);
    if (buffer[strlen(buffer) - 1] == '\n')
    {
        buffer[strlen(buffer) - 1] = '\0';
    }
    write(serverfd, buffer, sizeof(buffer));
    // Ricezione del messaggio
    read(serverfd, &conteggio, sizeof(struct ConteggioLettere));
    printf("Messaggio ricevuto -> Vocali: %d, Consonanti: %d\n", conteggio.vocali, conteggio.consonanti);
    close(serverfd);
    return 0;
}