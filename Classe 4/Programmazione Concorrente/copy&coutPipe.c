#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_DIM 1024

int main(int argc, char **argv)
{
    int PIDC1, PIDC2;
    int fd[4];
    FILE *f;
    // Check if the numer of argument is correct
    if (argc != 4)
    {
        printf("Uso: %s [<origin file>] [<destination file>] [<char to count>]\n", argv[0]);
        exit(-1);
    }
    // Open the pipes
    if (pipe(fd) < 0)
    {
        printf("Error creating the first pipe\n");
        exit(-1);
    }
    if (pipe(fd + 2) < 0)
    {
        printf("Error creating the first pipe\n");
        exit(-1);
    }
    // Create the first child
    PIDC1 = fork();
    if (PIDC1 < 0)
    {
        printf("Error creating the first child\n");
        for (int i = 0; i < 4; i++)
        {
            close(fd[i]);
        }
        exit(-1);
    }
    if (PIDC1)
    {
        // Create the second child
        PIDC2 = fork();
        if (PIDC2 < 0)
        {
            printf("Error creating the second child\n");
            for (int i = 0; i < 4; i++)
            {
                close(fd[i]);
            }
            wait(NULL);
            exit(-1);
        }
        if (PIDC2)
        {
            // Parent
            int n;
            char buffer[BUFFER_DIM];
            close(fd[0]);
            close(fd[2]);
            // Open the file
            f = fopen(argv[1], "r");
            if (f == NULL)
            {
                printf("Error while opening the origin file\n");
                close(fd[1]);
                close(fd[3]);
                wait(NULL);
                wait(NULL);
                exit(-1);
            }
            // Read from the file, write to the pipe
            while ((n = fread(buffer, sizeof(char), sizeof(buffer), f)) > 0)
            {
                write(fd[1], buffer, n);
            }
            // Close the file, the first pipe and wait the first child
            fclose(f);
            close(fd[1]);
            wait(NULL);
            // Sync the third child, close the second pipe and wait the second child
            write(fd[3], &n, sizeof(int));
            close(fd[3]);
            wait(NULL);
        }
        else
        {
            // Child 2
            int n, c;
            close(fd[0]);
            close(fd[1]);
            close(fd[3]);
            // Sync
            read(fd[2], &n, sizeof(int));
            // Open the destination file
            f = fopen(argv[2], "r");
            if (f == NULL)
            {
                printf("Error while opening the destination file\n");
                close(fd[2]);
                exit(-1);
            }
            // Check each character for occurency
            while ((c = fgetc(f)) != EOF)
            {
                if (c == argv[3][0])
                {
                    n++;
                }
            }
            printf("There are %d %c in the destination file\n", n, argv[3][0]);
            // Close the pipe and the file
            fclose(f);
            close(fd[2]);
        }
    }
    else
    {
        // Child 1
        int n;
        char buffer[BUFFER_DIM];
        close(fd[1]);
        close(fd[2]);
        close(fd[3]);
        // Open the destination file
        f = fopen(argv[2], "w");
        if (f == NULL)
        {
            printf("Error while opening the destination file\n");
            close(fd[2]);
            exit(-1);
        }
        // Read from the pipe and write to the file
        while ((n = read(fd[0], buffer, sizeof(buffer))) > 0)
        {
            fwrite(buffer, sizeof(char), n, f);
        }
        // Close the pipe and the file
        fclose(f);
        close(fd[0]);
    }
    return 0;
}