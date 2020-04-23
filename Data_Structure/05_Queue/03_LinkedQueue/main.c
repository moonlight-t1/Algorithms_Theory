#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

void displayLinkedQueue(LinkedQueue *pQueue)
{
    QueueNode *pNode = NULL;
    int i = 0;

    if (pQueue != NULL)
    {
        printf("Current Number of Nodes : %d\n", pQueue->currentElementCount);

        pNode = pQueue->pFrontNode;
        while (pNode != NULL)
        {
            printf("[%d] - [%c]\n", i, pNode->data);
            i++;
            pNode = pNode->pLink;
        }
    }
}

int enqueueLQChar(LinkedQueue *pQueue, char data)
{
    QueueNode node = {
        0,
    };
    node.data = data;
    return enqueueLQ(pQueue, node);
}

int main(int argc, char *argv[])
{
    LinkedQueue *pQueue = NULL;
    QueueNode *pNode = NULL;
    char value = 0;

    pQueue = createLinkedQueue(4);
    if (pQueue != NULL)
    {
        // 큐 초기화 : 'A', 'B', 'C', 'D' 추가
        enqueueLQChar(pQueue, 'A');
        enqueueLQChar(pQueue, 'B');
        enqueueLQChar(pQueue, 'C');
        enqueueLQChar(pQueue, 'D');
        displayLinkedQueue(pQueue);

        pNode = dequeueLQ(pQueue);
        if (pNode != NULL)
        {
            printf("Dequeue Value - [%c]\n", pNode->data);
            free(pNode);
        }
        displayLinkedQueue(pQueue);

        pNode = peekLQ(pQueue);
        if (pNode != NULL)
        {
            printf("Peek Value - [%c]\n", pNode->data);
        }
        displayLinkedQueue(pQueue);

        enqueueLQChar(pQueue, 'E');

        displayLinkedQueue(pQueue);

        return 0;
    }
}