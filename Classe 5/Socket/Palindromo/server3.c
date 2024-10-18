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
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define PORT 3333
#define BUFFERSIZE 128
#define MAXCLIENT 10

bool isPalindroma(char *str, int stringlen)
{
    int l = 0, r = stringlen - 1;
    while (l < r)
    {
        // Ingnoro caratteri non alfabetici
        while (!isalpha(str[l]))
        {
            l++;
        }
        while (!isalpha(str[r]))
        {
            r--;
        }
        // Controllo se sono arrivato alla fine
        if (l >= r)
        {
            return true;
        }
        // Controllo se è palindroma
        if (tolower(str[l]) != tolower(str[r]))
        {
            return false;
        }
        r--;
        l++;
    }
    return true;
}

int main(int argc, char *argv[])
{
    bool result;
    unsigned char buffer[BUFFERSIZE];
    int serverfd, clientfd, socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in server, client;
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
    bind(serverfd, (struct sockaddr *)&server, socklen);
    listen(serverfd, MAXCLIENT);
    printf("Server avviato\n\n");
    while (1)
    {
        printf("Attesa richieste\n");
        clientfd = accept(serverfd, (struct sockaddr *)&client, &socklen);
        printf("Connessione accettata\n");
        read(clientfd, buffer, BUFFERSIZE);
        printf("Stringa letta: %s\n", buffer);
        result = isPalindroma(buffer, strlen(buffer));
        printf("La stringa %s palindroma\n", result ? "è" : "non è");
        write(clientfd, &result, sizeof(bool));
        printf("Messaggio inviato, chiusura connessione\n\n");
        close(clientfd);
    }
    // Chiusura
    close(serverfd);
    return 0;
}