#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *f;
    char c;
    f = fopen("file.txt", "r"); // cerca file in pwd
    if (f == NULL)
    {
        printf("File non apribile\n");
        exit(1);
    }
    printf("File aperto!\n");
    do
    {
        c = fgetc(f);
        putchar(c);
    } while (c != EOF);
    fclose(f);
    return 0;
}