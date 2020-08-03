#include <stdio.h>

int d[1000001];

long long int dp(int d[], int x)
{
    if (x == 0)
        return 1;
    if (x == 1)
        return 2;
    if (x == 2)
        return 7;
    if (d[x] > 0)
        return d[x];
    long long int result = 3 * dp(d, x - 2) + 2 * dp(d, x - 1);
    for (int i = 3; i <= x; i++)
    {
        result += (2 * dp(d, x - i)) % 100000007;
    }
    return d[x] = result % 100000007;
}

int main(void)
{
    int x;
    scanf("%d", &x);
    printf("%d", dp(d, x));
    return 0;
}