#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

// 연결 리스트의 생성
LinkedList *createLinkedList()
{
    LinkedList *pReturn = NULL;
    int i = 0;

    // 메모리 할당과 점검
    pReturn = (LinkedList *)malloc(sizeof(LinkedList));
    if (pReturn != NULL)
    {
        // 구조체 초기화
        memset(pReturn, 0, sizeof(LinkedList));
    }
    else
    {
        printf("Error. Memory Allocation Failed. createLinkedList()\n");
        return NULL;
    }

    return pReturn;
}

// 노드 추가
int AddLLElement(LinkedList *pList, int position, ListNode element)
{
    int ret = FALSE;
    int i = 0;
    ListNode *pPreNode = NULL;
    ListNode *pNewNode = NULL;

    // 입력 파라미터에 대한 유효성 점검
    if (pList != NULL) // 연결 리스트 NULL 여부
    {
        if (position >= 0 && position <= pList->currentElementCount) // 추가하려는 위치와 인덱스
        {
            pNewNode = (ListNode *)malloc(sizeof(ListNode));
            if (pNewNode != NULL) // 메모리 NULL 여부
            {
                // 새로 추가된 노드의 값 설정과 링크 초기화
                *pNewNode = element;
                pNewNode->pLink = NULL;

                // 새로운 노드가 추가될 위치로 이동
                // 추가하려는 위치의 이전 노드로 이동하여 pPreNode가 가리킨다(position - 1)
                pPreNode = &(pList->headerNode);
                for (i = 0; i < position; i++)
                {
                    pPreNode = pPreNode->pLink;
                }

                // 추가된 노드와 기존 노드 사이의 링크 재설정
                pNewNode->pLink = pPreNode->pLink; // pNewNode를 position에 있는 노드를 가리키게 한다
                pPreNode->pLink = pNewNode;        // position-1(pPreNode) 노드를 pNewNode를 가리키게 한다

                // 현재 노드 개수 1 증가
                pList->currentElementCount++;

                // 리턴 값 성공으로 설정
                ret = TRUE;
            }
            else
            {
                printf("Error. Memoray Allocatio Failed. addLLElement()\n");
                return ret;
            }
        }
    }

    return ret;
}

// 노드 제거
int removeLLElement(LinkedList *pList, int position)
{
    int ret = FALSE;
    int i = 0;
    int arrayCount = 0;
    ListNode *pNode = NULL;
    ListNode *pDelNode = NULL;

    // 입력 파라미터에 대한 유효성 점검
    if (pList != NULL) // 연결 리스트 NULL 여부
    {
        arrayCount = getLinkedListLength(pList);
        if (position >= 0 && position < arrayCount) // 추가하려는 위치의 인덱스
        {
            // 제거될 노드 위치로 이동
            // 삭제할 이전 위치로 이동(position - 1)
            pNode = &(pList->headerNode);
            for (i = 0; i < position; i++)
            {
                pNode = pNode->pLink;
            }

            // 제거될 노드와 기존 노드 사이의 링크 재설정
            // pDelNode : 삭제할 노드, pNode : 삭제할 노드의 이전 노드
            pDelNode = pNode->pLink;        // 삭제할 노드를 가리킨다
            pNode->pLink = pDelNode->pLink; // 삭제할 노드의 이전 노드와 삭제할 노드의 다음 노드 연결

            // 제거될 노드 메모리 해제
            free(pDelNode);

            // 헌재 노드 개수 1 감소
            pList->currentElementCount--;

            // 리턴 값 성공으로 설정
            ret = TRUE;
        }
        else
        {
            printf("Error. Position Index-[%d] removeLLEElement()\n", position);
        }
    }
    return ret;
}

// 리스트 원소 반환
ListNode *getLLElement(LinkedList *pList, int position)
{
    ListNode *pReturn = NULL;
    int i = 0;
    ListNode *pNode = NULL;

    // 입력 파라미터에 대한 유효성 점검
    if (pList != NULL) // 연결 리스트 NULL 여부
    {
        if (position >= 0 && position < pList->currentElementCount) // 추가하려는 위치와 인덱스
        {
            // 해당 노드 위치로 이동
            pNode = &(pList->headerNode);
            for (i = 0; i <= position; i++)
            {
                pNode = pNode->pLink;
            }
            pReturn = pNode;
        }
    }
    return pReturn;
}

void clearLinkedList(LinkedList *pList)
{
    if (pList != NULL)
    {
        if (pList->currentElementCount > 0)
        {
            removeLLElement(pList, 0);
        }
    }
}

int getLinkedListLength(LinkedList *pList)
{
    int ret = 0;
    if (pList != NULL)
    {
        ret = pList->currentElementCount;
    }

    return ret;
}

void deleteLinkedList(LinkedList *pList)
{
    int i = 0;
    if (pList != NULL)
    {
        clearLinkedList(pList);
        free(pList);
    }
}

int isEmpty(LinkedList *pList)
{
    int ret = FALSE;

    if (pList != NULL)
    {
        if (pList->currentElementCount == 0)
        {
            ret = TRUE;
        }
    }

    return ret;
}