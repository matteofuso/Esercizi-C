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

void fillArray(int *arr, int len, int min, int max)
{
    int diff = max - min + 1;
    if (diff < 0)
    {
        diff *= -1;
        min = max;
    }
    for (int i = 0; i < len; i++)
    {
        arr[i] = min + rand() % diff;
    }
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
    struct SommaMedia sommamedia;
    struct sockaddr_in server;
    int socketfd, socketlen = sizeof(struct sockaddr_in);
    int arraylen;
    // Controllo argomenti
    if (argc != 4)
    {
        printf("Uso: %s [lunghezza] [minimo] [massimo]\n", argv[0]);
        exit(-1);
    }
    arraylen = atoi(argv[1]);
    if (arraylen < 0 || arraylen > MAXLEN)
    {
        printf("Lunghezza non valida\n");
        exit(-2);
    }
    // Riempimento array
    int array[arraylen];
    srand(time(NULL));
    fillArray(array, arraylen, atoi(argv[2]), atoi(argv[3]));
    printf("Array generato: \n");
    printArray(array, arraylen);
    // Creazione socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SRV_PORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-3);
    }
    // Connessione al server
    if (connect(socketfd, (struct sockaddr *)&server, socketlen) < 0)
    {
        printf("Errore nella connessione al server");
        close(socketfd);
        exit(-4);
    }
    // Invio array
    write(socketfd, array, arraylen * sizeof(int));
    // Ricezione Somma e Media
    read(socketfd, &sommamedia, sizeof(struct SommaMedia));
    printf("La somma dei numeri è %d, la media %.2f\n", sommamedia.somma, sommamedia.media);
    close(socketfd);
    return 0;
}