// 재귀로 구현하는 이진 탐색

#include <stdio.h>

int BSearchRecur(int ar[], int first, int last, int target)
{
    int mid;
    if (first > last)
        return -1;

    mid = (first + last) / 2; // 탐색 대상의 중앙 찾기
    if (ar[mid] == target)
        return mid;
    else if (target < last)
        return BSearchRecur(ar, first, mid - 1, target); // last => mid - 1
    else
        return BSearchRecur(ar, mid + 1, last, target); // first => mid + 1
}

int main(void)
{
    int arr[] = {1, 3, 5, 7, 9};
    int idx;

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
    if (idx == -1)
        printf("Search Failed\n");
    else
        printf("Target Saved Index : %d\n", idx);

    idx = BSearchRecur(arr, 0, sizeof(arr) / sizeof(int) - 1, 4);
    if (idx == -1)
        printf("Search Failed\n");
    else
        printf("Target Saved Index : %d\n", idx);

    return 0;
}