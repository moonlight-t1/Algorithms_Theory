#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayHeap.h"

// 히프의 생성
ArrayMaxHeap *createArrayMaxHeap(int maxElementCount)
{
    ArrayMaxHeap *pReturn = NULL;
    int i = 0;

    if (maxElementCount > 0) // 최대 원소 개수 점검
    {
        // 히프 구조체 메모리 할당 및 점검
        pReturn = (ArrayMaxHeap *)malloc(sizeof(ArrayMaxHeap));
        if (pReturn != NULL)
        {
            // 히프 구조체 초기화
            pReturn->maxElementCount = maxElementCount;
            pReturn->currentElementCount = 0;

            // 배열 메모리 할당 및 점검
            pReturn->pElement = (HeapNode *)malloc(sizeof(HeapNode) * (maxElementCount + 1));
            if (pReturn->pElement == NULL)
            {
                printf("Error. Second Memory Allocation Failed, createArrayList()\n");
                free(pReturn);
                return NULL;
            }
            // 배열 메모리 초기화
            memset(pReturn->pElement, 0, sizeof(HeapNode) * (maxElementCount + 1));
        }
        else
        {
            printf("Error. Memory Allocation Failed. createArrayList()\n");
        }
    }
    else
    {
        printf("Maximum number of elements should be greater than 0.\n");
    }
    return pReturn;
}

// 히프 삭제
void deleteArrayMaxHeap(ArrayMaxHeap *pHeap)
{
    if (pHeap != NULL)
    {
        if (pHeap != NULL)
        {
            free(pHeap->pElement);
        }
        free(pHeap);
    }
}

// 최대 히프에서의 삽입 연산
void insertMaxHeapAH(ArrayMaxHeap *pHeap, HeapNode element)
{
    int i = 0;

    if (pHeap != NULL)
    {
        // 히프의 크기를 초과하여 저장하는지 점검
        if (pHeap->currentElementCount == pHeap->maxElementCount)
        {
            printf("Error. Heap is full[%d], insertMaxHeapAH()\n", pHeap->maxElementCount);
            return;
        }

        // Step 1
        pHeap->currentElementCount++;   // 현재 노드 갯수를 1 증가 시킨다
        i = pHeap->currentElementCount; // 변수 i는 현재 히프에서의 마지막 노드를 가리킨다

        // Step 2
        // 부모 노드와 키 값 비교와 이동
        while ((i != 1) && (element.key > pHeap->pElement[i / 2].key))
        {
            pHeap->pElement[i] = pHeap->pElement[i / 2];
            i /= 2;
        }
        pHeap->pElement[i] = element;
    }
}

HeapNode *deleteMaxHeapAH(ArrayMaxHeap *pHeap)
{
    HeapNode *pReturn = NULL;
    HeapNode *pTemp = NULL;

    int i = 0;
    int parent = 0, child = 0;

    // 현재 반환 가능한 노드가 있는지 점검
    if (pHeap != NULL && pHeap->currentElementCount > 0)
    {
        // 반환되는 노드에 대한 메모리 할당 및 점검
        pReturn = (HeapNode *)malloc(sizeof(HeapNode));
        if (pReturn == NULL)
        {
            printf("Error. Memory Allocation Failed. deleteMaxHeapAH()\n");
            return NULL;
        }
        // 루트 노드가 반환되는 노드이다.
        *pReturn = pHeap->pElement[1]; // 반환되는 노드의 값으로 기존 루트 노드의 값(value)을 대입

        i = pHeap->currentElementCount; // i - 히프의 제일 마지막 위치 인덱스
        pTemp = &(pHeap->pElement[i]);  // pTemp : 히프의 제일 마지막 노드를 가리킴
        pHeap->currentElementCount--;   // 현재 노드의 개수를 1개 감소

        // 루프가 시작되는 곳은 루트 노드(인덱스 1)와 루트 노드의 왼쪽 자식 노드(인덱스 2)
        parent = 1;
        child = 2;
        // 히프의 제일 마지막 위치에 있는 노드를 만날 때까지 루프
        while (child <= pHeap->currentElementCount)
        {
            // 왼쪽 자식 노드보다 오른쪽 자식 노드의 키 값이 더 크다면
            // 오른쪽 자식 노드가 비교 대상이 되도록 위치 인덱스 child를 수정한다
            if ((child < pHeap->currentElementCount) && pHeap->pElement[child].key < pHeap->pElement[child + 1].key)
            {
                child++;
            }

            // 앞서 설정한 히프의 제일 마지막 노드와 현재 노드의 키 값을 비교
            // 만약, 마지막 노드의 키 값이 현재 노드보다 더 크거나 같다면
            // 루프를 빠져나온다. 바로 이 위치에서 삽입하면 된다.
            if (pTemp->key >= pHeap->pElement[child].key)
            {
                break;
            }

            // 만약 그렇지 않다면 현재의 노드를 부모 노드의 위치로 한 칸 이동시키고
            // 다시 아래 레벨로 이동
            pHeap->pElement[parent] = pHeap->pElement[child];
            parent = child;
            child *= 2;
        } // end-of-while
        pHeap->pElement[parent] = *pTemp;
    }
    return pReturn;
}