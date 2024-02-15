#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 20 // Definisco il valore di MAX_STR
#define qtaNomi 4  // Definisco il valore di qtaNomi

int i; // Definisco una variabile intera globale

int main() // Punto di ingresso del programma
{
	FILE *fileDestinazione;					   // Creo una variabile puntatore a file
	char vett[MAX_STR];						   // Creo una stringa con lunghezza massima di MAX_STR caratteri
	fileDestinazione = fopen("nomi.txt", "w"); // Apro il file "nomi.txt" in modalità di scrittura
	if (fileDestinazione == NULL)			   // Controllo se il file non stato aperto
	{
		printf("Impossibile aprire il file"); // Stampo l'errore
		exit(1);							  // Esco dal programma con il codice 1
	}
	else // Se il file è stato aperto
	{
		for (i = 0; i < qtaNomi; i++) // Ripeto qtaNomi volte
		{
			printf("Inserisci il %d^ nome   >>   ", i + 1); // Chiedo il nome
			scanf("%s", vett);								// Leggo il nome
			fputs(vett, fileDestinazione);					// Stampo il nome
			fputc('\n', fileDestinazione);					// Stampo il carattere \n, cioè vado a capo
		}
	}
	fclose(fileDestinazione);				   // Chiudo il file
	fileDestinazione = fopen("nomi.txt", "r"); // Riapro il file in modalità sola lettura

	while (fgets(vett, MAX_STR, fileDestinazione)) // Leggo una riga o MAX_STR caratteri dal file e li salvo sul vettore vett.
												   // Continuo finchè fgets() non ritorna NULL (NULL è interpretato come False),
												   // quindi quando il file è terimato
		printf("%s", vett);						   // Stampo quello letto dal file

	if (fclose(fileDestinazione) == 0)						   // Controllo se l'operazione di chiusura è andata a buon fine
		printf("\n\nChiusura del file avvenuta con successo"); // Dico che il file è stato chiuso con successo
	else													   // Se l'operazione di chiusura non è andata a buon fine
		printf("\n\nChiusura del file fallita");			   // Dico che non è stato possibile chiudere il file
	return 0;												   // Esco dal programma con il codice 0
}

/*
	Il progamma legge qtaNomi nomi e li scrive sul file "nomi.txt". Successivamente,
	tramite fgets stampo il contenuto del file
*/