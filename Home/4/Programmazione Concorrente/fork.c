#include <stdio.h>
#include <unistd.h>

/*
    Utilizzando la funzione fork() in un processo padre, generare un processo figlio.
    1-Il processo padre deve stampare a video il suo PID e quello del padre; deve inoltre scrivere la seguente frase: " sono il processo padre ".
    2-Il processo figlio deve stampare a video il suo PID e quello del padre; deve inoltre scrivere la seguente frase: " sono il processo figlio". 
    3-Provare a dichiarare la variabile intera che memorizza il ritorno della fork() sia fuori, sia dentro il main. Cosa cambia? motivare la risposta
    4- Prima di chiamare la funzione fork() scrivere la seguente istruzione: printf("ciao\n). Che cosa si nota? Motivare il risultato.
    5- Che legame esiste tra i PID dei punti 1 e 2. Chi è il padre del padre? Spiegare
*/

/*
    5. PPID in child shows the PID of his parent, the programm (Same as the contente of p). The PPID in the parent shows
    the PID of whom executed the programm, in this case the terminal.
*/

// int p;
// 3. If i declare the variable p outside the main, the scope changes.
// That mean that I can use the variables inside each function

/// @brief Main entry of the programm
/// @param argc Lenght of args
/// @param argv Array of args
/// @return Status
int main(int argc, char *argv[])
{
    printf("Hello World!\n"); // 4. Istructions before fork are executed by the parent process
    int p = fork();   // 3. If i declare the p variable inside the main, functions
                      // 4. can't use the variable without passing it
    printf("Second Hello World\n"); // Istructions after fork are executed by both the parent and the child process
    if (p < 0)
    {
        // Fail in the fork process
        printf("Couldn't create process!");
        return -1;
    }
    if (p == 0)
    {
        // 2. What the child will execute
        printf("I'm the child process (PID: %d) (PPID: %d)\n", getpid(), getppid());
        return 0; // Kill the child process
    }
    // 1. What the parent will execute
    printf("I'm the parent process (PID: %d) (PPID: %d)\n", getpid(), getppid());
    return 0;
}