#include <stdio.h>

bool isPrimeNumber(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(void)
{
    printf("%d", isPrimeNumber(97));
    return 0;
}