/*
    Data una misura di tempo espressa in secondi S1, convertirla in ore H,
    minuti M e secondi S.

    Esempio: se il numero dei secondi è 1630, si dovrà ottenere, in uscita
    dal programma, 0h 27m 10s.
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    int s, m, h;
    do
    {
        printf("Inserisci il numero di secondi da formattare in hh:mm:ss : ");
        scanf("%d", &s);
    } while (s < 0);
    m = s / 60;
    s = s % 60;
    h = m / 60;
    m = m % 60;
    printf("%dh %dm %ds\n", h, m, s);
    return 0;
}