/*
    Su una somma di denaro (relativa all'acquito di un prodotto) si vuole applicare uno sconto
    in base all'importo inserito seguendo il seguente schema:
        da 0 a 500€ sconto del 10%;
        da 501 a 1000 sconto del 20%;
        oltre i 1001 sconto 30%;
    Il programma dopo aver calcolato e visualizzato a video lo sconto ed il prezzo netto deve permettere di
    reinserire ulteriori somme di denaro.
*/

#include <stdio.h>

void main()
{
    int continua, sconto;
    float denaro;
    do
    {
        do
        {
            printf("Inserisci la somma di denaro: ");
            scanf("%f", &denaro);
        } while (denaro < 0);
        if (denaro <= 500)
        {
            sconto = 10;
        }
        else
        {
            if (denaro > 1001)
            {
                sconto = 30;
            }
            else
            {
                sconto = 20;
            }
        }
        printf("Con il tuo acquisto di %.2f€ hai diritto di uno sconto del %i percento\n", denaro, sconto);
        printf("Vuoi reinserire un ulteriore somma di denaro?\n(0) No\n(1) Si\n");
        scanf("%i", &continua);
    } while (continua);
}