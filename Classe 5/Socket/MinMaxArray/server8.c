/*
    Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve
    in input un vettore di numeri interi, dopo aver effettuato gli eventuali ed opportuni 
    controlli (se necessari), rispedisce al Client il massimo ed il minimo .
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>

#define SRV_PORT 9045
#define MAXLEN 128

struct MassimoMinimo
{
    int massimo;
    int minimo;
};

struct MassimoMinimo calcolaMassimoMinimo(int *array, int len)
{
    struct MassimoMinimo massimominimo = {array[0], array[0]};
    for (int i = 1; i < len; i++)
    {
        if (array[i] < massimominimo.minimo)
        {
            massimominimo.minimo = array[i];
        }
        else if (array[i] > massimominimo.massimo)
        {
            massimominimo.massimo = array[i];
        }
    }
    return massimominimo;
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
    struct MassimoMinimo massimominimo;
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
        massimominimo = calcolaMassimoMinimo(array, arraylen);
        // Invio somma e media e chiusura
        write(clientfd, &massimominimo, sizeof(struct MassimoMinimo));
        printf("Chiusura della connessione. Numero massimo inviato: %d, numero minimo: %d\n\n", massimominimo.massimo, massimominimo.minimo);
        close(clientfd);
    }
    close(serverfd);
    return 0;
}