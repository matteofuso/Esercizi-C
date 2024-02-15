#include <stdio.h>

typedef union
{
    int intero;
    unsigned char decimalePuntato[4];
} IP;

int main(int argc, char *argv[])
{
    IP ip;
    ip.intero = 25565;
    printf("IP: %d.%d.%d.%d\n", 3[ip.decimalePuntato], 2[ip.decimalePuntato], ip.decimalePuntato[1], ip.decimalePuntato[0]);
    return 0;
}