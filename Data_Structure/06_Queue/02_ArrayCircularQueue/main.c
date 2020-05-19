#include <stdio.h>
#include <stdlib.h>
#include "ArrayQueue.h"

void displayArrayQueue(ArrayQueue *pQueue)
{
    int i = 0;
    int maxElementIndex = 0, pos = 0;

    if (pQueue != NULL)
    {
        printf("Queue Size : %d, Current Number of Nodes : %d\n", pQueue->maxElementCount, pQueue->currentElementCount);

        // front를 기준으로 rear의 인덱스 값 계산
        maxElementIndex = pQueue->front + pQueue->currentElementCount;
        for (i = pQueue->front + 1; i <= maxElementIndex; i++)
        {
            pos = i % pQueue->maxElementCount;
            printf("[%d] - [%c]\n", pos, pQueue->pElement[pos].element);
        }
    }
}

int enqueueAQChar(ArrayQueue *pQueue, char data)
{
    ArrayQueueNode node = {
        0,
    };
    node.element = data;
    return enqueueAQ(pQueue, node);
}

int main(int argc, char *argv[])
{
    ArrayQueue *pQueue = NULL;
    ArrayQueueNode *pNode = NULL;
    char value = 0;

    pQueue = createArrayQueue(4);
    if (pQueue != NULL)
    {
        // 큐 초기화 : 'A', 'B', 'C', 'D' 추가
        enqueueAQChar(pQueue, 'A');
        enqueueAQChar(pQueue, 'B');
        enqueueAQChar(pQueue, 'C');
        enqueueAQChar(pQueue, 'D');
        displayArrayQueue(pQueue);

        pNode = dequeueAQ(pQueue);
        if (pNode != NULL)
        {
            printf("Dequeue Value - [%c]\n", pNode->element);
            free(pNode);
        }
        displayArrayQueue(pQueue);

        pNode = peekAQ(pQueue);
        if (pNode != NULL)
        {
            printf("Peek Value - [%c]\n", pNode->element);
        }
        displayArrayQueue(pQueue);

        enqueueAQChar(pQueue, 'E');

        displayArrayQueue(pQueue);
    }
    return 0;
}