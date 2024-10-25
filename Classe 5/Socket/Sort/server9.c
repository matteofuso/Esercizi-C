/*
    Scrivere il codice in C, di un applicazione Socket CLIENT-SERVER in cui il server riceve
    in input un vettore di numeri interi, dopo aver effettuato gli eventuali ed opportuni 
    controlli (se necessari), rispedisce al Client il vettore ordinato in modo crescente
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <stdbool.h>

#define PORT 8021
#define MAXLEN 128

void sort(int *str, int arraylen)
{
    bool sorted = false;
    for (int i = 0; i < arraylen - 1 && !sorted; i++)
    {
        sorted = true;
        for (int j = 0; j < arraylen - i - 1; j++)
        {
            if (str[j] > str[j + 1])
            {
                int temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
                sorted = false;
            }
        }
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
    int serverfd, clientfd, socketlen = sizeof(struct sockaddr_in);
    int arraylen, array[MAXLEN];
    // Creazione socket
    struct sockaddr_in server, client;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(PORT);
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0)
    {
        printf("Errore nella creazione del socket");
        exit(1);
    }
    // Listen
    bind(serverfd, (struct sockaddr *)&server, sizeof(server));
    listen(serverfd, 10);
    printf("Server in ascolto sulla porta %d\n\n", PORT);
    // Ciclo di accettazione connessioni
    while (1)
    {
        clientfd = accept(serverfd, (struct sockaddr *)&client, &socketlen);
        if (clientfd < 0)
        {
            printf("Tentativo di connessione fallito\n");
            continue;
        }
        printf("Connessione accettata\n");
        // Ricezione array
        arraylen = read(clientfd, &array, sizeof(int) * MAXLEN) / sizeof(int);
        printf("Array ricevuto: \n");
        printArray(array, arraylen);
        // Elaborazione e invio
        sort(array, arraylen);
        write(clientfd, array, sizeof(int) * arraylen);
        printf("Chiusura connessione. Array inviato: \n");
        printArray(array, arraylen);
        // Chiusura connessione
        close(clientfd);
    }
    close(serverfd);
    return 0;
}