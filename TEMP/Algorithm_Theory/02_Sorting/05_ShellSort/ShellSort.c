#include <stdio.h>
#include <stdlib.h>

void shellInsertionSort(int value[], int start, int end, int interval);
void printArray(int value[], int count);

void shellSort(int value[], int count)
{
    int i = 0, interval = 0;

    // 초기 간격(interval)은 자료 개수의 1/2로 설정한다
    interval = count / 2;

    // 간격이 1이 될 때까지 루프를 돈다.
    while (interval >= 1)
    {
        // 주어진 간격 interval로 삽입 정렬을 실시한다.
        // 삽입 정렬 함수에 간격 interval 조건을 추가한 함수 shellInsertionSort()을 호출한다
        for (i = 0; i < interval; i++)
        {
            shellInsertionSort(value, i, count - 1, interval);
        }

        printf("Interval-%d, ", interval);
        printArray(value, count);

        interval = interval / 2; // 간격을 기존 간격의 1/2로 줄인다
    }
}

void shellInsertionSort(int value[], int start, int end, int interval)
{
    int i = 0;
    int item = 0, index = 0;

    // 정렬의 범위가 start + interval 부터 end까지 이다.
    // 또한, 간격을 이용하여 정렬 대상을 선정한다.
    for (i = start + interval; i <= end; i = i + interval)
    {
        // 삽입 정렬의 키 값과 위치를 초기화 시킨다
        item = value[i];
        index = i - interval;

        // 내부 루프를 돌면서 삽입할 위치를 찾는다.
        // 기존 정렬된 부분 집합의 제일 뒷 자료부터 시작하여 제일 첫 자료까지(index >= start)
        // 루프를 돌면서, 정렬할 자료의 키 값(item)보다 키 값이 작은 자료를 찾을 때(item > value[index]) 루프가 중단된다.

        while ((index >= start) && item < value[index])
        {
            // 단, 내부 루프를 돌기 위해 각 단계 별로 자료를 오른쪽으로 간격만큼 이동시키고,
            // 인덱스 값을 간격만큼 감소시킨다.
            value[index + interval] = value[index];
            index = index - interval;
        }

        // 최종적으로 찾은 위치에 정렬할 자료를 삽입한다.
        value[index + interval] = item;
    }
}

int main(int argc, char *argv[])
{
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before Sorted\n");
    printArray(values, 8);

    shellSort(values, 8);

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