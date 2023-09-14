/*
    Progettare un algoritmo che risolva il seguente problema. Si richieda
    all’utente di inserire una serie di terne di dati numerici (A, B, C).
    Il programma deve terminare quando uno dei valori inseriti è minore di
    zero. Si scartino le terne nelle quali i valori non sono in ordine
    strettamente crescente, ovvero quelle terne per cui non valga A < B < C.
    Su tutte le terne non scartate si calcoli il massimo e il minimo dei
    valori inseriti. Si stampino a video tali valori massimi e minimi prima
    di terminare il programma.
*/

#include <stdio.h>


int main(int argc, char *argv[])
{
    float a, b, c, max = 0, min = 0;
    int terne = 0;
    while (1)
    {
        printf("Inserisci il primo numero: ");
        scanf("%f", &a);
        printf("Inserisci il secondo numero: ");
        scanf("%f", &b);
        printf("Inserisci il terzo numero: ");
        scanf("%f", &c);
        if (a == 0 || b == 0 || c == 0)
        {
            break;
        }
        if (a < b && b < c)
        {
            terne++;
            if (terne == 1)
            {
                min = a;
            }
            else
            {
                if (a < min)
                {
                    min = a;
                }
                if (c > max)
                {
                    max = c;
                }
            }
            printf("Della terna (%.2f-%.2f-%.2f) il numero massimo è %.2f ed il minimo è %.2f\n", a, b, c, c, a);
        }
        else
        {
            printf("Terna scartata\n");
        }
    }
    printf("\nDalle %d terne che hai inseito, il massimo trovato è %.2f ed il minimo è %.2f\n", terne, max, min);
    return 0;
}