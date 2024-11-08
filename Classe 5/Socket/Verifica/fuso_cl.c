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
#include <time.h>

#define SRV_PORT 8070
#define MAX_LEN 128

// Riempio l'array con un numero dato di numeri casuali compresi in un intervallo
void fillArray(int *array, int len, int min, int max)
{
    int diff = max - min + 1; // Differenza da utilizzare per sovrascrivere il range 
                              // della funzione rand(), il +1 è per includere max nell'intervallo 
    // Riempio l'array con numeri casuali compresi nell'intervallo
    for (int *i = array; i < array + len; i++)
    {
        *i = rand() % diff + min;
    }
}

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

int main(int argc, char *argv[])
{
    int arraylen, min, max, frequenza;
    int socketfd, socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in server;
    // Controllo il numero degli argomenti a linea di comando
    if (argc != 4)
    {
        printf("Utilizzo %s [len] [min] [max]\n", argv[0]);
        exit(-1);
    }
    // Controllo se la dimensione dell'array è compresa tra 1 e MAX_LEN,
    // controlla anche per errori di atoi, cioè quando ritorna 0
    arraylen = atoi(argv[1]);
    if (arraylen < 1 || arraylen > MAX_LEN)
    {
        printf("La dimensione dell'array deve essere compresa tra 0 e %d\n", MAX_LEN);
        exit(-2);
    }
    // Controllo il numero minimo ed il massimo
    // controlla anche per errori di atoi, cioè quando ritorna 0
    min = atoi(argv[2]);
    max = atoi(argv[3]);
    if (min < 1 || max < min)
    {
        printf("Il numero minimo deve essere almeno 1, oppure l'ordine MIN MAX è invertito\n");
        exit(-3);
    }
    // Riempio l'array
    int array[arraylen];
    srand(time(NULL)); // Imposto il seed per la generazione di numeri casuali all'ora di adesso
                       // per rendere i numeri random diversi ad ogni avvio
    fillArray(array, arraylen, min, max);
    printf("Array generato:\n");
    printArray(array, arraylen);
    // Definisco l'indirizzo e la porta di ascolto del server
    server.sin_family = AF_INET; // Definisco la famiglia del socket come AF_INET cioè internet con IPv4
    server.sin_addr.s_addr = htonl(INADDR_ANY); // Accetta connessioni da tutti gli indirizzi in ingresso
    server.sin_port = htons(SRV_PORT); // Accetta le connessioni sulla porta PORT
    // Creo la socket e gli lego l'indirizzo e la porta appena definiti
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    // Controllo se ci sono stati errori
    if (socketfd < 0)
    {
        printf("Errore nella creazione della socket\n");
        exit(-4);
    }
    // Avvio la connessione con il server e controllo se ci sono stati errori
    if (connect(socketfd, (struct sockaddr *)&server, socklen) < 0)
    {
        printf("Errore nella connessione con il server\n");
        exit(-5);
    }
    // Invio l'array al server e controllo se è stato inviato almeno un byte
    // cioè se ci sono stati errori
    if (write(socketfd, array, arraylen * sizeof(int)) < 1)
    {
        printf("Errore nell'invio dell'array\n");
        close(socketfd);
        exit(-6);
    }
    // Ricezione nuovo array e frequenza e controllo se è stato ricevuto almeno un byte
    // cioè se ci sono stati errori
    if (read(socketfd, &frequenza, sizeof(int)) < 0)
    {
        printf("Errore nella ricezione della frequenza\n");
        close(socketfd);
        exit(-7);
    }
    if (read(socketfd, array, arraylen * sizeof(int)) < 0)
    {
        printf("Errore nella ricezione dell'array invertito\n");
        close(socketfd);
        exit(-8);
    }
    // Stampa valori elaborati
    printf("Il primo valore è contenuto %d volte nell'array. L'array invertito è:\n", frequenza);
    printArray(array, arraylen);
    // Chiudo il file descriptor del server e chiudo il programma
    close(socketfd);
    return 0;
}