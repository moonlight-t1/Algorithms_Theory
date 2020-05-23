#include <stdio.h>
#include <stdlib.h>

void printArray(int value[], int count);

// 버블 정렬
void bubbleSort(int value[], int count)
{
    int i = 0, j = 0;
    int temp = 0;

    // 전체 자료 개수보다 1 적은 횟수(count-1)만큼 루프를 돈다.
    // 정렬의 마지막에 남은 자료는 최대 자료이기 떄문에 추가 정렬이 필요없다.
    for (i = count - 1; i >= 0; i--)
    {
        // 정렬되지 않은 자료들을 대상으로 이웃한 두 자료 사이의 위치를 교환한다.
        for (j = 0; j <= i; j++)
        {
            if (value[j - 1] > value[i])
            {
                temp = value[j - 1];
                value[j - 1] = value[j];
                value[j] = temp;
            }
        }
        printf("Step - %d : ", i + 1);
        printArray(value, count);
    }
}

int main(int argc, char *argv[])
{
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before Sorted\n");
    printArray(values, 8);

    bubbleSort(values, 8);

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