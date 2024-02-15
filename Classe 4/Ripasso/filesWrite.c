#include <stdio.h>
#include <stdlib.h>

#define NEWLINE fputc('\n', f);

int main(int argc, char *argv[])
{
    FILE *f;
    char nome[20];
    f = fopen("file.txt", "a"); // cerca file in pwd
    if (f == NULL)
    {
        printf("File non apribile\n");
        exit(1);
    }
    printf("File aperto!\n");
    for (int i = 0; i < 4; i++)
    {
        printf("Inserisci il nome %d: ", i+1);
        scanf("%s", nome);
        fputs(nome, f);
        NEWLINE
    }
    fclose(f);
    return 0;
}