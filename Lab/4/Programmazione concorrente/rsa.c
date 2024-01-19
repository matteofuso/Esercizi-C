#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#define true 1
#define false 0

int IsPrime(unsigned long n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

unsigned long RandPrime(char bits)
{
    unsigned long n;
    unsigned int min = 1 << (bits - 1); // 2 ^ (bits - 1)
    unsigned int max = (1 << bits) - 1; // (2 ^ bits) - 1
    do
    {
        n = (rand() % (max - min + 1)) + min;
    } while (!IsPrime(n));
    return n;
}

long inverse(long a, long n)
{
    long t = 0, newt = 1, r = n, newr = a, quotient, temp;
    while (newr != 0)
    {
        quotient = r / newr;
        temp = t;
        t = newt;
        newt = temp - quotient * newt;
        temp = r;
        r = newr;
        newr = temp - quotient * newr;
    }
    if (r > 1)
    {
        return -1; // Inverso modulare non esiste
    }
    if (t < 0)
    {
        t += n;
    }
    return t;
}

__int128_t power(__int128_t x, __int128_t y, __int128_t p)
{
    __int128_t res = 1; // Initialize result

    x = x % p; // Update x if it is more than or equal to p

    if (x == 0)
        return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

int main(int argc, char **argv)
{
    srand(getpid());
    long d;
    unsigned long p, q, e;
    unsigned long n, phi;
    do
    {
        p = RandPrime(20);
        q = RandPrime(20);
    } while (p == q);
    n = p * q;
    e = 65537;
    phi = (p - 1) * (q - 1);

    d = inverse(e, phi);

    printf("Primes (p,q): (%lu, %lu)\n", p, q);
    printf("Public Key (n, e): (%lu, %lu)\n", n, e);
    printf("Private Key (n, d): (%lu, %ld)\n", n, d);

    long a = power(12, e, n);
    long b = power(a, d, n);
    printf("%ld\n", b);
    return 0;
}
