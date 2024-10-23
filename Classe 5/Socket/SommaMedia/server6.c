/*
    Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve
    in input un vettore di numeri interi, dopo aver effettuato gli eventuali ed opportuni
    controlli (se necessari), rispedisce al Client la somma e la media del vettore stesso.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define SRV_PORT 2323
#define MAXLEN 128

struct SommaMedia
{
    int somma;
    float media;
};

void printArray(int *arr, int len)
{
    printf("[ ");
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\b\b ]\n");
}

struct SommaMedia calcolaSommaMedia(int *arr, int len)
{
    struct SommaMedia sommamedia;
    sommamedia.somma = 0;
    for (int i = 0; i < len; i++)
    {
        sommamedia.somma += arr[i];
    }
    sommamedia.media = (float)sommamedia.somma / len;
    return sommamedia;
}

int main(int argc, char *argv[])
{
    struct SommaMedia sommamedia;
    struct sockaddr_in server, client;
    int serverfd, clientfd, socketlen = sizeof(struct sockaddr_in);
    int arraylen, array[MAXLEN];
    // Creazione socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SRV_PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-1);
    }
    // Assegnazione indirizzo
    bind(serverfd, (struct sockaddr *)&server, socketlen);
    listen(serverfd, 10);
    printf("Server in ascolto\n\n");
    // Accettazione connessione
    while (1)
    {
        clientfd = accept(serverfd, (struct sockaddr *)&client, &socketlen);
        if (clientfd < 0)
        {
            printf("Tentativo di connessione interrotto\n");
            exit(-2);
        }
        printf("Connessione accettata\n");
        // Ricezione array e calcolo somma e media
        arraylen = read(clientfd, array, sizeof(int) * MAXLEN) / sizeof(int);
        printf("Array ricevuto:\n");
        printArray(array, arraylen);
        sommamedia = calcolaSommaMedia(array, arraylen);
        // Invio somma e media e chiusura
        write(clientfd, &sommamedia, sizeof(struct SommaMedia));
        printf("Chiusura della connessione, somma inviata: %d, media inviata %.2f\n\n", sommamedia.somma, sommamedia.media);
        close(clientfd);
    }
    close(serverfd);
    return 0;
}