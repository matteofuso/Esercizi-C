#include <stdio.h>

/*
    Scrivere un programma in c che permetta di inserire dei numeri interi in input da tastiera.
    L’inserimento termina quando la somma dei numeri inseriti supera il valore pari a 20.
    Visualizzare a video:
        1) La somma e la media effettiva dei numeri inseriti;
        2) quanti numeri maggiori di 7 sono stati inseriti;
        3) la media dei numeri pari e di quelli dispari (tra quelli inseriti);
*/

// Matteo Fuso - Fila A - 18/01/2023

int main(int argc, char *argv[])
{
    // Dichiarazione variabili e costanti e inizializzazione
    // Inizializzo i contatori a 0 così in un istruzione posso usarli sia come variabile che operatore, come in superoLimite++
    const int fine = 20, valoreLimite = 7;
    int input, somma = 0, counter = 0, superoLimite = 0, numeriPari = 0, numeriDispari = 0, sommaPari = 0, sommaDispari = 0;
    float media, mediaPari, mediaDispari;
    // Uso un do-while perchè so di dover entrare almeno una volta dentro il ciclo
    do
    {
        // Chiedo all'utente di inserire il numero e gli mostro quanti ne ha già inseriti
        counter++;
        printf("Inserisci il %i° numero intero: ", counter);
        scanf("%i", &input);
        // Controllo quanti numeri sono maggiori di 7 - Seconda domanda
        if (input > valoreLimite)
        {
            superoLimite++;
        }
        // Controllo quanti numeri sono pari e dispari - Terza domanda
        if (input % 2 == 0)
        {
            numeriPari++;
            sommaPari += input;
        }
        else
        {
            numeriDispari++;
            sommaDispari += input;
        }
        // Aggiungo il numero inserito alla variabile somma per calcolare la somma totale e quindi la media
        somma += input;
    } while (somma <= fine);
    // Calcolo la media, il contatore non potrà essere mai 0, infatti bisogna inserire per forza almeno un valore
    media = (float)somma / (float)counter;
    // Visualizzo le richieste delle prime due domande
    printf("\nLa somma dei numeri inseriti è %i e la media %.2f\n", somma, media);
    printf("I numeri maggiori di %i sono %i\n", valoreLimite, superoLimite);
    // Per la terza domanda, siccome devo calcolare una media e che, al massimo
    // uno tra numeripari e numeridispari può essere 0, suddivido la frase.
    // La funzione printf() non va a capo da sola alla fine della frase e quindi la uso per
    // dividere la frase
    if (numeriPari == 0)
    {
        // Non ci sono numeri pari e quindi non calcolo la media
        printf("Non ci sono numeri pari");
    }
    else
    {
        mediaPari = (float)sommaPari / (float)numeriPari;
        printf("La media dei numeri pari è %.2f", mediaPari);
    }
    if (numeriDispari == 0)
    {
        // Siccome al massimo uno tra numeripari e numeridispari può essere 0, uso "ma" per unire i due pezzi di frasi
        printf(" ma non ci sono numeri dispari\n");
    }
    else
    {
        // Siccome non posso sapere senza un altro controllo se c'è almeno un numero pari, uso "e" per unire le frasi
        mediaDispari = (float)sommaDispari / (float)numeriDispari;
        printf(" e la media dei numeri dispari è %.2f\n", mediaDispari);
    }
}