#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>

#define PORT 9999
#define BUFFERSIZE 128

struct ConteggioLettere
{
    int vocali;
    int consonanti;
};

bool isVocale(char c)
{
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

struct ConteggioLettere contaletter(char *str)
{
    struct ConteggioLettere conteggio = {0,0};
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (isVocale(str[i]))
        {
            conteggio.vocali++;
        }
        else if (isalpha(str[i]))
        {
            conteggio.consonanti++;
        }
    }
    return conteggio;
}

int main(int argc, char *argv[])
{
    unsigned char buffer[BUFFERSIZE];
    struct ConteggioLettere conteggio;
    int serverfd, clientfd, socketsize = sizeof(struct sockaddr_in);
    struct sockaddr_in server, client;
    // Creazione del socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        perror("Errore nella creazione del socket");
        exit(1);
    }
    // Bind del socket
    bind(serverfd, (struct sockaddr *)&server, sizeof(server));
    listen(serverfd, 10);
    printf("Server in ascolto\n\n");
    while (1)
    {
        // Accettazione della connessione
        clientfd = accept(serverfd, (struct sockaddr *)&client, &socketsize);
        if (clientfd < 0)
        {
            printf("Errore nella connessione\n");
            continue;
        }
        printf("Connessione accettata\n");
        // Ricezione del messaggio
        read(clientfd, buffer, BUFFERSIZE);
        printf("Messaggio ricevuto: %s\n", buffer);
        // Elaborazione del messaggio
        conteggio = contaletter(buffer);
        write(clientfd, &conteggio, sizeof(struct ConteggioLettere));
        printf("Inviato conteggio -> Vocali: %d, Consonanti: %d\n\n", conteggio.vocali, conteggio.consonanti);
        // Chiusura della connessione
        close(clientfd);
    }
    return 0;
}