#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedListOP.h"

// 순회 함수
void iteratedLinkedList(LinkedList *pList)
{
    ListNode *pNode = NULL;
    int count = 0;
    if (pList != NULL)
    {
        // 헤더 노드를 시작으로 리스트의 모든 노드를 순회
        pNode = pList->headerNode.pLink;
        while (pNode != NULL)
        {
            printf("[%d]: %d\n", count, pNode->data);
            count++;

            pNode = pNode->pLink; // 다음 노드로 이동
        }
        printf("The number of nodes : %d\n", count);
    }
    else
    {
        printf("It is an empty list.\n");
    }
}

// 연결시키는 함수
void concatLinekdList(LinkedList *pListA, LinkedList *pListB)
{
    ListNode *pNodeA = NULL, *pNodeB = NULL;

    if (pListA != NULL && pListB != NULL) // 리스트의 NULL 점검
    {
        pNodeA = pListA->headerNode.pLink;
        // 연결 리스트 A의 마지막 노드 찾기
        while (pNodeA->pLink != NULL)
        {
            pNodeA = pNodeA->pLink;
        }
        // 연결 리스트 A의 마지막 노드와 연결 리스트 B의 첫 번째 노드 연결
        pNodeA->pLink = pListB->headerNode.pLink;
        pListA->currentElementCount += pListB->currentElementCount;

        // 연결 리스트 B의 첫 번째 노드로 NULL 대입 및 노드 개수 0개로 설정
        pListB->headerNode.pLink = NULL;
        pListB->currentElementCount = 0;
    }
}

// 역순으로 만드는 함수
void reverseLinkedList(LinkedList *pList)
{
    ListNode *pNode = NULL, *pCurrentNode = NULL, *pPrevNode = NULL;

    if (pList != NULL)
    {
        pNode = pList->headerNode.pLink; // 시작 노드 설정(헤더 노드의 다음 노드)
        while (pNode != NULL)
        {
            // 두 개 노드의 순서 바꾸기
            pPrevNode = pCurrentNode;        // pPrev는 이전 노드를 가리킨다
            pCurrentNode = pNode;            // pCurrentNode는 현재 노드를 가리킨다
            pNode = pNode->pLink;            // pNode는 현재 노드의 다음 노드를 가리킨다
            pCurrentNode->pLink = pPrevNode; // 현재 노드의 다음 노드가 이전 노드가 되도록 한다
        }
        // 헤더 노드의 다음 노드로 기존의 가장 마지막 노드인 pCurrentNode를 대입한다
        pList->headerNode.pLink = pCurrentNode;
    }
}