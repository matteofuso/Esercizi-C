#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    int fd[2], pid1, pid2, n;
    FILE *f;
    // Check if the numer of argument is correct
    if (argc != 4)
    {
        printf("Uso: %s [<origin file>] [<destination file>] [<char>]\n", argv[0]);
        exit(-1);
    }
    // Check if there were an error calling the pipe api
    if (pipe(fd))
    {
        printf("Error calling the pipe api\n");
        exit(-1);
    }
    pid1 = fork();
    // Check if there were an error calling the fork api
    if (pid1 == -1)
    {
        printf("Error calling the fork api\n");
        close(fd[0]);
        close(fd[1]);
        exit(-1);
    }
    // Differenciate process
    if (pid1)
    {
        pid2 = fork();
        if (pid2 == -1)
        {
            printf("Error calling the fork api\n");
            close(fd[0]);
            close(fd[1]);
            exit(-1);
        }
        if (pid2)
        {
            // Parent
            char buffer[BUFFER_SIZE];
            close(fd[0]);
            // Check if the file is opened successfully
            if (!(f = fopen(argv[1], "r")))
            {
                printf("Error while opening file %s\n", argv[1]);
                close(fd[1]);
                wait(NULL);
                exit(-1);
            }
            // Read from the file, then send through the pipe
            while ((n = fread(buffer, sizeof(char), BUFFER_SIZE, f)) > 0)
            {
                write(fd[1], buffer, n);
            }
            // Close and exit
            fclose(f);
            close(fd[1]);
            wait(NULL);
            wait(NULL);
        }
        else
        {
            int c, counter = 0;
            close(fd[0]);
            close(fd[1]);
            waitpid(pid1, NULL, 0);
            // Check if the file is opened successfully
            if ((f = fopen(argv[2], "r")))
            {
                // Read
                while ((c = getc(f)) != EOF)
                {
                    if (c == argv[3][0])
                    {
                        counter++;
                    }
                }
                printf("Nel file sono state trovate %d %c\n", counter, argv[3][0]);
                fclose(f);
            }
        }
    }
    else
    {
        // Child
        char buffer[BUFFER_SIZE];
        close(fd[1]);
        // Check if the file is opened successfully
        if (!(f = fopen(argv[2], "w")))
        {
            printf("Error while opening file %s\n", argv[2]);
            close(fd[0]);
            exit(-1);
        }
        // Read from the pipe, then write to the file
        while ((n = read(fd[0], buffer, BUFFER_SIZE)) > 0)
        {
            fwrite(buffer, sizeof(char), n, f);
        }
        // Close and exit
        fclose(f);
        close(fd[0]);
    }
    return 0;
}