#include <iostream>
#include <algorithm>

using namespace std;

string a[20000];
int n;

bool compare(string a, string b)
{
    // 길이가 짧은 단어가 먼저
    if (a.length() < b.length())
        return 1;
    else if (a.length() > b.length())
        return 0;
    // 길이가 같은 경우 사전순
    else
        return a < b;
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, compare); // compare 함수 반환값을 기준으로 정렬
    for (int i = 0; i < n; i++)
    {
        // 동일한 단어는 패스하고 출력
        if (i > 0 && a[i] == a[i - 1])
            continue;
        cout << a[i] << '\n';
    }
    return 0;
}