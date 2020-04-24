#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprLinkedStack.h"

// 스택의 생성
LinkedStack *createLinkedStack()
{
    LinkedStack *pReturn = NULL;
    int i = 0;

    // 메모리 할당
    pReturn = (LinkedStack *)malloc(sizeof(LinkedStack));

    if (pReturn != NULL) // 메모리 할당 점검
    {
        memset(pReturn, 0, sizeof(LinkedStack)); // 메모리 초기화
    }
    else
    {
        printf("Error. Memory Allocation Failed. createLinkedStack()\n");
        return NULL;
    }
    return pReturn;
}

// 푸시
int pushLS(LinkedStack *pStack, StackNode element)
{
    int ret = FALSE;
    StackNode *pNode = NULL;

    if (pStack != NULL)
    {
        pNode = (StackNode *)malloc(sizeof(StackNode)); // 새로운 노드에 대한 메모리 할당

        if (pNode != NULL) // 메모리 점검
        {
            memset(pNode, 0, sizeof(StackNode)); // 노드에 대한 메모리 초기화
            *pNode = element;                    // 노드에 자료의 값 할당
            pNode->pLink = pStack->pTopElement;  // 새로 추가된 노드와 기존 탑 노드 연결
            pStack->pTopElement = pNode;         // 새로 추가된 노드를 탑 노드로 설정

            pStack->currentElementCount++;
            ret = TRUE;
        }
        else
        {
            printf("Error. Memory Allocation Faild. pushLS()\n");
        }
    }
    return ret;
}

// 팝
StackNode *popLS(LinkedStack *pStack)
{
    StackNode *pReturn = NULL;
    if (pStack != NULL)
    {
        if (isLinkedStackEmpty(pStack) == FALSE)
        {
            pReturn = pStack->pTopElement;        // 반환 노드 설정
            pStack->pTopElement = pReturn->pLink; // 탑 노드 변경, 반환 노드의 다음 노드가 탑 노드가 된다
            pReturn->pLink = NULL;                //반환 노드의 다음 노드로 NULL 설정
            pStack->currentElementCount--;
        }
    }
    return pReturn;
}

// 피크
StackNode *peekLS(LinkedStack *pStack)
{
    StackNode *pReturn = NULL;
    if (pStack != NULL)
    {
        if (isLinkedStackEmpty(pStack) == FALSE)
        {
            pReturn = pStack->pTopElement; // 포인터 반환
        }
    }
    return pReturn;
}

void deleteLinkedStack(LinkedStack *pStack)
{
    StackNode *pNode = NULL;
    StackNode *pDelNode = NULL;

    if (pStack != NULL)
    {
        pNode = pStack->pTopElement; // pNode 탑 가리킨다
        while (pNode != NULL)
        {
            pDelNode = pNode;
            pNode = pNode->pLink; // pNode 한칸 이동
            free(pDelNode);       // 메모리 해제
        }
        free(pStack);
    }
}

int isLinkedStackFull(LinkedStack *pStack)
{
    int ret = FALSE;
    return ret;
}

int isLinkedStackEmpty(LinkedStack *pStack)
{
    int ret = FALSE;

    if (pStack != NULL)
    {
        if (pStack->currentElementCount == 0)
        {
            ret = TRUE;
        }
    }
    return ret;
}