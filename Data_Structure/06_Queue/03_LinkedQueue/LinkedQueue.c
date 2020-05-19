#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedQueue.h"

// 큐의 생성
LinkedQueue *createLinkedQueue()
{
    LinkedQueue *pReturn = NULL;
    int i = 0;

    pReturn = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    if (pReturn != NULL)
    {
        memset(pReturn, 0, sizeof(LinkedQueue));
    }
    else
    {
        printf("Error. Memory Allocation Failed. createLinkedQueue()\n");
    }
    return pReturn;
}

// 인큐
int enqueueLQ(LinkedQueue *pQueue, QueueNode element)
{
    int ret = FALSE;
    QueueNode *pNode = NULL;

    if (pQueue != NULL)
    {
        // 새로운 노드 메모리 할당 및 점검
        pNode = (QueueNode *)malloc(sizeof(QueueNode));
        if (pNode != NULL)
        {
            *pNode = element;    // 새로운 자료값 대입
            pNode->pLink = NULL; // 새 노드의 다음 노드를 NULL로 설정

            // 공백인 큐인 경우
            if (isLinkedQueueEmpty(pQueue) == TRUE)
            {
                pQueue->pFrontNode = pNode;
                pQueue->pRearNode = pNode;
            }
            // 공백이 아닌 큐인 경우
            else
            {
                pQueue->pRearNode->pLink = pNode; // 이전 노드와 새 노드 연결
                pQueue->pRearNode = pNode;        // Rear와 새 노드
            }
            pQueue->currentElementCount++;
            ret = TRUE;
        }
        else
        {
            printf("Error. Memory Allocation Failed. enqueueLQ()\n");
        }
    }
    return ret;
}

// 디큐
QueueNode *dequeueLQ(LinkedQueue *pQueue)
{
    QueueNode *pReturn = NULL;
    if (pQueue != NULL)
    {
        // 일반적인 경우
        if (isLinkedQueueEmpty(pQueue) == FALSE)
        {
            pReturn = pQueue->pFrontNode;                   // pReturndms 삭제할 노드 가리킨다
            pQueue->pFrontNode = pQueue->pFrontNode->pLink; // FrontNode는 Front의 이전 노드를 가리킨다
            pReturn->pLink = NULL;                          // 삭제할 노드의 링크를 끊는다

            pQueue->currentElementCount--;

            // 큐에 남은 마지막 노드를 디큐한 경우
            if (isLinkedQueueEmpty(pQueue) == TRUE)
            {
                pQueue->pRearNode = NULL; // RearNode에 NULL 할당
            }
        }
    }

    return pReturn;
}

// 피크
QueueNode *peekLQ(LinkedQueue *pQueue)
{
    QueueNode *pReturn = NULL;
    if (pQueue != NULL)
    {
        if (isLinkedQueueEmpty(pQueue) == FALSE)
        {
            pReturn = pQueue->pFrontNode;
        }
    }
    return pReturn;
}

void deleteLinkedQueue(LinkedQueue *pQueue)
{
    QueueNode *pNode = NULL;
    QueueNode *pDelNode = NULL;

    if (pQueue != NULL)
    {
        // 시작 노드 -> 프런트 노드
        pNode = pQueue->pFrontNode;
        // 루프 돌면서 각 노드들 메모리 해제
        while (pNode != NULL)
        {
            pDelNode = pNode;
            pNode = pNode->pLink;

            free(pDelNode);
        }
        free(pQueue);
    }
}

int isLinkedQueueFull(LinkedQueue *pQueue)
{
    int ret = FALSE;
    return ret;
}

int isLinkedQueueEmpty(LinkedQueue *pQueue)
{
    int ret = FALSE;

    if (pQueue != NULL)
    {
        if (pQueue->currentElementCount == 0)
        {
            ret = TRUE;
        }
    }
    return ret;
}