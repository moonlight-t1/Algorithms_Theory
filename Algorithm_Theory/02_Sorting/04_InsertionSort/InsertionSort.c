#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);

void insertionSort(int value[], int count)
{
    int i = 0, j = 0;
    int temp = 0;

    // '두 번째 자료'부터 전체 자료 개수(count)만큼 루프를 돈다.
    // 초기 정렬 시에 두 번째 자료와 첫 번째 자료를 비교하기 위해서이다.
    for (i = 1; i < count; i++)
    {
        // 정렬할 자료의 키 값(value[i])과 위치(i)로 초기화 한다.
        temp = value[i];
        j = i;

        // 내부 루프를 돌면서 삽입할 위치를 찾는다.
        // 즉, 기존 정렬의 부분 집합의 제일 뒤 자료부터 시작하여 제일 첫 자료까지(j > 0)
        // 루프를 돌면서, 정렬할 자료의 키 값(temp)보다 키 값이 작은 자료를 찾을 때(value[j-1] > temp) 루프가 중단된다.
        while ((j > 0) && value[j - 1] > temp)
        {
            // 내부 루프를 돌기 위해 각 단계별로 자료를 오른쪽으로 한 칸씩 이동시키고, 인덱스 값을 1 감소시킨다.
            value[j] = value[j - 1];
            j = j - 1;
        }

        // 최종적으로 찾은 위치에 정렬할 자료를 삽입한다.
        value[j] = temp;

        printf("Step-%d, ", i);
        printArray(value, count);
    }
}

int main(int argc, char *argv[])
{
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before Sorted\n");
    printArray(values, 8);

    insertionSort(values, 8);

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