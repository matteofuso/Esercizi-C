#include <stdio.h>
#include <stdlib.h>

int main() // Punto di ingresso del programma
{
	FILE *fileOrigine;					  // Creo una variabile puntatore a file
	char c;								  // Creo una variabile di tipo carattere
	fileOrigine = fopen("nomi.txt", "r"); // Apro il file di nome "nomi.txt" in modalità sola lettura
	if (fileOrigine == NULL)			  // Se il puntatore non punta a niente, allora il file non è stato aperto
	{
		printf("Impossibile aprire il file"); // Dico che è impossibile aprire il file
		exit(1);							  // Esco dal programma con il codice 1
	}
	else // Se il file è stato aperto
	{
		c = fgetc(fileOrigine); // Prendo il primo carattere del file
		while (c != EOF)		// Finchè non arrivo alla fine del file
		{
			putchar(c);				// Stampo il carattere appena ottenuto
			c = fgetc(fileOrigine); // Prendo il carattere successivo
		}
		if (fclose(fileOrigine) == 0)							   // Se l'operazione di chiusura è andata a buon fine
			printf("\n\nChiusura del file avvenuta con successo"); // Dico che il file è stato chiuso con successo
		else													   // Se l'operazione di chiusura non è andata a buon fine
			printf("\n\nChiusura del file fallita");			   // Dico che non è stato possibile chiudere il file
	}
	return 0; // Esco dal programma con il codice 0
}

/*
	Il programma stampa il contenuto del file nomi.txt.
	Per fare questo apre il file in modalità sola lettura, e controlla se il file è stato aperto.
	Infine chiude il file e controlla se è stato chiuso
*/