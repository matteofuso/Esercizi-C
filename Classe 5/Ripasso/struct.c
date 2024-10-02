/*
    Scrivere un programma in C che dopo aver dichiarato una struttura denominata Auto
    con i seguenti campi: Modello Auto, marca, cilindrata, prezzo, anno_immatricolazione,
    determinare:
    1) Il prezzo + alto e quello + basso visualizzando anche il modello dell'auto;
    2) Ordinare la lista delle auto in base all'anno d'immatricolazione;
    3) Visualizzare il nome delle auto a partire da un prezzo scelto dall'utente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct
{
    char Modello[50];
    char Marca[50];
    int Cilindrata;
    float Prezzo;
    int AnnoImmatricolazione;
} Automobile;

typedef enum
{
    Cilindrata,
    Prezzo,
} Campo;

void printAuto(Automobile *automobili, int len)
{
    printf("%-15s %-15s %-15s %-15s %-15s\n", "Modello", "Marca", "Cilindrata", "Prezzo", "Anno Immatricolazione");
    for (int i = 0; i < len; i++)
    {
        printf("%-15s %-15s %-15d €%-14.2f %-15d\n", automobili[i].Modello, automobili[i].Marca, automobili[i].Cilindrata, automobili[i].Prezzo, automobili[i].AnnoImmatricolazione);
    }
}

int findFirstMatchingIndex(Automobile *automobili, int len, float price)
{
    for (int i = 0; i < len; i++)
    {
        if (automobili[i].Prezzo >= price)
        {
            return i;
        }
    }
    return -1;
}

void sort(Automobile *automobili, int len, Campo campo)
{
    bool swapped = true;
    for (int i = 0; i < len - 1 && swapped; i++)
    {
        swapped = false;
        for (int j = 0; j < len - i - 1; j++)
        {
            if (campo == Cilindrata)
            {
                if (automobili[j].Cilindrata > automobili[j + 1].Cilindrata)
                {
                    Automobile temp = automobili[j];
                    automobili[j] = automobili[j + 1];
                    automobili[j + 1] = temp;
                    swapped = true;
                }
            }
            else if (automobili[j].Prezzo > automobili[j + 1].Prezzo)
            {
                Automobile temp = automobili[j];
                automobili[j] = automobili[j + 1];
                automobili[j + 1] = temp;
                swapped = true;
            }
        }
    }
}

void minMaxPrice(Automobile *automobili, int len, int *min, int *max)
{
    *min = 0;
    *max = 0;
    for (int i = 1; i < len; i++)
    {
        if (automobili[i].Prezzo < automobili[*min].Prezzo)
        {
            *min = i;
        }
        if (automobili[i].Prezzo > automobili[*max].Prezzo)
        {
            *max = i;
        }
    }
}

int main(int argc, char **argv)
{
    int min, max;
    int len;
    float price;
    Automobile automobili[] = {
        {"3 Series", "BMW", 2000, 30000, 2015},
        {"Model S", "Tesla", 0, 70000, 2019},
        {"Corolla", "Toyota", 1600, 18000, 2013},
        {"Civic", "Honda", 1800, 20000, 2012},
        {"Fiesta", "Ford", 1200, 15000, 2010},
        {"A3", "Audi", 2000, 25000, 2014},
        {"Clio", "Renault", 1400, 17000, 2011},
        {"Panda", "Fiat", 1200, 13000, 2009},
        {"Yaris", "Toyota", 1600, 19000, 2013},
        {"Golf", "Volkswagen", 1600, 20000, 2012},
    };
    len = sizeof(automobili) / sizeof(Automobile);
    printf("Automobili disponibili:\n");
    printAuto(automobili, len);
    minMaxPrice(automobili, len, &min, &max);
    // Visualizza prezzo minore e maggiore
    printf("\nAuto con prezzo minore:\n");
    printAuto(automobili + min, 1);
    printf("\nAuto con prezzo maggiore:\n");
    printAuto(automobili + max, 1);
    // Ordina per anno di immatricolazione
    sort(automobili, len, Cilindrata);
    printf("\nAutomobili ordinate per anno di immatricolazione:\n");
    printAuto(automobili, len);
    // Visualizza auto con prezzo maggiore di un valore scelto
    sort(automobili, len, Prezzo);
    printf("\nInserire un prezzo per visualizzare le auto con prezzo maggiore o uguale: ");
    scanf("%f", &price);
    min = findFirstMatchingIndex(automobili, len, price);
    if (min != -1)
    {
        printf("\nAutomobili con prezzo maggiore o uguale a €%.2f:\n", price);
        printAuto(automobili + min, len - min);
    }
    else
    {
        printf("\nNessuna auto trovata con prezzo maggiore o uguale a €%.2f\n", price);
    }
    return 0;
}