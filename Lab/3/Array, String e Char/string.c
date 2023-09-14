#include <stdio.h>

int main(int argc, char *argv[])
{
    char str[20];
    int i = 0;
    printf("Inserisci una stringa (Fino 20 caratteri): ");
    scanf("%s", str);
    printf("Hai inserito la seguente stringa: %s\n", str);
    while (str[i] != '\0') // L'array di caratteri finisce con '\0' - Delimitatore di fine stringa
    {
        printf("Alla posizione %d, troviamo %c\n", i, str[i]);
        i++;
    }
    printf("La stringa è lunga %d\n", i);
    return 0;
}