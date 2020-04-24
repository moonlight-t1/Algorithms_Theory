#include <stdio.h>
#include <stdlib.h>
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
            pNode->pRLink = NULL; // 다음 노드를 NULL로 설정

            // 공백 상태의 덱인 경우
            if (isLinkedDequeEmpty(pDeque) == TRUE)
            {
                pDeque->pFrontNode = pNode;
                pDeque->pRearNode = pNode;
            }
            // 공백 상태가 아닌 덱인 경우
            else
            {
                pDeque->pFrontNode->pRLink = pNode;
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

int insertRearLD(LinkedDeque *pDeque, DequeNode element);
DequeNode *deleteFrontLD(LinkedDeque *pDeque);
DequeNode *deleteRearLD(LinkedDeque *pDeque);
DequeNode *peekFrontLD(LinkedDeque *pDeque);
DequeNode *peeRearLD(LinkedDeque *pDeque);
void deleteLinkedQueue(LinkedDeque *pDeque);
int isLinkedDequeFull(LinkedDeque *pDeque);
int isLinkedDequeEmpty(LinkedDeque *pDeuqe);