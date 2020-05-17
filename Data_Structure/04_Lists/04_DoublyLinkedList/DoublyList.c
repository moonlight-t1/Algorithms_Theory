#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DoublyList.h"

// 연결 리스트 생성
DoublyList *createDoublyList()
{
    DoublyList *pReturn = NULL;
    int i = 0;

    // 메모리 할다 및 검증
    pReturn = (DoublyList *)malloc(sizeof(DoublyList));
    if (pReturn != NULL)
    {
        // 구조체 변수 값들을 초기화
        memset(pReturn, 0, sizeof(DoublyList));

        // 공백 리스트이므로 headerNode는 자기 자신을 가리킨다
        pReturn->headerNode.pLLink = &(pReturn->headerNode);
        pReturn->headerNode.pRLink = &(pReturn->headerNode);
    }
    else
    {
        printf("Error. Memory Allocation Failed. createDoublyList()\n");
        return NULL;
    }
    return pReturn;
}

void deleteDoublyList(DoublyList *pList)
{
    if (pList != NULL)
    {
        clearDoublyList(pList);
        free(pList);
    }
}

// 노드 추가
int addDLElement(DoublyList *pList, int position, DoublyListNode element)
{
    int ret = FALSE, i = 0;
    DoublyListNode *pPreNode = NULL, *pNewNode = NULL, *pTempNode = NULL;
    if (pList != NULL)
    {
        if (position >= 0 && position <= pList->currentElementCount)
        {
            // 새로 추가할 노드 동적 할당
            pNewNode = (DoublyListNode *)malloc(sizeof(DoublyListNode));
            if (pNewNode == NULL)
            {
                printf("Error. Memory Allocation Failed. addCLElement()\n");
                return ret;
            }

            // 삽입할 새 노드 초기화
            *pNewNode = element;
            pNewNode->pLLink = NULL;
            pNewNode->pRLink = NULL;

            // 삽입할 노드의 이전 노드를 찾아 pPreNode가 가리키게 한다
            pPreNode = &(pList->headerNode);
            for (i = 0; i < position; i++)
            {
                pPreNode = pPreNode->pRLink;
            }

            pNewNode->pLLink = pPreNode;         // 새 노드의 왼쪽 링크 연결
            pNewNode->pRLink = pPreNode->pRLink; // 새 노드의 오른쪽 링크 연결
            pPreNode->pRLink = pNewNode;         // 새 노드의 이전 노드를 새 노드와 연결
            pNewNode->pRLink->pLLink = pNewNode; // 새 노드의 오른쪽 노드를 새 노드와 연결

            pList->currentElementCount++;
            ret = TRUE;
        }
        else
        {
            printf("Error. Position Index - [%d] addDLElement()\n", position);
        }
    }
    return ret;
}

// 노드 제거
int removeDLElement(DoublyList *pList, int position)
{
    int ret = FALSE;
    int i = 0, arrayCount = 0;
    DoublyListNode *pPreNode = NULL, *pDelNode = NULL, *pTempNode = NULL;

    if (pList != NULL)
    {
        arrayCount = getDoublyListLength(pList);
        if (position >= 0 && position < arrayCount)
        {
            // 삭제할 노드의 이전 노드 위치를 찾아 pPreNode가 가리키게 한다
            pPreNode = &(pList->headerNode);
            for (i = 0; i < position; i++)
            {
                pPreNode = pPreNode->pRLink;
            }
            pDelNode = pPreNode->pRLink; // 삭제할 노드

            pPreNode->pRLink = pDelNode->pRLink; // 삭제할 노드의 이전 노드를 삭제할 노드 다음 노드와 연결
            pDelNode->pRLink->pLLink = pPreNode; // 삭제할 노드의 다음 노드를 삭제할 노드의 이전노드와 연결
            free(pDelNode);                      // 삭제할 노드(pDelNode)의 메모리를 해제한다.

            pList->currentElementCount--;
            ret = TRUE;
        }
        else
        {
            printf("Error. Position Index - [%d]. removeDLElement()\n", position);
        }
        return ret;
    }
}

void clearDoublyList(DoublyList *pList)
{
    if (pList != NULL)
    {
        while (pList->currentElementCount > 0)
        {
            removeDLElement(pList, 0);
        }
    }
}

int getDoublyListLength(DoublyList *pList)
{
    int ret = 0;
    if (pList != NULL)
    {
        ret = pList->currentElementCount;
    }
    return ret;
}

DoublyListNode *getDLElement(DoublyList *pList, int position)
{
    DoublyListNode *pReturn = NULL;
    int i = 0;
    DoublyListNode *pNode = NULL;
    if (pList != NULL)
    {
        if (position >= 0 && position < pList->currentElementCount)
        {
            pNode = pList->headerNode.pRLink;
            for (i = 0; i < position; i++)
            {
                pNode = pNode->pRLink;
            }
            pReturn = pNode;
        }
        else
        {
            printf("Error. Position Index - [%d] getDLElement()\n", position);
        }
    }
    return pReturn;
}

void displayDoublyList(DoublyList *pList)
{
    int i = 0;
    if (pList != NULL)
    {
        printf("Current Number of Elements : %d\n", pList->currentElementCount);

        for (i = 0; i < pList->currentElementCount; i++)
        {
            printf("[%d] - %d\n", i, getDLElement(pList, i)->data);
        }
    }
    else
    {
        printf("There is no element. It is an empty list.\n");
    }
}