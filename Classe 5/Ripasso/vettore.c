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
#include <stdbool.h>

/// @brief Fill an array with random integers
/// @param array Array to fill
/// @param len Lenght of the array
/// @param interval1 First interval of the random numbers
/// @param interval2 Last interval of the random numbers
void fillArray(int *array, int len, int interval1, int interval2)
{
    int range = interval1 - interval2 + 1;
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

/// @brief Print an array
/// @param startPosition Start position of the array
/// @param len Lenght of the array (Negative for reverse print)
/// @param end End index
void printArray(int *startPosition, int len)
{
    if (len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            printf("[%d] %d\n", i + 1, startPosition[i]);
        }
        return;
    }
    for (int i = -len - 1; i >= 0; i--)
    {
        printf("[%d] %d\n", i + 1, startPosition[i]);
    }
}

/// @brief Print the sum and the average of an array
/// @param array Source array
/// @param len Lenght of the array
void printSumAverage(int *array, int len)
{
    int sum = 0;
    double average;
    for (int *i = array; i < array + len; i++)
    {
        sum += *i;
    }
    average = (double)sum / len;
    printf("Somma: %d\nMedia: %.2f\n", sum, average);
}

/// @brief Print even or odd numbers
/// @param array Source array
/// @param len Lenght of the array
/// @param isOdd True for odd numbers, false for even numbers
void printEvenOdd(int *array, int len, bool isOdd)
{
    for (int i = 0; i < len; i++)
    {
        if (array[i] % 2 == isOdd)
        {
            printf("[%d] %d\n", i + 1, array[i]);
        }
    }
}

/// @brief Search the index of the first occurance of a number in an array
/// @param array Source array
/// @param len Length of the array
/// @param number Number to search
/// @return Index or -1 if the number is not present
int firstOccurance(int *array, int len, int number)
{
    for (int i = 0; i < len; i++)
    {
        if (array[i] == number)
        {
            return i;
        }
    }
    return -1;
}

/// @brief Search and print the indexes of a number in an array
/// @param array Source array
/// @param len Length of the array
/// @param number Number to search
/// @return Number of times the number is present in the array
int searchNumber(int *array, int len, int number)
{
    int times = 0;
    for (int i = 0; i < len; i++)
    {
        if (array[i] == number)
        {
            printf("[%d] %d\n", i + 1, array[i]);
            times++;
        }
    }
    return times;
}

/// @brief Remove a number from an array
/// @param array Source array
/// @param len Length of the array
/// @param number Number to remove
/// @return Number of times the number is removed
int removeNumber(int *array, int *len, int number)
{
    int removed = 0;
    int left = firstOccurance(array, *len, number);
    if (left == -1)
    {
        return 0;
    }
    for (int i = left; i < *len; i++)
    {
        if (array[i] == number)
        {
            removed++;
            continue;
        }
        array[left++] = array[i];
    }
    *len -= removed;
    return removed;
}

/// @brief Alternate elements of an array
/// @param array Source array
/// @param len Length of the array
void alternateElements(int *array, int len)
{
    int newLen = len - len % 2;
    for (int i = 0; i < newLen; i += 2)
    {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }
}

/// @brief Sort an array using Bubble Sort
/// @param array Source array
/// @param len Length of the array
void sort(int *array, int len)
{
    bool swapped = true;
    for (int i = 0; i < len - 1 && swapped; i++)
    {
        swapped = false;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                swapped = true;
            }
        }
    }
}

/// @brief Show the menu and ask for a suitable choice
/// @return User choice
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

/// @brief Redirect the user choice to the right function
/// @param array Source array
/// @param len Array length
/// @param choice User choice
void functionRedirect(int *array, int *len, int choice)
{
    switch (choice)
    {
    case 1:
        printf("Visualizzo Array:\n");
        printArray(array, *len);
        break;
    case 2:
        printf("Visualizzo Array invertito:\n");
        printArray(array, -*len);
        break;
    case 3:
        printf("Visualizzo somma e media:\n");
        printSumAverage(array, *len);
        break;
    case 4:
        printf("Visualizzo numeri pari:\n");
        printEvenOdd(array, *len, false);
        break;
    case 5:
        printf("Visualizzo numeri dispari:\n");
        printEvenOdd(array, *len, true);
        break;
    case 6:
        printf("Ricerca numero:\n\n");
        printf("Inserisci il numero da cercare: ");
        scanf("%d", &choice);
        if (searchNumber(array, *len, choice) == 0)
        {
            printf("Numero non trovato\n");
        }
        break;
    case 7:
        printf("Elimina numero:\n\n");
        printf("Inserisci il numero da eliminare: ");
        scanf("%d", &choice);
        if (removeNumber(array, len, choice) == 0)
        {
            printf("Numero non trovato\n");
        }
        else
        {
            printf("Numero rimosso.\nNuovo array:\n\n");
            printArray(array, *len);
        }
        break;
    case 8:
        printf("Alternare elementi:\n");
        alternateElements(array, *len);
        printf("Numeri alternati.\nNuovo array:\n\n");
        printArray(array, *len);
        break;
    case 9:
        printf("Ordina Array:\n");
        sort(array, *len);
        printf("Array ordinato.\nNuovo array:\n\n");
        printArray(array, *len);
        break;
    }
}

/// @brief Main entry of the program
/// @param argc Lenght of the arguments
/// @param argv Arguments
/// @return Exit status
int main(int argc, char **argv)
{
    int len, choice, *array;
    if (argc != 4)
    {
        printf("Use: %s <array lenght> <minimum number> <maximum number>\n", argv[0]);
        return -1;
    }
    len = atoi(argv[1]);
    array = (int *)malloc(len * sizeof(int));
    srand(time(NULL));
    fillArray(array, len, atoi(argv[2]), atoi(argv[3]));
    while (1)
    {
        choice = menu();
        if (choice == 10)
        {
            break;
        }
        functionRedirect(array, &len, choice);
    }
    free(array);
    return 0;
}