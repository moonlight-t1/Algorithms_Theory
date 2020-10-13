#include <stdio.h>
#include <stdlib.h>

int partitionQuickSort(int value[], int start, int end);
void printArray(int value[], int count);

// 퀵 정렬
void quickSort(int value[], int start, int end)
{
    int pivot = 0;

    // 정렬 시작 위치(start)와 끝 위치(end)를 비교하여 퀵 정렬을 수행할지 결정한다.
    // 시작 위치가 끝 위치와 같거나 크다면 더 이상 퀵 정렬을 수행하지 않는다.
    if (start < end)
    {
        pivot = partitionQuickSort(value, start, end);
        // 분할 정복을 위해 리턴된 피봇 위치를 이용하여 왼쪽 부분 집합과 오른쪽 부분 집합에 대해
        // 각각 quickSort()를 재귀적으로 호출한다.
        quickSort(value, start, pivot - 1);
        quickSort(value, pivot + 1, end);
    }
}

int partitionQuickSort(int value[], int start, int end)
{
    int pivot = 0;
    int temp = 0, left = 0, right = 0;

    // left와 right 및 피봇의 위치를 초기화 시킨다.
    // 여기서는 피봇의 초기 위치를 right와 동일하게 한다.
    left = start;
    right = end;
    pivot = end;

    // left가 right의 왼쪽에 있을 동안 루프를 실행한다
    while (left < right)
    {
        // left는 피봇 값보다 큰 값을 찾기 위해 오른쪽으로 이동한다.
        // 단, right보다 더 오른쪽으로 이동할 수 없다
        while ((value[left] < value[pivot]) && (left < right))
        {
            left++;
        }

        // right는 피봇보다 더 작은 값을 찾기 위해 왼쪽으로 이동한다.
        // 단, left보다 더 왼쪽으로 이동할 수 없다.
        while ((value[right] >= value[pivot]) && (left < right))
        {
            right--;
        }

        // left와 right의 위치가 적합하다면(left가 right보다 왼쪽)
        // 이 경우 두 자료의 위치를 교환한다.
        if (left < right)
        {
            temp = value[left];
            value[left] = value[right];
            value[right] = temp;

            printf("start-[%d], end-[%d], pivot-[%d], in-loop: ", start, end, value[pivot]);

            printArray(value, end - start + 1);
        }
    }

    // 최종적으로 결정된 left & right 위치의 자료와 피봇의 자료를 위치 교환한다
    temp = value[pivot];
    value[pivot] = value[right];
    value[right] = temp;
    printf("start-[%d], end-[%d], pivot-[%d], in-loop: ", start, end, value[right]);

    printArray(value, end - start + 1);

    return right; // 최종 피봇 위치 right를 반환한다.
}

int main(int argc, char *argv[])
{
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before Sorted\n");
    printArray(values, 8);

    quickSort(values, 0, 7);

    printf("After Sorted\n");
    printArray(values, 8);

    return 0;
}

void printArray(int value[], int count)
{
    int i = 0;
    for (i = 0; i < count; i++)
    {
        printf("%d ", value[i]);
    }
    printf("\n");
}