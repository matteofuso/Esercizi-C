/*
    Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server
    riceve in input un vettore di numeri e dopo aver effettuato gli eventuali ed opportuni
    controlli (se necessari), rispedisce al Client il conteggio dei numeri pari e dei
    numeri dispari contenuti nel vettore.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define SRV_PORT 9050
#define MAXLEN 128

struct ConteggioPariDispari
{
    int pari;
    int dispari;
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

int main(int argc, char *argv[])
{
    int arraylen;
    int socketfd, socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in server;
    struct ConteggioPariDispari conteggio;
    // Controllo argomenti e riempimento array
    if (argc != 4)
    {
        printf("Uso: %s [dimensione] [min] [max]\n", argv[0]);
        exit(-1);
    }
    arraylen = atoi(argv[1]);

    int array[arraylen];
    srand(time(NULL));
    fillArray(array, arraylen, atoi(argv[2]), atoi(argv[3]));
    // Crazione socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(SRV_PORT);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
    {
        printf("Errore nella creazione del socket\n");
        exit(-2);
    }
    // Connessione al server
    if (connect(socketfd, (struct sockaddr *)&server, socklen) < 0)
    {
        printf("Impossibile connettersi al server\n");
        close(socketfd);
        exit(-3);
    }
    // Invio
    if (write(socketfd, array, sizeof(int) * arraylen) < 1)
    {
        printf("Errore nell'invio dell'array\n");
        close(socketfd);
        exit(-4);
    }
    printf("Invio dell'array riuscito:");
    printArray(array, arraylen);
    // Ricezione
    if (read(socketfd, &conteggio, sizeof(struct ConteggioPariDispari)) < 1)
    {
        printf("Errore nel formato della risposta\n");
        close(socketfd);
        exit(-5);
    }
    printf("L'array contiene %d numeri pari e %d numeri dispari\n", conteggio.pari, conteggio.dispari);
    close(socketfd);
    return 0;
}