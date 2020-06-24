#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

void printArray(int value[], int count);
void radixSort(int value[], int count, int radix, int digit)
{
    int i = 0, bucket = 0, d = 0, factor = 1;
    LinkedQueue **ppQueue = NULL;
    QueueNode node = {
        0,
    };

    // 기수(radix)만큼 연결 큐를 생성하기 위해 메모리를 할당하고, 이를 검증
    ppQueue = (LinkedQueue **)malloc(sizeof(LinkedQueue *) * radix);
    if (ppQueue == NULL)
    {
        printf("Error, Memory Allocation Failed, radixSort()\n");
        return;
    }

    // 각 기수에 해당하는 버킷(연결 큐)를 생성한다.
    // 단, 버킷을 생성하는 도중 오류가 발생하였을 경우, 이미 할당된 메모리를 해제한다.
    for (bucket = 0; bucket < radix; bucket++)
    {
        ppQueue[bucket] = createLinkedQueue();
        if (ppQueue[bucket] == NULL)
        {
            for (i = 0; i < bucket - 1; i++)
            {
                if (ppQueue[i] != NULL)
                {
                    deleteLinkedQueue(ppQueue[i]);
                }
                free(ppQueue);
                printf("Error, createLinkedQueue() in radixSort()\n");
                return;
            }
        }
    }

    // 각 자릿수별로 루프를 돌면서 분배 및 저장 연산을 실행
    for (d = 0; d < digit; d++)
    {
        for (i = 0; i < count; i++)
        {
            node.data = value[i];
            enqueueLQ(ppQueue[(value[i] / factor) % radix], node);
        }

        // 자료의 분배가 완료된 다음, 각 버킷별로 루프를 돌면서 자료를 꺼내어 이를 저장
        i = 0;
        for (bucket = 0; bucket < radix; bucket++)
        {
            while (isLinkedQueueEmpty(ppQueue[bucket]) == FALSE)
            {
                QueueNode *pNode = dequeueLQ(ppQueue[bucket]);
                if (pNode != NULL)
                {
                    value[i] = pNode->data;
                    i++;
                    free(pNode);
                }
            }
        }

        printf("Digit-%d,", factor);
        printArray(value, count);
        factor = factor * radix;
    }

    // 할당된 버킷(연결 큐)의 메모리를 해제
    // 단, 큐들의 배열이기 때문에 루프 루프를 돌며 각각의 버킷을 메모리 해제시키고, 전체 메모리를 해제
    for (bucket = 0; bucket < radix; bucket++)
    {
        deleteLinkedQueue(ppQueue[bucket]);
    }

    free(ppQueue);
}

int main(int argc, char *argv[])
{
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before Sorted\n");
    printArray(values, 8);

    radixSort(values, 8, 10, 2);

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