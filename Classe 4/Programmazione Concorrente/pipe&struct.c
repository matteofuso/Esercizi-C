#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct
{
    char titolo[100];
    char autore[100];
    double prezzo;
} Libro;

int main(int argc, char **argv)
{
    int pid, fd[2];
    Libro libri[2];
    int numeroLibri = sizeof(libri) / sizeof(Libro);
    if (pipe(fd) == -1)
    {
        printf("Errore nell'aperture della pipe\n");
        exit(-1);
    }
    pid = fork();
    if (pid < 0)
    {
        printf("Errore nella creazione di un processo figlio\n");
        close(fd[0]);
        close(fd[1]);
        exit(-1);
    }
    if (pid)
    {
        // Padre
        close(fd[0]);
        for (int i = 0; i < numeroLibri; i++)
        {
            printf("Inserisci il titolo del %d libro: ", i + 1);
            scanf("%s", i[libri].titolo);
            printf("Inserisci l'autore del %d libro: ", i + 1);
            scanf("%s", (libri + i)->autore);
            printf("Inserisci il prezzo del %d libro: ", i + 1);
            scanf("%lf", &libri[i].prezzo);
            printf("\n");
            write(fd[1], libri + i, sizeof(Libro));
        }
        // write(fd[1], libri, sizeof(Libro) * numeroLibri);
        close(fd[1]);
        wait(NULL);
    }
    else
    {
        // Figlio
        close(fd[1]);
        // read(fd[0], libri, sizeof(Libro) * numeroLibri);
        for (int i = 0; i < numeroLibri; i++)
        {
            read(fd[0], libri + i, sizeof(Libro));
        }
        for (int i = 0; i < numeroLibri; i++)
        {
            printf("Libro %d:\n", i + 1);
            printf("Titolo: %s\n", i[libri].titolo);
            printf("Autore: %s\n", (libri + i)->autore);
            printf("Prezzo: %.2lf\n", libri[i].prezzo);
            printf("\n");
        }
        close(fd[0]);
    }
    return 0;
}