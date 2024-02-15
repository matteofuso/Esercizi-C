#include <stdio.h>

int main(int argc, char *argv[])
{

    int numeri[5], i;
    *numeri = 0;
    *(numeri + 1) = 10;
    *(numeri + 2) = 20;
    *(numeri + 3) = 30;
    *(numeri + 4) = 40;

    printf("Indirizzo dell'array numeri: %p\n", numeri);
    printf("Indirizzo dell'array numeri: %p\n", numeri);
    printf("Indirizzo di numeri[0]: %p\n", numeri);

    for (i = 0; i < 5; i++)
    {
        printf("%p\n", numeri + i);
    }

    for (i = 0; i < 5; i++)
    {
        printf("numeri[%d]: %d\n", i, *(numeri + i));
    }
}