/*
    Dato un array di dimensione massima pari a SHRT_MAX,
    inserire in input un numero arbitrario di interi positivi.
    L'inserimento termina quando viene inserito il valore -1.

    Si mostri quindi un menu cosi strutturato:
        premere 1 per mostrare il contenuto dell'array
        premere 2 per inserire un elemento in coda
        premere 3 per modificare un elemento, se presente
        premere 4 per eliminare un elemento, se presente
        premere 5 per ricercare un elemento
        premere 6 per inserire un elemento in una certa posizione
        premere 7 per mostrare il contenuto dell'array all'inverso
        premere 8 per mostrare il valore massimo dell'array
        premere 0 per terminare

    dopo ogni operazione il menu deve essere nuovamente mostrato.

    osservazione:
    SHRT_MAX è dichiarata in limits.h

    Vincolo:
    è obbligatorio strutturare il programma in funzioni
*/

#include <stdio.h>
#include <limits.h>

int menu(int n)
{
    int s, max;
    printf("0. Esci\n");
    printf("1. Inserisci un elemento\n");
    max = 1;
    if (n != 0)
    {
        printf("2. Mostra il contenuto dell'array\n");
        printf("3. Modifica un elemento\n");
        printf("4. Elimina un elemento\n");
        printf("5. Ricerca un elemento\n");
        printf("6. Sostituisci un elemento in una certa posizione\n");
        printf("7. Mostra il contenuto dell'array all'inverso\n");
        printf("8. Mostra il valore massimo dell'array\n\n");
        max = 8;
    }
    do
    {
        printf("Inserisci un numero nell'intervallo: ");
        scanf("%d", &s);
    } while (s < 0 || s > max);
    return s;
}

void mostra(int n, int *nums)
{
    printf("Ecco l'array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d - %d\n", i, nums[i]);
    }
}

void mostraInverso(int n, int *nums)
{
    printf("Ecco l'array:\n");
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d - %d\n", i, nums[i]);
    }
}

void inserisci(int *n, int *nums)
{
    printf("Inserisci gli elementi. Digita -1 per uscire:\n");
    while (*n < sizeof(nums))
    {
        do
        {
            printf("%d - ", *n);
            scanf("%d", nums + *n);
        } while (nums[*n] < -1);
        if (nums[*n] != -1)
        {
            (*n)++;
            continue;
        }
        break;
    }
}

void sostituisci(int p, int *nums)
{
    int n;
    do
    {
        printf("Inserisci il numero positivo con cui vuoi sostituire %d o esci con -1: ", nums[p]);
        scanf("%d", &n);
    } while (n < -1);
    if (n != -1)
    {
        nums[p] == n;
    }
}

int trova(int a, int n, int *nums)
{
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == a)
        {
            return i;
        }
    }
    return -1;
}

int max(int n, int *nums)
{
    int max = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max;
}

void entry(int s, int *n, int *nums)
{
    int tmp;
    printf("\n");
    switch (s)
    {
    case 1:
        inserisci(n, nums);
        break;
    case 2:
        mostra(*n, nums);
        break;
    case 3:
        // todo
        break;
    case 4:
        // todo
        break;
    case 5:
        printf("Inserisci il numero da ricercare: ");
        scanf("%d", &tmp);
        tmp = trova(tmp, *n, nums);
        if (tmp == -1)
        {
            printf("Non ci sono occorenze.\n");
        }
        else
        {
            printf("La prima occerrenza è alla posizione %d.\n", tmp);
        }
        break;
    case 6:
        do
        {
            printf("Inserisci la posizione (Compresa tra 0 e %d): ", *n);
            scanf("%d", &tmp);
        } while (tmp < 0 || tmp > *n);
        sostituisci(tmp, nums);
        break;
    case 7:
        mostraInverso(*n, nums);
        break;
    case 8:
        printf("Il massimo numero presente nell'array è %d\n", max(*n, nums));
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int s, n = 0, nums[SHRT_MAX];
    while (1)
    {
        s = menu(n);
        if (s == 0)
        {
            printf("Programma terminato!\n");
            return 0;
        }
        entry(s, &n, nums);
    }
}