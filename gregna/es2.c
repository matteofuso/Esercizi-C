/*
    Progettare un algoritmo che effettui le seguenti operazioni:
    • continui a leggere da tastiera due valori numerici, fermandosi quando uno dei due numeri è
    0 (zero)
    • per ogni coppia di numeri letti:
    ◦ calcoli il prodotto dei due numeri e ne stampi il valore
    ◦ sommi il prodotto calcolato ad una variabile che memorizzi la somma di tutti i prodotti
    • all’uscita del ciclo, stampi il valore della somma
*/

#include <stdio.h>

int main(int argc, char *argv[])
{
    float primo, secondo, prodotto, sommaTotale = 0;
    do
    {
        printf("Inserisci il primo numero: ");
        scanf("%f", &primo);
        printf("Inserisci il secondo numero: ");
        scanf("%f", &secondo);
        prodotto = primo * secondo;
        sommaTotale += prodotto;
        printf("Coppia inserita correttamente. Continua\n\n");
    } while (primo != 0 && secondo != 0);
    printf("Hai inserito 0\n");
    printf("Hello boy. La somma del prodotto delle coppie inserite in precedenza è di %.2f\n", sommaTotale);
}