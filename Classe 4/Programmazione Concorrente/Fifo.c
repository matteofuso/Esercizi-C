#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    int fd;

    if (mkfifo("myfifo1", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Errore nella creazione della fifo\n");
            return 1;
        }
    }
    fd = open("myfifo1", O_WRONLY); // fd[1]
    printf("Aperta la FIFO\n");

    int x = 90;

    if (write(fd, &x, sizeof(int)) == -1)
    {
        printf("Errore in scrittura nella fifo\n");
        close(fd);
        return -2;
    }
    printf("Ho scritto nella fifo\n");
    close(fd);

    return 0;
}