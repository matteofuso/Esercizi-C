#include <stdio.h>
#include <stdlib.h>

#define BUFFER_DIM 16

int main(int argc, char *argv[])
{
    FILE *origine, *destinazione;
    unsigned char buffer[BUFFER_DIM];
    int n;
    if (argc != 3)
    {
        printf("Inserire il giusto numero di parametri di ingresso.\n");
        exit(1);
    }
    origine = fopen(argv[1], "r");
    if (origine == NULL)
    {
        printf("Impossibile aprire file di origine\n");
        exit(1);
    }
    destinazione = fopen(argv[2], "w");
    if (destinazione == NULL)
    {
        printf("Impossibile aprire file di destinazione\n");
        exit(1);
    }
    while (!feof(origine))
    {
        n = fread(buffer, 1, BUFFER_DIM, origine);
        if (n > 0)
        {
            fwrite(buffer, 1, n, destinazione);
        }
    }
    fclose(origine);
    fclose(destinazione);
    return 0;
}