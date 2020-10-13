#include <iostream>
#include <algorithm> // sort

using namespace std;

int main(void)
{
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
    sort(a, a + 10); // 배열의 시작점 주소와 마지막 주소 + 1

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';
    }
}