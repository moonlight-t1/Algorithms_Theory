#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayQueue.h"

// 큐 생성
ArrayQueue *createArrayQueue(int maxElementCount)
{
    ArrayQueue *pReturn = NULL;
    int i = 0;

    if (maxElementCount > 0) // 입력 파라미터의 유효성 점검
    {
        pReturn = (ArrayQueue *)malloc(sizeof(ArrayQueue)); // 메모리 할당
        if (pReturn != NULL)                                // 메모리 할당 점검
        {
            memset(pReturn, 0, sizeof(ArrayQueue));     // 메모리 초기화
            pReturn->maxElementCount = maxElementCount; // 큐 크기설정

            // 프런트(front) 및 리어(rear)의 위치 초기화(-1)
            pReturn->front = -1;
            pReturn->rear = -1;
        }
        else
        {
            printf("Error. Memory Allocation Failed. createArrayQueue()\n");
            return NULL;
        }
    }
    else
    {
        printf("Error. Queue size should be greater than 0.\n");
        return NULL;
    }
    // 원소를 저장하는 배열 메모리 할당 및 점검
    pReturn->pElement = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode) * maxElementCount);
    if (pReturn->pElement != NULL)
    {
        memset(pReturn->pElement, 0, sizeof(ArrayQueueNode) * maxElementCount); // 메모리 초기화
    }
    else
    {
        printf("Error. Memory Allocation Failed.\n");
        free(pReturn);
        return NULL;
    }
    return pReturn;
}

// 인큐 연산
int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element)
{
    int ret = FALSE;
    int i = 0;

    // 입력 파라미터에 대한 유효성 점검
    if (pQueue != NULL) // 메모리 NULL 여부
    {
        if (isArrayQueueFull(pQueue) == FALSE) // 배열에 새로운 원소 추가 가능 여부
        {
            pQueue->rear++;                           // 리어(rear) 위치 변경
            pQueue->pElement[pQueue->rear] = element; // 새로운 자료츄가
            pQueue->currentElementCount++;            // 현재 자료 개수 증가
            ret = TRUE;
        }
        else
        {
            printf("Error. Queue is full.\n");
        }
    }
    return ret;
}

// 디큐
ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue)
{
    ArrayQueueNode *pReturn = NULL;
    // 입력 파라미터에 대한 유효성 검사
    if (pQueue != NULL) // 메모리 NULL 여부
    {
        if (isArrayQueueEmpty(pQueue) == FALSE) // 공백(empty) 큐인지 여부 점검
        {
            // 반환 노드 메모리 할당 및 점검
            pReturn = (ArrayQueueNode *)malloc(sizeof(ArrayQueueNode));
            if (pReturn != NULL)
            {
                pQueue->front++;                                            // 프런트 위치 변경
                pReturn->element = pQueue->pElement[pQueue->front].element; // 반환 노드 내용 복사

                pQueue->currentElementCount--; // 큐의 원소 개수 감수
            }
            else
            {
                printf("Error. Memory Allocation Failed. dequeueAQ()\n");
            }
        }
    }
    return pReturn;
}

// 피크
ArrayQueueNode *peekAQ(ArrayQueue *pQueue)
{
    ArrayQueueNode *pReturn = NULL;
    // 입력 파라미터에 대한 유효성 검사
    if (pQueue != NULL) // 메모리 NULL 여부
    {
        if (isArrayQueueEmpty(pQueue) == FALSE) // 공백(empty) 큐인지 여부 결정
        {
            pReturn = &(pQueue->pElement[pQueue->front + 1]);
        }
    }
    return pReturn;
}

void deleteArrayQueue(ArrayQueue *pQueue)
{
    if (pQueue != NULL)
    {
        if (pQueue->pElement != NULL)
        {
            free(pQueue->pElement);
        }
        free(pQueue);
    }
}

int isArrayQueueFull(ArrayQueue *pQueue)
{
    int ret = FALSE;

    if (pQueue != NULL)
    {
        // 현재 노드의 개수가 최대 노드의 개수와 같다면
        // 리어(rear)의 위치가 현재 노드 배열의 제일 마지막에 위치해 있다면 큐는 가득 차있다
        if (pQueue->currentElementCount == pQueue->maxElementCount || pQueue->rear == pQueue->maxElementCount - 1)
        {
            ret = TRUE;
        }
    }
    return ret;
}

int isArrayQueueEmpty(ArrayQueue *pQueue)
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