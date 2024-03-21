#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define PROGRAM "./consumatore"

int spawn(char *program, char **arguments)
{
    int pid;
    printf("\nSono il padre spawn, il mio PID è %d\n", getpid());
    pid = fork();
    if (pid < 0)
    {
        // Errore nella creazione della fork
        return -1;
    }
    if (pid > 0)
    {
        printf("\nSono il padre spawn, il mio figio ha PID %d\n", pid);
        return 0;
    }
    printf("\nSono il figlio spawn, il mio PID è %d\n", getpid());
    execv(program, arguments);
    printf("Errore nella chiamata execv\n");
    abort();
}

int main(int argc, char **argv)
{
    FILE *file;
    int fifo;
    unsigned char buffer[BUFFER_SIZE];
    int n;
    char *arg[3];
    int a;

    printf("\nSono il padre main ossia il processo produttore, il mio PID è %d\n", getpid());
    if (argc != 3)
    {
        printf("Uso %s [<file_origine>] [<file_destinazione>]\n", argv[0]);
        exit(-1);
    }

    arg[0] = (char *)malloc(strlen(PROGRAM) + 1);
    strcpy(arg[0], PROGRAM);

    arg[1] = (char *)malloc(strlen(argv[2]) + 1);
    strcpy(arg[1], argv[2]);

    arg[2] = NULL;

    if (spawn(PROGRAM, arg) < 0)
    {
        printf("Errore nella creazione del processo figlio\n");
        free(arg[0]);
        free(arg[1]);
        exit(-2);
    }

    printf("\narg[0] = %s\n", arg[0]);
    if (mkfifo("fifo.fifo", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Errore nella creazione della fifo\n");
            free(arg[0]);
            free(arg[1]);
            exit(-3);
        }
    }

    fifo = open("fifo.fifo", O_WRONLY);
    if (fifo < 0)
    {
        printf("Errore nell'apertura della fifo\n");
        free(arg[0]);
        free(arg[1]);
        exit(-4);
    }

    file = fopen(argv[1], "rb");
    if (file == NULL)
    {
        printf("Errore nell'apertura del file %s\n", argv[1]);
        close(fifo);
        free(arg[0]);
        free(arg[1]);
        exit(-5);
    }

    while (!feof(file))
    {
        n = fread(buffer, 1, BUFFER_SIZE, file);
        if (n > 0)
        {
            write(fifo, buffer, n);
        }
    }

    close(fifo);
    fclose(file);
    free(arg[0]);
    free(arg[1]);
    return 0;
}