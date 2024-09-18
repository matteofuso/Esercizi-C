/*
    Scrivere un programma in C che effettui, attraverso un menù, le seguenti operazione sugli array:
    1) Visualizzi a video gli elementi dell’array inseriti o generati casualmente;
    2) Visualizzi a video l’array invertito cioè sostituendo il primo elemento
    con l'ultimo , il secondo con il penultimo e cosi via;
    3) Visualizzi a video la somma e media degli elementi del vettore;
    4) Visualizzi a video tutti i numeri pari;
    5) Visualizzi a video tutti i numeri dispari;
    6) Ricerchi un numero (letto in input) nell’array;
    7) Elimini un elemento (letto in input) dell’array (se esistente);
    8) Alterni (o scambi ) a due a due le posizioni del vettore: esempio
    vettore: 1,2,3,4 vettore alternato: 2,1,4,3 (attenzione se lungo dispari);
    9) Ordini il vettore (ordinamento a scelta).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArray(int *array, int len, int interval1, int interval2)
{
    int range = interval1 - interval2;
    int min = interval1;
    if (interval1 > interval2)
    {
        range *= -1;
        min = interval2;
    }
    for (int *i = array; i < array + len; i++)
    {
        *i = rand() % range + min;
    }
}

void printArray(int *array, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("[%d] %d\n", i + 1, array[i]);
    }
}

int menu()
{
    int choice;
    printf("\n\
    1 - Visualizza array\n\
    2 - Visualizza array invertito\n\
    3 - Visualizza somma e media\n\
    4 - Visualizza numeri pari\n\
    5 - Visualizza numeri dispari\n\
    6 - Ricerca numero\n\
    7 - Elimina numero\n\
    8 - Alternare elementi\n\
    9 - Ordinare array\n\
    10 - Esci\n\n");
    do
    {
        printf("Inserisci la scelta: ");
        scanf("%d", &choice);
    } while (choice < 1 || choice > 10);
    printf("\n");
    return choice;
}

void functionRedirect(int *array, int len, int choice)
{
    switch (choice)
    {
    case 1:
        printf("Visualizzo Array:\n");
        printArray(array, len);
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    case 9:
        break;
    }

}

int main(int argc, char **argv)
{
    int len, choice;
    // Controllo argomenti
    if (argc != 4)
    {
        printf("Use: %s <array lenght> <minimum number> <maximum number>\n", argv[0]);
        return -1;
    }
    // Inizializzo l'array
    len = atoi(argv[1]);
    int array[len];
    srand(time(NULL));
    fillArray(array, len, atoi(argv[2]), atoi(argv[3]));
    // Visualizzazione menu e reindirizzamento funzioni
    while (1)
    {
        choice = menu();
        if (choice == 10)
        {
            break;
        }
        functionRedirect(array, len, choice);
    }
}