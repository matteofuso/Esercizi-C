/*
    Creare un programma che :
    1- chiede i dati di uno studente (nome,cognomome, classe,media);
    2- crea un thread per stampare a video i dati inseriti;
    3- crea un secondo thread per stampare su un file di testo i dati inseriti.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    char nome[100];
    char cognome[100];
    char classe[10];
    float media;
} Studente;

typedef struct
{
    Studente *studente;
    FILE *stream;
} Parametri;

void *StampaStudente(void *arg)
{
    Parametri *p = (Parametri *)arg;
    Studente *studente = p->studente;
    FILE *stream = p->stream;
    fprintf(stream, "Il nome dello studente è %s\n", studente->nome);
    fprintf(stream, "Il cognome dello studente è %s\n", studente->cognome);
    fprintf(stream, "La classe dello studente è %s\n", studente->classe);
    fprintf(stream, "La media dello studente è %.2f\n", studente->media);
    return NULL;
}

int main(int argc, char *argv[])
{
    Studente studente;
    pthread_t threadVideo, threadFile;
    FILE *file;
    // Controllo il numero di parametri
    if (argc != 2)
    {
        printf("Uso corretto: %s [<file>]\n", argv[0]);
        return -1;
    }
    // Provo ad aprire il file
    file = fopen(argv[1], "w");
    if (file == NULL)
    {
        printf("Impossibile aprire il file\n");
        return -2;
    }
    printf("Inserisci il nome dello studente: ");
    scanf("%s", studente.nome);
    printf("Inserisci il cognome dello studente: ");
    scanf("%s", studente.cognome);
    printf("Inserisci la classe dello studente: ");
    scanf("%s", studente.classe);
    printf("Inserisci la media dello studente: ");
    scanf("%f", &studente.media);
    printf("\n");
    // Preparo i parametri
    Parametri parametriVideo, parametriFile;
    parametriVideo.studente = &studente;
    parametriVideo.stream = stdout;
    parametriFile.studente = &studente;
    parametriFile.stream = file;
    // Creo i thread
    pthread_create(&threadVideo, NULL, &StampaStudente, &parametriVideo);
    pthread_create(&threadFile, NULL, &StampaStudente, &parametriFile);
    // Chiudo
    pthread_join(threadVideo, NULL);
    pthread_join(threadFile, NULL);
    fclose(file);
    return 0;
}