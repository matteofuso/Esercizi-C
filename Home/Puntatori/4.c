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

int trova(int n, int l, int *nums)
{
    for (int i = 0; i < l; i++)
    {
        if (nums[i] == n)
        {
            return i;
        }
    }
    return -1;
}

int popola(int *nums)
{
    int l = 0;
    printf("Inserisci gli elementi. Digita -1 per uscire:\n");
    while (1)
    {
        do
        {
            printf("%d - ", l);
            scanf("%d", nums + l);
        } while (nums[l] < -1);
        if (nums[l] != -1)
        {
            l++;
            continue;
        }
        return l;
    }
}

void aggiungi(int n, int *l, int *nums)
{
    nums[*l] = n;
    (*l)++;
}

void mostra(int l, int *nums)
{
    for (int i = 0; i < l; i++)
    {
        printf("%d - %d\n", i, nums[i]);
    }
}

int modifica(int start, int end, int l, int *nums)
{
    int i = trova(start, l, nums);
    if (i == -1)
    {
        return 1;
    }
    nums[i] = end;
    return 0;
}

int rimuovi(int n, int *l, int *nums)
{
    int i = trova(n, *l, nums);
    if (i == -1)
    {
        return 0;
    }
    while (i < *l)
    {
        nums[i] = nums[i + 1];
        i++;
    }
    (*l)--;
    return 1;
}

void sostituisci(int i, int n, int *nums)
{
    nums[i] = n;
}

void mostraInverso(int l, int *nums)
{
    for (int i = l - 1; i >= 0; i--)
    {
        printf("%d - %d\n", i, nums[i]);
    }
}

int max(int l, int *nums)
{
    int max = nums[0];
    for (int i = 1; i < l; i++)
    {
        if (nums[i] > max)
        {
            max = nums[i];
        }
    }
    return max;
}

int getPositive(int min, char *msg)
{
    int n;
    do
    {
        printf("%s: ", msg);
        scanf("%d", &n);
    } while (n < min);
    return n;
}

int menu()
{
    int s;
    printf("\n0. Esci\n");
    printf("1. Mostra il contenuto dell'array\n");
    printf("2. Inserisci un elemento in coda\n");
    printf("3. Modifica un elemento (Dopo averlo cercato)\n");
    printf("4. Elimina un elemento (Dopo averlo cercato)\n");
    printf("5. Ricerca un elemento\n");
    printf("6. Sostituisci un elemento in una certa posizione\n");
    printf("7. Mostra il contenuto dell'array all'inverso\n");
    printf("8. Mostra il valore massimo dell'array\n\n");
    do
    {
        printf("Inserisci un numero nell'intervallo: ");
        scanf("%d", &s);
    } while (s < 0 || s > 8);
    return s;
}

void entry(int s, int *l, int *nums)
{
    int n;
    printf("\n");
    switch (s)
    {
    case 1:
        mostra(*l, nums);
        break;
    case 2:
        n = getPositive(0, "Inserisci un numero positivo");
        aggiungi(n, l, nums);
        printf("Aggiunto con successo!\n");
        break;
    case 3:
        int start, end;
        printf("Inserisci il numero da modificare: ");
        scanf("%d", &start);
        printf("Inserisci il numero in cui modificare: ");
        scanf("%d", &end);
        if (modifica(start, end, *l, nums))
        {
            printf("Numero non trovato\n");
        }
        else
        {
            printf("Numero modificato!\n");
        }
        break;
    case 4:
        printf("Inserisci il numero da eliminare: ");
        scanf("%d", &n);
        if (rimuovi(n, l, nums))
        {
            printf("Numero rimosso con successo\n");
        }
        else
        {
            printf("Numero non trovato\n");
        }
        break;
    case 5:
        printf("Inserisci il numero da ricercare: ");
        scanf("%d", &n);
        n = trova(n, *l, nums);
        if (n == -1)
        {
            printf("Non ci sono occorenze.\n");
        }
        else
        {
            printf("La prima occerrenza è alla posizione %d.\n", n);
        }
        break;
    case 6:
        int i;
        do
        {
            printf("Inserisci la posizione (Compresa tra 0 e %d): ", *l);
            scanf("%d", &i);
        } while (i < 0 || i > *l);
        n = getPositive(-1, "Inserisci un numero positivo con cuoi vuoi sostituire o esci con -1");
        sostituisci(i, n, nums);
        break;
    case 7:
        mostraInverso(*l, nums);
        break;
    case 8:
        printf("Il massimo numero presente nell'array è %d\n", max(*l, nums));
    }
}

int main(int argc, char *argv[])
{
    int s, nums[SHRT_MAX], l = popola(nums);
    while (1)
    {
        s = menu();
        if (s == 0)
        {
            printf("Programma terminato!\n");
            return 0;
        }
        entry(s, &l, nums);
    }
}