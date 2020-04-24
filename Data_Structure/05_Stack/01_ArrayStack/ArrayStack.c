#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayStack.h"

// 스택의 생성
ArrayStack *createArrayStack(int size)
{
    ArrayStack *pReturn = NULL;
    int i = 0;

    if (size > 0) // 입력 파라미터 유효성 점검
    {
        pReturn = (ArrayStack *)malloc(sizeof(ArrayStack)); // 메모리 할당
        if (pReturn != NULL)                                // 메모리 할당 점검
        {
            memset(pReturn, 0, sizeof(ArrayStack)); // 메모리 초기화
            pReturn->maxElementCount = size;
        }
        else
        {
            printf("Error. Memory Allocation Failed. createArrayStack()\n");
            return NULL;
        }

        // 원소 저장하는 배열 메모리 할당 및 점검
        pReturn->pElement = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));

        if (pReturn->pElement != NULL)
        {
            memset(pReturn->pElement, 0, sizeof(ArrayStackNode) * size);
        }
        else
        {
            printf("Error. Second Memory Allocation Failed. createArrayStack()\n");
            free(pReturn);
            return NULL;
        }
    }
    else
    {
        printf("Error. Stack size should larger than 0.\n");
        return NULL;
    }

    return pReturn;
}

// 푸시 연산
int pushAS(ArrayStack *pStack, ArrayStackNode element)
{
    int ret = FALSE;
    int i = 0;

    // 입력 파라미터에 대한 유효성 점검
    if (pStack != NULL) // 메모리 NULL 여부
    {
        if (isArrayStackFull(pStack) == FALSE) // 배열에 새로운 원소 추가 가능 여부
        {
            pStack->pElement[pStack->currentElementCount] = element; // 배열에 새로운 우너소 추가
            pStack->currentElementCount++;                           // 탑의 위치 변경
            ret = TRUE;
        }
        else
        {
            printf("Error. The stack is full. pushAS()\n");
        }
    }
}

// 팝
ArrayStackNode *popAS(ArrayStack *pStack)
{
    ArrayStackNode *pReturn = NULL;

    // 입력 파라미터에 대한 유혀성 점검
    if (pStack != NULL) // 메모리 NULL 여부
    {
        if (isArrayStackEmpty(pStack) == FALSE) // 공백(empty) 스택인지 여부 점검
        {
            // 반환 노드 메모리 할당 및 점검
            pReturn = (ArrayStackNode *)malloc(sizeof(ArrayStackNode));
            if (pReturn != NULL)
            {
                *pReturn = pStack->pElement[pStack->currentElementCount - 1]; // 노드 내용 복사
                pStack->currentElementCount--;                                // 탑 변경
            }
            else
            {
                printf("Error. Memory Allocation Failed. popAS()\n");
            }
        }
    }
    return pReturn;
}

// 피크
ArrayStackNode *peekAS(ArrayStack *pStack)
{
    ArrayStackNode *pReturn = NULL;

    // 입력 파라미터에 대한 유효성 점검
    if (pStack != NULL) // 메모리 NULL 여부
    {
        if (isArrayStackEmpty(pStack) == FALSE) // 공백(empty) 스택인지 여부 점검
        {
            pReturn = &(pStack->pElement[pStack->currentElementCount - 1]);
        }
    }
    return pReturn;
}

void deleteArrayStack(ArrayStack *pStack)
{
    if (pStack != NULL)
    {
        if (pStack->pElement != NULL)
        {
            free(pStack->pElement); // 내부 변수 메모리 해제
        }
        free(pStack); // 스택 메모리 해제
    }
}

int isArrayStackFull(ArrayStack *pStack)
{
    int ret = FALSE;

    if (pStack != NULL)
    {
        if (pStack->currentElementCount == pStack->maxElementCount)
        {
            ret = TRUE;
        }
    }

    return ret;
}

int isArrayStackEmpty(ArrayStack *pStack)
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