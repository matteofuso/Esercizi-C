#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        printf("Sono il primo processo, il mio PID è %d\n", getpid());
        execl(argv[0], "ciao", "buongiorno", NULL);
        printf("Errore nell'invocazione della execl\n");
        return -1;
    }
    else
    {
        printf("\nSono il secondo processo, il mio PID è %d\n", getpid());
        printf("Parametri passati:\n");
        for (int i = 0; i < argc; i++)
        {
            printf("%d - %s\n", i, argv[i]);
        }
    }
    return 0;
}