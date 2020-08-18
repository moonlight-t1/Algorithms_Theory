// 이진 탐색

#include <stdio.h>

int BSearch(int ar[], int len, int target)
{
    int first = 0; // 탐색 대상의 시작 인덱스
    int last = len - 1;
    int mid;

    // first가 last보다 큰 경우 탐색은 종료 => 탐색 실패
    while (first <= last)
    {
        mid = (first + last) / 2; // 탐색 대상의 중앙 찾기
        // 탐색 완료
        if (target == ar[mid])
            return mid;
        else
        {
            if (target < ar[mid])
                last = mid - 1;
            else
                first = mid + 1;
        }
    }
    return -1; // 탐색 실패 시 -1 반환
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearch(arr, sizeof(arr) / sizeof(int), 5);
    if (idx == -1)
        printf("Search Failed\n");
    else
        printf("Target saved index : %d\n", idx);
    return 0;
}