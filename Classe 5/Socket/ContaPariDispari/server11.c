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

#define PORT 9050
#define MAXLEN 128
#define MAXCLIENTS 10

struct ConteggioPariDispari
{
    int pari;
    int dispari;
};

struct ConteggioPariDispari contaPariDispari(int *array, int arraylen)
{
    struct ConteggioPariDispari conteggio = {0,0};
    for (int *i = array; i < array + arraylen; i++)
    {
        if (*i % 2 == 0)
        {
            conteggio.pari++;
            continue;
        }
        conteggio.dispari++;
    }
    return conteggio;
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
    int array[MAXLEN], arraylen;
    struct ConteggioPariDispari conteggio;
    int serverfd, clientfd, socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in client, server;
    // Creazione socket
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-1);
    }
    // Bind indirizzo
    if (bind(serverfd, (struct sockaddr *)&server, socklen) < 0)
    {
        printf("Impossibile aprire il server nella porta %d\n", PORT);
        close(serverfd);
        exit(-2);
    }
    // Ciclo principale
    if (listen(serverfd, MAXCLIENTS) < 0)
    {
        printf("Errore nella preparazione per l'ascolto\n");
        close(serverfd);
        exit(-3);
    }
    printf("Server in ascolto nella porta %d\n\n", PORT);
    while (1)
    {
        // Accettazione connessione
        clientfd = accept(serverfd, (struct sockaddr *)&client, &socklen);
        if (clientfd < 0)
        {
            printf("Tentativo di connessione interrotto\n\n");
            continue;
        }
        printf("Connessione accettata\n");
        // Ricezione
        arraylen = read(clientfd, array, sizeof(int) * MAXLEN) / sizeof(int);
        if (arraylen < 1)
        {
            printf("Errore nel formato della richiesta\n\n");
            close(clientfd);
            continue;
        }
        printf("Array ricevuto: \n");
        printArray(array, arraylen);
        // Elaborazione
        conteggio = contaPariDispari(array, arraylen);
        // Invio elaborazione e chiusura
        if (write(clientfd, &conteggio, sizeof(struct ConteggioPariDispari)) < 1)
        {
            printf("Errore nell'invio della risposta elaborata\n\n");
            close(clientfd);
            continue;
        }
        printf("Invio elaborazione con successo. Conteggio numeri pari: %d, conteggio numeri dispari: %d\n\n", conteggio.pari, conteggio.dispari);
        close(clientfd);
    }
    close(serverfd);
    return 0;
}