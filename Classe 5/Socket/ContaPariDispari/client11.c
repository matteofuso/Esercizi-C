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

int main(int argc, char *argv[])
{
    return 0;
}