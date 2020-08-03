#include <iostream>
#include <algorithm>

using namespace std;

// 정렬 기준이 되는 함수
bool compare(int a, int b)
{
    return a < b;
}

int main(void)
{
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};
    sort(a, a + 10, compare); // 해당 함수의 반환값에 맞게 정렬

    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << ' ';
    }
}