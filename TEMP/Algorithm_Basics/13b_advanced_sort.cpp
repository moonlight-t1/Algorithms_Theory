#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<string> v;

int getSum(string a)
{
    int n = a.length(), sum = 0;
    for (int i = 0; i < n; i++)
    {
        // 숫자인 경우만 더합니다.
        if (a[i] - '0' <= 9 && a[i] - '0' >= 0)
        {
            sum += a[i] - '0';
        }
    }
    return sum;
}

bool compare(string a, string b)
{
    // 길이 순서로 정렬
    if (a.length() != b.length())
    {
        return a.length() < b.length();
    }
    else
    {
        int aSum = getSum(a);
        int bSum = getSum(b);
        // 글자에 포함된 숫자의 합으로 정렬
        if (aSum != bSum)
        {
            return aSum < bSum;
        }
        // 사전순으로 정렬
        else
        {
            return a < b;
        }
    }
}

int main()
{
    cin >> n;

    string input;
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end(), compare);

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}