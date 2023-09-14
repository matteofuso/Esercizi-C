#include <stdio.h>
#include <stdbool.h>

void fill_array(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("Inserisci il %d elemento: ", i + 1);
        scanf("%d", arr + i);
    }
}

int bubble_sort(int *arr, int len)
{
    bool sentinel = true;
    int temp;
    for (int i = len - 1; i > 0 && sentinel; i--)
    {
        sentinel = false;
        for (int j = 0; j < i; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
                sentinel = true;
            }
        }
    }
}

void print_array(int *arr, int len)
{
    printf("\n");
    for (int i = 0; i < len; i++)
    {
        printf("%p - %d\n", arr + i, *(arr + i));
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int len;
    // Chiedo la lunghezza
    do
    {
        printf("Inserisci la lunghezza dell'array: ");
        scanf("%d", &len);
    } while (len < 1);
    int arr[len];
    // Chiedo i dati
    fill_array(arr, len);
    // Ordino l'array
    bubble_sort(arr, len);
    // Stampo l'array ordinato
    print_array(arr, len);
    return 0;
}