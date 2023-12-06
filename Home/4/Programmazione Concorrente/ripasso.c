#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

typedef struct
{
    char tipo[20];
    char colore[20];
    int peso;
} Frutto;

#define SALVAilMONDO 2

int main(int argc, char *argv[])
{
    int p, status;
    FILE *f;
    Frutto *frutti[SALVAilMONDO];
    // File
    f = fopen("frutti.txt", "w");
    if (f == NULL)
    {
        printf("Errore nell'apertura del file\n");
        exit(1);
    }
    // Assing
    for (int i = 0; i < SALVAilMONDO; i++)
    {
        frutti[i] = malloc(sizeof(Frutto));
        printf("Frutto %d\n", i + 1);
        printf("Inserisci il tipo del frutto: ");
        scanf("%s", frutti[i]->tipo);
        printf("Inserisci il colore del frutto: ");
        scanf("%s", frutti[i]->colore);
        printf("Inserisci il peso del frutto: ");
        scanf("%d", &frutti[i]->peso);
        printf("\n");
    }
    // Uze
    p = fork();
    if (!p)
    {
        for (int i = 0; i < SALVAilMONDO; i++)
        {
            fwrite(frutti[i], sizeof(Frutto), 1, f);
        }
        if (fclose(f) != 0)
        {
            printf("Errore nella chiusura del file\n");
            exit(-1);
        }
        exit(104);
    }
    // Print
    for (int i = 0; i < SALVAilMONDO; i++)
    {
        printf("Il frutto %d è di tipo %s, di colore %s e pesa %d\n", i, frutti[i]->tipo, frutti[i]->colore, frutti[i]->peso);
    }
    wait(&status);
    printf("Mio figlio ha finito di scrivere sul file con il codice %d\n", WEXITSTATUS(status));
    // Free
    for (int i = 0; i < SALVAilMONDO; i++)
    {
        free(frutti[i]);
    }
    return 0;
}