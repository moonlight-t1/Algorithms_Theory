#include <stdio.h>

int number = 10;
int data[] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void show()
{
    int i;
    for (i = 0; i < number; i++)
    {
        printf("%d ", data[i]);
    }
}

void quickSort(int *data, int start, int end)
{
    // 원소가 1개인 경우 그대로 두기
    if (start >= end)
    {
        return;
    }

    int key = start;   // 키는 첫 번째 원소
    int i = start + 1; // 왼쪽부터 찾을 때 인덱스
    int j = end;       // 오른쪽부터 찾을 때 인덱스
    int temp;

    // 엇갈릴 때까지 반복
    while (i <= j)
    {
        // 키 값보다 큰 값을 만날 때까지
        while (i <= end && data[i] <= data[key])
        {
            i++;
        }
        // 키 값보다 작은 값을 만날 때까지
        while (j > start && data[j] >= data[key])
        {
            j--;
        }
        // 현재 엇갈린 상태면 키 값과 교체
        if (i > j)
        {
            temp = data[j];
            data[j] = data[key];
            data[key] = temp;
        }
        // 엇갈리지 않았다면 i와 j를 교체
        else
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j - 1);
    quickSort(data, j + 1, end);
}

int main(void)
{
    quickSort(data, 0, number - 1);
    show();
    return 0;
}