#include <stdio.h>
#include <stdlib.h>

void mergeSortInternal(int value[], int buffer[], int start, int middle, int end);

void mergeSort(int value[], int buffer[], int start, int end)
{
    int middle = 0;
    // 원소의 개수가 1이 될 때까지 순환적으로 병합정렬을 실시한다
    if (start < end)
    {
        // 2개의 부분 집합으로 나누기 위해 중간 위치 middle을 구한다.
        middle = (start + end) / 2;

        // 왼쪽 부분 집합(start, middle)과 오른쪽 부분 집합(middle+1, end)에 대해
        // 순환적으로 병합 정렬을 실시한다.
        mergeSort(value, buffer, start, middle);
        mergeSort(value, buffer, middle + 1, end);

        // 병합 정렬이 완료된 두 개의 부분 집합에 대해 병합을 실시한다.
        // 단, 이 때 병합을 위해 배열의 개수만큼의 추갖거인 메모리 공간이 필요하며,
        // 이를 위해 버퍼(buffer)를 전달한다.
        // 이 버퍼는 전달 받은 것으로, 함수 mergeSort()를 사용하기 위해서는
        // 이러한 버퍼를 입력 파라미터로 전달해야 한다.
        mergeSortInternal(value, buffer, start, middle, end);
    }
}

void mergeSortInternal(int value[], int buffer[], int start, int middle, int end)
{
    // 변수들을 초기화 시킨다.
    int i = 0; // i : 첫 번째 부분 집합의 원소를 가리키는 인덱스
    int j = 0; // j : 두 번쨰 부분 집합의 원소를 가리키는 인덱스
    int k = 0; // k : 결과 버퍼의 현재 위치를 가리키는 인덱스

    i = start;
    j = middle + 1;
    k = start;

    // 두 개의 부분 집합 (start, middle) 및 (middle+1, end)을 대상으로 루프를 돌면서
    // 각 부분 집합의 원소의 키 값을 비교한다.
    // 만약 키 값이 작다면 해당 우너소의 키 값을 복사하고, 다음 원소를 가리키도록 이동시킨다.
    while (i <= middle && j <= end)
    {
        if (value[i] <= value[j])
        {
            buffer[k] = value[i];
            i++;
        }
        else
        {
            buffer[k] = value[j];
            j++;
        }
        k++;
    }
    // 위의 루프를 빠져 나온 것은 두 개의 부분 집합 중 한 개 부분 집합이 모두 복사되었다는 의미이므로,
    // 원소가 남은 다른 부분 집합의 자료를 복사해주어야 한다.
    // 어느 부분 집합의 원소가 남았는지 판단한 다음, 해당 부분 집합의 남은 원소들을 결과 버퍼에 복사한다.
    if (i > middle)
    {
        for (int t = j; t <= end; t++, k++)
        {
            buffer[k] = value[t];
        }
    }
    else
    {
        for (int t = i; t <= middle; t++, k++)
        {
            buffer[k] = value[t];
        }
    }

    // 정렬 결과가 저장된 버퍼의 내용을 최종적으로 복사한다.
    for (int t = start; t <= end; t++)
    {
        value[t] = buffer[t];
    }
    printf("start-%d, middle-%d, end-%d, ", start, middle, end);
    for (int t = start; t <= end; t++)
    {
        printf("%d ", value[t]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before Sorted\n");
    printArray(values, 8);

    // 병합 정렬은 정렬 도중 배열의 개수만큼 추가 메모리 공간이 필요하다
    int *pBuffer = NULL;
    pBuffer = (int *)malloc(sizeof(int) * 8);

    if (pBuffer != NULL)
    {
        mergeSort(values, pBuffer, 0, 7);

        free(pBuffer);
    }

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