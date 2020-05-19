#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedDeque.h"

// 덱 생성
LinkedDeque *createLinkedDeque()
{
    LinkedDeque *pReturn = NULL;
    int i = 0;

    // 메모리 할당 및 검증
    pReturn = (LinkedDeque *)malloc(sizeof(LinkedDeque));
    if (pReturn != NULL)
    {
        memset(pReturn, 0, sizeof(LinkedDeque)); // 구조체 변수 초기화
    }
    else
    {
        printf("Error. Memory Allocation Failed. createLinkedDeque()\n");
    }

    return pReturn;
}

// 노드 앞 추가
int insertFrontLD(LinkedDeque *pDeque, DequeNode element)
{
    int ret = FALSE;
    DequeNode *pNode = NULL;

    if (pDeque != NULL)
    {
        // 새로운 노드 메모리 할당 및 점검
        pNode = (DequeNode *)malloc(sizeof(DequeNode));
        if (pNode != NULL)
        {
            *pNode = element;     // 새로운 값 대입
            pNode->pRLink = NULL; // 다음 노드를 NULL로 설정
            pNode->pLLink = NULL; // 다음 노드를 NULL로 설정

            // 공백 상태의 덱인 경우
            if (isLinkedDequeEmpty(pDeque) == TRUE)
            {
                pDeque->pFrontNode = pNode;
                pDeque->pRearNode = pNode;
            }
            // 공백 상태가 아닌 덱인 경우
            else
            {
                pDeque->pFrontNode->pLLink = pNode;
                pNode->pRLink = pDeque->pFrontNode;
                pDeque->pFrontNode = pNode;
            }
            pDeque->currentElementCount++;
            ret = TRUE;
        }
        else
        {
            printf("Error. Memory Allocation Failed. insertFrontLD()\n");
        }
    }
    return ret;
}

// 노드 뒤 추가
int insertRearLD(LinkedDeque *pDeque, DequeNode element)
{
    int ret = FALSE;
    DequeNode *pNode = NULL;

    if (pDeque != NULL)
    {
        // 새로운 노드 메모리 할당 및 점검
        pNode = (DequeNode *)malloc(sizeof(DequeNode));
        if (pNode != NULL)
        {
            *pNode = element;     // 새로운 자료 값 대입
            pNode->pRLink = NULL; // 다음 노드를 NULL로 설정
            pNode->pLLink = NULL; // 다음 노드를 NULL로 설정

            // 공백 상태의 덱인 경우
            if (isLinkedDequeEmpty(pDeque) == TRUE)
            {
                pDeque->pFrontNode = pNode;
                pDeque->pRearNode = pNode;
            }
            // 공백 상태가 아닌 덱인 경우
            else
            {
                pDeque->pRearNode->pRLink = pNode;
                pNode->pLLink = pDeque->pRearNode;
                pDeque->pRearNode = pNode;
            }
            pDeque->currentElementCount++;
            ret = TRUE;
        }
        else
        {
            printf("Error. Memory Allocation Failed. insertRearLD()\n");
        }
    }
    return ret;
}

// 맨 앞 노드 제거
DequeNode *deleteFrontLD(LinkedDeque *pDeque)
{
    DequeNode *pReturn = NULL;
    if (pDeque != NULL)
    {
        if (isLinkedDequeEmpty(pDeque) == FALSE)
        {
            // 일반적인 경우
            pReturn = pDeque->pFrontNode;
            pDeque->pFrontNode = pDeque->pFrontNode->pRLink;
            pReturn->pRLink = NULL;

            pDeque->currentElementCount--;

            // 덱에 남은 마지막 노드를 제거한 경우 Rear 처리
            if (isLinkedDequeEmpty(pDeque) == TRUE)
            {
                pDeque->pRearNode = NULL;
            }
            // 일반적인 경우(덱에 여전히 노드가 1개 이상 존재)
            else
            {
                pDeque->pFrontNode->pLLink = NULL;
            }
        }
    }
    return pReturn;
}

// 맨 뒤 노드 삭제
DequeNode *deleteRearLD(LinkedDeque *pDeque)
{
    DequeNode *pReturn = NULL;

    if (pDeque != NULL)
    {
        if (isLinkedDequeEmpty(pDeque) == FALSE)
        {
            // 일반적인 경우
            pReturn = pDeque->pRearNode;
            pDeque->pRearNode = pDeque->pRearNode->pLLink;
            pReturn->pLLink = NULL;

            pDeque->currentElementCount--;

            // 덱에 남은 마지막 노드를 제거한 경우
            if (isLinkedDequeEmpty(pDeque) == TRUE)
            {
                pDeque->pFrontNode = NULL;
            }
            // 일반적인 경우(덱에 여전히 노드가 1개 이상 존재)
            else
            {
                pDeque->pRearNode->pRLink = NULL;
            }
        }
    }
    return pReturn;
}

// 맨 앞 노드 peek
DequeNode *peekFrontLD(LinkedDeque *pDeque)
{
    DequeNode *pReturn = NULL;
    if (pDeque != NULL)
    {
        if (isLinkedDequeEmpty(pDeque) == FALSE)
        {
            pReturn = pDeque->pFrontNode;
        }
    }
    return pReturn;
}

// 맨 뒤 노드 peek
DequeNode *peeRearLD(LinkedDeque *pDeque)
{
    DequeNode *pReturn = NULL;
    if (pDeque != NULL)
    {
        if (isLinkedDequeEmpty(pDeque) == FALSE)
        {
            pReturn = pDeque->pRearNode;
        }
    }
    return pReturn;
}

void deleteLinkedQueue(LinkedDeque *pDeque)
{
    DequeNode *pNode = NULL;
    DequeNode *pDelNode = NULL;

    if (pDeque != NULL)
    {
        pNode = pDeque->pFrontNode;
        while (pNode != NULL)
        {
            pDelNode = pNode;
            pNode = pNode->pRLink;
            free(pDelNode);
        }
        free(pDeque);
    }
}

int isLinkedDequeFull(LinkedDeque *pDeque)
{
    int ret = FALSE;
    return ret;
}

int isLinkedDequeEmpty(LinkedDeque *pDeque)
{
    int ret = FALSE;
    if (pDeque != NULL)
    {
        if (pDeque->currentElementCount == 0)
        {
            ret = TRUE;
        }
    }
    return ret;
}