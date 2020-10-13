#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// 배열 리스트 생성
ArrayList *createArrayList(int maxElementCount)
{
    ArrayList *pReturn = NULL;
    int i = 0;

    if (maxElementCount > 0) // 입력 파라미터의 유효성 점검
    {
        pReturn = (ArrayList *)malloc(sizeof(ArrayList)); // 메모리 할당

        if (pReturn != NULL) // 메모리 할당 점검
        {
            pReturn->maxElementCount = maxElementCount;
            pReturn->currentElementCount = 0;
            pReturn->pElement = NULL;
        }
        else
        {
            printf("Error. Memory Allocation Falied. createArrayList()\n");
            return NULL;
        }
    }
    else
    {
        printf("Error. Max Element Count should be at least more than 0.\n");
        return NULL;
    }

    // 원소 저장하는 배열에 대한 메모리 할당
    pReturn->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);

    if (pReturn->pElement == NULL) // 원소를 저장하는 배열 메모리 할당 및 점검
    {
        printf("Error. Second Memory Allocation Failed. createArrayList() \n");
        free(pReturn);
        return NULL;
    }

    // 할당된 메모리에 대해 0으로 초기화
    memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount);

    return pReturn;
}

// 원소 추가
int addALElement(ArrayList *pList, int position, ArrayListNode element)
{
    int ret = FALSE; // 원소 추가 성공 여부
    int i = 0;

    // 입력 파라미터에 대한 유효성 점검
    if (pList != NULL) // 메모리 NULL 여부
    {
        if (isArrayListFull(pList) != TRUE) // 배열에 새로운 원소 추가 가능 여부
        {
            if (position >= 0 && position <= pList->currentElementCount) // 추가하려는 위치의 인덱스
            {
                // 기존 원소들을 오른쪽으로 한 칸씩 이동시키기
                for (i = pList->currentElementCount - 1; i >= position; i--)
                {
                    pList->pElement[i + 1] = pList->pElement[i];
                }

                // 새로운 원소 추가 (값 대입)
                pList->pElement[position] = element;
                pList->currentElementCount++;
                ret = TRUE;
            }
            else
            {
                printf("Error. Position Index-[%d] Out of Range. addALElement()\n", position);
            }
        }
        else
        {
            printf("Error. List Capacity Exceeded-[%d]/[%d]\n", position, pList->maxElementCount);
        }
    }
    return 0;
}

// 원소 제거
int removeALElement(ArrayList *pList, int position)
{
    int ret = FALSE;
    int i = 0;

    // 입력 파라미터에 대한 유효성 점검
    if (pList != NULL) // 메모리 NULL 여부
    {
        if (position >= 0 && position < pList->currentElementCount) // 제거하려는 위치의 인덱스
        {
            // 기존 원소들을 왼쪽으로 한 칸씩 이동
            for (i = position; i < pList->currentElementCount - 1; i++)
            {
                pList->pElement[i] = pList->pElement[i + 1];
            }

            pList->currentElementCount--;
            ret = TRUE;
        }
        else
        {
            printf("Error. Position Index-[%d] Out of Range. removeALElemet()\n", position);
        }
    }
    return ret;
}

// 리스트 원소 반환
ArrayListNode *getALElement(ArrayList *pList, int position)
{
    ArrayListNode *pReturn = NULL;

    // 입력 파라미터에 대한 유효성 점검
    if (pList != NULL) // 메로리 NULL 여부
    {
        if (position >= 0 && position < getArrayListLength(pList)) // 제거하려는 위치의 인덱스
        {
            pReturn = &(pList->pElement[position]);
        }
        else
        {
            printf("Error. Postion Index-[%d] Out of Range. getALElement()\n", position);
        }
    }
    return pReturn;
}

// 리스트 순회
void displayArrayList(ArrayList *pList)
{
    int i = 0;
    if (pList != NULL)
    {
        printf("Maximum Number of Elements : %d\n", pList->maxElementCount);
        printf("Current Number of Elements : %d\n", pList->currentElementCount);

        // 저장된 원소의 값을 출력
        for (i = 0; i < pList->currentElementCount; i++)
        {
            printf("[%d] - %d\n", i, getALElement(pList, i)->data);
        }

        i = pList->currentElementCount;
        for (; i < pList->maxElementCount; i++)
        {
            printf("[%d] - Empty\n", i);
        }
    }
    else
    {
        printf("ArrayList is NULL\n");
    }
}

int isArrayListFull(ArrayList *pList)
{
    int ret = FALSE;

    if (pList != NULL)
    {
        if (pList->currentElementCount == pList->maxElementCount)
        {
            ret = TRUE;
        }
    }
    return ret;
}

int getArrayListLength(ArrayList *pList)
{
    int ret = 0;

    if (pList != NULL)
    {
        ret = pList->currentElementCount;
    }

    return ret;
}

void deleteArrayList(ArrayList *pList)
{
    int i = 0;
    if (pList != NULL)
    {
        free(pList->pElement); // element 메모리 해제
        free(pList);           // 리스트 메모리 해제
    }
}

// 맨 앞에 원소 추가
int addALElementFirst(ArrayList *pList, int element)
{
    int position = 0;
    ArrayListNode node;
    node.data = element;
    return addALElement(pList, position, node);
}

// 맨 뒤에 원소 추가
int addALElementLast(ArrayList *pList, int element)
{
    int ret = FALSE;
    int position = 0;
    if (pList != NULL)
    {
        ArrayListNode node;
        node.data = element;
        position = getArrayListLength(pList);
        ret = addALElement(pList, position, node);
    }

    return ret;
}
