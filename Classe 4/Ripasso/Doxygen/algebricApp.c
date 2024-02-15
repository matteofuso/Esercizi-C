#include <stdio.h>

/// @brief Compute the sum of the two numbers
/// @param a First parameter
/// @param b Second parameter
/// @return The sum of the two numbers
int add(int a, int b)
{
    return a + b;
}

/// @brief Compute the multiplication between the two numbers
/// @param a First parameter
/// @param b Second parameter
/// @return The multiplication of the two numbers
int mul(int a, int b)
{
    return a * b;
}

/// @brief Compute the subtruction of the two numbers
/// @param a First number
/// @param b First number
/// @return The subtraction between the first and the second parameter
int sub(int a, int b)
{
    return a - b;
}

/// @brief Compute the division of the two numbers
/// @param a First number
/// @param b First number
/// @return The division between the first and the second parameter
double division(int a, int b)
{
    return a / b;
}

/// @brief The entry point of the algebric program
/// @param argc Size of argv
/// @param argv Array of pointers to char arrays (strings), list of parameters
/// @return The status of the compute
int main(int argc, char *argv[])
{
    printf("%d\n", add(6, 3));
    printf("%d\n", mul(6, 3));
    printf("%d\n", sub(6, 3));
    printf("%f\n", division(6, 3));
    return 0;
}
