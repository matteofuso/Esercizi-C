#include <stdio.h>

int main(int argc, char *argv[])
{
    char carattere; // Posso inserire tutti i caratteri della tabella ascii
    printf("Inserisci il carattere: ");
    // scanf("%c", &carattere); Metodo classico
    carattere = getchar();
    printf("Hai inserito il seguente carattere: %c\n", carattere);
    printf("Il codice ASCII del carattere inserito è: %d\n", carattere);
    return 0;
}