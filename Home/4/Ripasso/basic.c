#include <stdio.h>
#include <stdlib.h>

int main() // Punto di ingresso del programma
{
	FILE *fileOrigine;						  // Creo una variabile puntatore a file
	fileOrigine = fopen("nomeFile.txt", "r"); // Apro il file di nome "nomeFile.txt" in modalità sola lettura
	if (fileOrigine == NULL)				  // Se il puntatore non punta a niente, allora il file non è stato aperto
	{
		printf("Impossibile aprire il file"); // Dico che è impossibile aprire il file
		exit(1);							  // Esco dal programma con il codice 1
	}
	else // Se il file è stato aperto
	{
		printf("File aperto"); // Dico che il file è stato aperto
	}
	if (fclose(fileOrigine) == 0)							 // Se l'operazione di chiusura è andata a buon fine
		printf("\nChiusura del file avvenuta con successo"); // Dico che il file è stato chiuso con successo
	else													 // Se l'operazione di chiusura non è andata a buon fine
		printf("\nChiusura del file fallita");				 // Dico che non è stato possibile chiudere il file
	return 0;												 // Esco dal programma con il codice 0
}

/*
	Il programma apre il file "nomeFile.txt" in modalità sola lettura e stampa se è possibile aprirlo.
	Successivamente chiude il file e stampa se è stato possibile chiudere il file.
*/