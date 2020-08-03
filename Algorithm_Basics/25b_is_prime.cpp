#include <stdio.h>
#include <math.h>

bool isPrimeNumber(int x)
{
    int end = (int)sqrt(x);
    for (int i = 2; i <= end; i++)
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