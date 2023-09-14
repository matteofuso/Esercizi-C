#include <stdio.h>
#include <string.h>
#include <ctype.h>

void copy(char *origin, char *destination)
{
    for (int i = 0; i < strlen(origin); i++)
    {
        if (isdigit(*(origin + i)))
        {
            *(destination + strlen(destination)) = *(origin + i);
        }
    }
}

int main(int argc, char *argv[])
{
    char str1[100], str2[100] = {0};
    printf("Inserisci la prima stringa: ");
    scanf("%s", str1);
    copy(str1, str2);
    if (strlen(str2))
    {

        printf("La seconda stringa è ora %s\n", str2);
    }
    else
    {
        printf("Non ci sono numeri\n");
    }
    return 0;
}