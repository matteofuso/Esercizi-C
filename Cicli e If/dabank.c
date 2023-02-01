#include <stdio.h>

/*
    Una banca vuole conoscere alcune informazioni sulle proprie azioni detenute in portafoglio.
    Scrivere il programma in c che dopo aver inserito da tastiera la denominazione dell’azione e il suo prezzo
    determini e visualizzi in Output:
        1) La somma dei prezzi delle azioni;
        2) La media dei prezzi delle azioni;
        3) L’azione con il prezzo massimo;
        4) L’azione con il prezzo minimo
        5) La media dei prezzi delle azioni con un importo compreso tra 2,50 e 3,50 euro, estremi inclusi.
    L’inserimento termina con un numero negativo.
*/

int main(int argc, char *argv[])
{
    float max = 0, min = 0, somma = 0, azione, media;
    float sommaCompresi = 0, mediaCompresi;
    int i = 0, iCompresi = 0;
    printf("Inserisci il prezzo dell'azione: ");
    scanf("%f", &azione);
    if (azione <= 0)
    {
        printf("Non hai aggiunto nessuna azione!\n");
    }
    else
    {
        min = azione;
        while (azione >= 0)
        {
            i++;
            if (azione < min)
            {
                min = azione;
            }
            if (azione > max)
            {
                max = azione;
            }
            if (azione <= 3.50 && azione >= 2.50)
            {
                sommaCompresi += azione;
                iCompresi++;
            }
            printf("Inserisci il prezzo dell'azione: ");
            scanf("%f", &azione);
        }
        media = somma / i;
        printf("Della serie di azioni:\n-La loro somma è %.2f\n-La loro media è %.2f\n", somma, media);
        printf("-L'azione con il prezzo massimo vale %.2f\n-L'azione con il prezzo minimo vale %.2f\n", max, min);
        if (iCompresi == 0)
        {
            mediaCompresi = sommaCompresi / iCompresi;
            printf("La media delle azioni con un importo nell'intervallo 2,50 e 3,50 vale %.2f", mediaCompresi);
        }
    }
    printf("Programma terminato.\n");
    return 0;
}