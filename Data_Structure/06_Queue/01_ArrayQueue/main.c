#include <stdio.h>
#include <stdlib.h>
#include "ArrayQueue.h"

void displayArrayQueue(ArrayQueue *pQueue)
{
    int i = 0;

    if (pQueue != NULL)
    {
        printf("Queue Size : %d, Current Number of Nodes : %d\n", pQueue->maxElementCount, pQueue->currentElementCount);

        for (i = pQueue->front + 1; i <= pQueue->rear; i++)
        {
            printf("[%d] - [%c]\n", i, pQueue->pElement[i].element);
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