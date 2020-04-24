#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularList.h"

CircularList *createCircularList()
{
    CircularList *pReturn = NULL;
    int i = 0;

    pReturn = (CircularList *)malloc(sizeof(CircularList));
    if (pReturn != NULL)
    {
        memset(pReturn, 0, sizeof(CircularList));
    }
    else
    {
        printf("Error. Memory Allocation Failed createCicularList()\n");
        return NULL;
    }
    return pReturn;
}

void deleteCircularList(CircularList *pList)
{
    int i = 0;
    if (pList != NULL)
    {
        clearCircularList(pList);
        free(pList);
    }
}

// 노드 추가
int addCLElement(CircularList *pList, int position, CircularListNode element)
{
    int ret = FALSE;
    int i = 0;
    CircularListNode *pPreNode = NULL, *pNewNode = NULL, *pLastNode = NULL;

    if (pList != NULL)
    {
        if (position >= 0 && position <= pList->currentElementCount)
        {
            // 메모리 할당 및 점검
            pNewNode = (CircularListNode *)malloc(sizeof(CircularListNode));
            if (pNewNode == NULL)
            {
                printf("Error. Memory Allocation Failed. addCLElement()\n");
                return 0;
            }

            // 노드 정보 초기화
            *pNewNode = element;
            pNewNode->pLink = NULL;

            // Case 1 : 맨 앞(poistion = 0)에 추가하는 경우
            if (position == 0)
            {
                // Case 1-1 공백 리스트에서 첫 번째 노드를 추가하는 경우
                if (pList->currentElementCount == 0)
                {
                    pList->pLink = pNewNode;
                    pNewNode->pLink = pNewNode;
                }
                else
                {
                    // 마지막 노드를 찾을 때까지 이동
                    // pLastNode 순회
                    pLastNode = pList->pLink;
                    while (pLastNode->pLink != pList->pLink)
                    {
                        pLastNode = pLastNode->pLink;
                    }
                    // Case 1-2 공백 리스트가 아닌 우너형 연결 리스트에서 첫 번쨰 노드를 추가하는 경우
                    pList->pLink = pNewNode;            // 헤드가 새노드를 가리킨다
                    pNewNode->pLink = pLastNode->pLink; // 마지막 노드의 다음 노드를 새노드가 가리키게 한다
                    pLastNode->pLink = pNewNode;        // 마지막 노드를 새노드를 가리키게 한다
                }
            }
            // Case 2 : 중간에 삽입
            else
            {
                // 추가하려는 위치의 이전 노드를 찾을 떄까지 이동
                // pPreNode를 삽입 위치 이전(position - 1)로 이동
                pPreNode = pList->pLink;
                for (i = 0; i < position - 1; i++)
                {
                    pPreNode = pPreNode->pLink;
                }
                // Case 2 : 중간에 노드를 삽입하는 경우
                pNewNode->pLink = pPreNode->pLink; // 새 노드를 다음 노드를 가리키게 한다
                pPreNode->pLink = pNewNode;        // 새 노드의 이전 노드를 새 노드를 가리키게 하낟
            }

            pList->currentElementCount++;
            ret = TRUE;
        }
        else
        {
            printf("Error. Position Indoex - [%d] addCLElement()\n", position);
        }
    }
    return ret;
}

// 노드 제거
int removeCLElement(CircularList *pList, int position)
{
    int ret = FALSE;
    int i = 0, arrayCount = 0;
    CircularListNode *pPreNode = NULL, *pDelNode = NULL, *pLastNode = NULL;

    if (pList != NULL)
    {
        arrayCount = getCircularListLength(pList);
        if (position >= 0 && position < arrayCount)
        {
            // Case 1 : 맨 앞 노드(position = 0)을 삭제하는 경우
            if (position == 0)
            {
                pDelNode = pList->pLink; // pDelNode를 첫 번쨰 노드르 가리키게 한다
                // Case 1-1 마지막 노드이면서 동시에 첫 번째 노드를 제거하는 경우
                if (arrayCount == 1)
                {
                    free(pDelNode);
                    pList->pLink = NULL;
                }
                // Case 1-2 마지막 노드가 아니면서, 첫 번재 노드를 제거하는 경우
                else
                {
                    // 마지막 노드를 찾을 때까지 이동
                    pLastNode = pList->pLink;
                    while (pLastNode->pLink != pList->pLink)
                    {
                        pLastNode = pLastNode->pLink;
                    }
                    pLastNode->pLink = pDelNode->pLink; // 마지막 노드를 삭제할 노드 다음 노드를 가리키게 한다
                    pList->pLink = pDelNode->pLink;     // 헤드가 삭제할 노드(첫번쨰 노드) 다음을 가리키게 한다
                    free(pDelNode);
                }
            }
            // Case 2 : 리스트의 중간 노드를 삭제하는 경우
            else
            {
                // 삭제할 노드의 이전 위치를 찾는다
                // pPreNode를 position - 1인 노드까지 이동
                pPreNode = pList->pLink;
                for (i = 0; i < position - 1; i++)
                {
                    pPreNode = pPreNode->pLink;
                }
                pDelNode = pPreNode->pLink;        // 삭제할 노드
                pPreNode->pLink = pDelNode->pLink; // 삭제할 노드 이전 노드를 삭제할 노드 다음 노드와 연결
                free(pDelNode);
            }
            pList->currentElementCount--;
            ret = TRUE;
        }
        else
        {
            printf("Error. Position Index - [%d] removeCLElement()\n", position);
        }
    }
    return ret;
}

void clearCircularList(CircularList *pList)
{
    if (pList != NULL)
    {
        while (pList->currentElementCount > 0)
        {
            removeCLElement(pList, 0);
        }
    }
}

int getCircularListLength(CircularList *pList)
{
    int ret = 0;
    if (pList != NULL)
    {
        ret = pList->currentElementCount;
    }
    return ret;
}

CircularListNode *getCLElement(CircularList *pList, int position)
{
    int i = 0;
    CircularListNode *pNode = NULL;
    if (pList != NULL)
    {
        if (position >= 0 && position < pList->currentElementCount)
        {
            pNode = pList->pLink;
            for (i = 0; i < position; i++)
            {
                pNode = pNode->pLink;
            }
        }
    }
    return pNode;
}

void displayCircularList(CircularList *pList)
{
    int i = 0;
    if (pList != NULL)
    {
        printf("Current Number of Elements : %d\n", pList->currentElementCount);
        for (i = 0; i < pList->currentElementCount; i++)
        {
            printf("[%d]: %d\n", i, getCLElement(pList, i)->data);
        }
    }
    else
    {
        printf("There is no element. It is an empty list.\n");
    }
}