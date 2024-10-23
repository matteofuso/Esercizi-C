/*
    Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve in
    input un vettore di numeri interi, dopo aver effettuato gli eventuali ed opportuni controlli
    (se necessari), rispedisce al Client la somma e la media dei numeri pari e la somma e la
    media dei numeri dispari.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <stdbool.h>

#define SRV_PORT 2323
#define MAXLEN 128

struct SommaMedia
{
    int somma;
    float media;
};

struct SommaMedia calcolaSommaMedia(int *arr, int len, bool pari)
{
    struct SommaMedia sommamedia;
    int count = 0;
    sommamedia.somma = 0;
    for (int i = 0; i < len; i++)
    {
        if (pari && arr[i] % 2 == 0)
        {
            sommamedia.somma += arr[i];
            count++;
        }
        else if (!pari && arr[i] % 2 != 0)
        {
            sommamedia.somma += arr[i];
            count++;
        }
    }
    if (count == 0)
    {
        sommamedia.media = 0;
        return sommamedia;
    }
    sommamedia.media = (float)sommamedia.somma / count;
    return sommamedia;
}

void printArray(int *arr, int len)
{
    printf("[ ");
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\b\b ]\n");
}

int main(int argc, char *argv[])
{
    struct SommaMedia sommamediaPari, sommamediaDispari;
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
        sommamediaPari = calcolaSommaMedia(array, arraylen, true);
        sommamediaDispari = calcolaSommaMedia(array, arraylen, false);
        // Invio somma e media e chiusura
        write(clientfd, &sommamediaPari, sizeof(struct SommaMedia));
        write(clientfd, &sommamediaDispari, sizeof(struct SommaMedia));
        printf("Chiusura della connessione\n");
        printf("Somma e media numeri pari inviata: %d, media inviata %.2f\n", sommamediaPari.somma, sommamediaPari.media);
        printf("Somma e media numeri dispari inviata: %d, media inviata %.2f\n\n", sommamediaDispari.somma, sommamediaDispari.media);
        close(clientfd);
    }
    close(serverfd);
    return 0;
}