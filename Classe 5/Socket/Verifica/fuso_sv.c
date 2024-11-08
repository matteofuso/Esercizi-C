/*
    Scrivere il codice di un'applicazione socket client-server in linguaggio C. L'applicazione
    deve consentire al client di inviare al server un vettore di numeri interi maggiori di zero.
    Il server dovrà analizzare il vettore ricevuto dal client e restituire al client: il vettore
    con le componenti alternate a due a due (esempio: Vettore inserito: 1,2,3,4 -  vettore
    alternato: 2,1,4,3 ) e la frequenza della prima componente all’interno del vettore stesso
    (esempio: Vettore inserito: 1,2,1,4  - la prima componente si ripete 2 volte all’interno
    del vettore).
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define PORT 8070
#define LISTEN_CLIENTS 10
#define MAX_LEN 128

// Funzione per stampare in maniera ordinata l'array
void printArray(int *array, int len)
{
    printf("[ ");
    for (int i = 0; i < len; i++)
    {
        printf("%d, ", array[i]);
    }
    printf("\b\b ]\n"); // il carattere backslash (\b) serve per portare indietro di
                        // un carattere il cursore nella stdout
}

// Funzione per alternare gli elementi di un array
void alternaElementi(int *array, int len)
{
    int temp;
    int evenLen = len - len % 2; // Se l'array è dispari, l'ultimo elemento non va invertito
    // Ciclo l'array a due a due per invertire gli elementi
    for (int i = 0; i < evenLen; i += 2)
    {
        // Alterno gli elelementi
        temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
}

// Conta la frequenza di un numero in un array
int contaFrequenza(int *array, int len, int numero)
{
    int frequenza = 0; // Frequenza inizializzata a zero in caso non ci siano corrispondenze
    // Ciclo ogni numero e controllo se corrisponde
    for (int *i = array; i < array + len; i++)
    {
        // In caso il numero corrisponda, incremento di uno la frequenza
        if (*i == numero)
        {
            frequenza++;
        }
    }
    // Ritorno la frequenza
    return frequenza;
}

int main(int argc, char *argv[])
{
    int array[MAX_LEN], arraylen, frequenza;
    int serverfd, clientfd, socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in server, client;
    // Definisco l'indirizzo e la porta di ascolto del server
    server.sin_family = AF_INET; // Definisco la famiglia del socket come AF_INET cioè internet con IPv4
    server.sin_addr.s_addr = htonl(INADDR_ANY); // Accetta connessioni da tutti gli indirizzi in ingresso
    server.sin_port = htons(PORT); // Accetta le connessioni sulla porta PORT
    // Creo la socket
    serverfd = socket(AF_INET, SOCK_STREAM, 0); // Creo un socket IPv4 dove invio e ricezione solo slegati
    // Controllo se ci sono errori nella creazione del socket
    if (serverfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-1);
    }
    // Lego l'indirizzo e la porta appena definiti al socket e controllo se ci sono errori
    if (bind(serverfd, (struct sockaddr *)&server, socklen) < 0)
    {
        printf("Errore nel tentativo di uso della porta %d\n", PORT);
        exit(-2);
    }
    // Metto il server in ascolto
    listen(serverfd, LISTEN_CLIENTS);
    // Ciclo principale
    printf("Server in ascolto sulla porta %d\n", PORT);
    while (1)
    {
        // Pulisco lo stdout in caso di sporcizia nelle iterazioni precedenti
        fflush(stdout);
        // Accetto la connessione da parte del client
        clientfd = accept(serverfd, (struct sockaddr *)&client, &socklen);
        // Controllo se ci sono stati errori di connessione
        if (clientfd < 0)
        {
            printf("Errore nel tentativo di connessione da parte di un client\n\n");
            continue;
        }
        printf("Connessione accettata\n");
        // Ricezione array
        arraylen = read(clientfd, array, MAX_LEN) / sizeof(int);
        // Controllo se è stato inviato almeno un byte, cioè se ci sono stati errori
        if (arraylen < 1)
        {
            printf("Errore nel formato della risposta\n\n");
            close(clientfd);
            continue;
        }
        printf("Array ricevuto:\n");
        printArray(array, arraylen);
        // Elaborazione dell'array
        frequenza = contaFrequenza(array, arraylen, array[0]);
        alternaElementi(array, arraylen);
        printf("Il primo elemento compare %d volte, l'array invertito è:\n", frequenza);
        printArray(array, arraylen);
        // Invio array elaborato e frequenza del primo elemento e controllo se è stato inviato
        // almeno un byte, cioè se ci sono errori
        if (write(clientfd, &frequenza, sizeof(int)) < 1)
        {
            printf("Errore nell'invio della frequenza\n\n");
            close(clientfd);
            continue;
        }
        if (write(clientfd, array, arraylen * sizeof(int)) < 1)
        {
            printf("Errore nell'invio del nuovo array\n\n");
            close(clientfd);
            continue;
        }
        printf("Invio dati eseguito con successo\n\n");
        // Chiudo il file descriptor della socket del client
        close(clientfd);
    }
    // Chiudo il file descriptor del server e chiudo il programma
    close(serverfd);
    return 0;
}