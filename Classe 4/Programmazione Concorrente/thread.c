#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Thread POSIX
void *StampaSaluto(void *args)
{
    printf("%s\n", (char*)args);
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t threadgiorno, threadsera, threadnotte;
    char* msg1 = "Buongiorno";
    char* msg2 = "Buonasera";
    char* msg3 = "Buonanotte";

    pthread_create(&threadgiorno, NULL, &StampaSaluto, msg1);
    pthread_create(&threadsera, NULL, &StampaSaluto, msg2);
    pthread_create(&threadnotte, NULL, &StampaSaluto, msg3);

    pthread_join(threadgiorno, NULL);
    pthread_join(threadsera, NULL);
    pthread_join(threadnotte, NULL);
    return 0;
}