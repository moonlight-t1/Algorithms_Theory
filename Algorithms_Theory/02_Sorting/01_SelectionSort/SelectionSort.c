#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);

void selectionSort(int value[], int count)
{
    int i = 0, j = 0;
    int min = 0, temp = 0;

    // 전체 자료 갯보다 1 적은 횟수(count - 1)만큼 루프를 돈다
    // 정렬의 마지막에 남은 자료는 최대 자료이기 떄문에 추가적인 정렬이 필요없다.
    for (i = 0; i < count - 1; i++)
    {
        // (정렬되지 않은 자료들 중) 최솟값의 위치(min)을 초기화 시킨다.
        min = i;

        // 정렬되지 않은 자료들(j의 값이 i+1부터 시작)을 대상으로
        // 가장 작은 키 값을 찾는다.
        for (j = i + 1; j < count; j++)
        {
            if (value[j] < value[min])
            {
                min = j;
            }
        }

        // 정렬되지 않는 자료들 중 가장 작은 키 값을 가지는 자료(위치 min)와
        // 정렬 대상이 되는 자료(위치 i)의 위치를 교환한다.
        temp = value[i];
        value[i] = value[min];
        value[min] = temp;

        printf("Step - %d : ", i + 1);
        printArray(value, count);
    }
}

int main(int argc, char *argv[])
{
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before Sorted\n");
    printArray(values, 8);

    selectionSort(values, 8);

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