#include <iostream>

using namespace std;

void findString(string parent, string pattern)
{
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int parentHash = 0, patternHash = 0, power = 1;
    for (int i = 0; i <= parentSize - patternSize; i++)
    {
        if (i == 0)
        {
            for (int j = 0; j < patternSize; j++)
            {
                parentHash = parentHash +
                             parent[patternSize - 1 - j] * power;
                patternHash = patternHash +
                              pattern[patternSize - 1 - j] * power;
                if (j < patternSize - 1)
                    power = power * 403;
            }
        }
        else
        {
            parentHash = 403 * (parentHash - parent[i - 1] * power) +
                         parent[patternSize - 1 + i];
        }
        printf("해시 값 비교: %d %d\n", parentHash, patternHash);
    }
}

int main(void)
{
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    findString(parent, pattern);
    return 0;
}