#include <stdio.h>
#include <stdlib.h>
#include "ArrayHeap.h"

void printArray(int value[], int count);

void heapSort(int value[], int count)
{
    int i = 0;
    ArrayMinHeap *pHeap = NULL;

    // 최소 히프를 생성하고 이를 검증한다.
    pHeap = createArrayMinHeap(8);
    if (pHeap != NULL)
    {
        HeapNode node;

        // 입력받은 자료를 최소 히프에 삽입한다
        for (i = 0; i < count; i++)
        {
            node.key = value[i];
            insertMinHeapAH(pHeap, node);
        }

        // 입력 자료의 개수만큼 최소 히프에서 삭제 연산을 실행한다.
        for (i = 0; i < count; i++)
        {
            HeapNode *pNode = deleteMinHeapAH(pHeap);
            if (pNode != NULL)
            {
                value[i] = pNode->key; // 최소 히프에서 삭제하여 반환받은 자료를 저장
                free(pNode);           // 최소 히프에서 반환받은 노드를 메모리 해제
            }
        }

        // 생성한 최소 히프를 메모리 해제
        deleteArrayMinHeap(pHeap);
    }
    else
    {
        printf("Error, createArrayMinHeap() in heapSort()\n");
        return;
    }
}

int main(int argc, char *argv[])
{
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before Sorted\n");
    printArray(values, 8);

    heapSort(values, 8);

    printf("After Sorted\n");
    printArray(values, 8);

    return 0;
}

void printArray(int value[], int count)
{
    int i = 0;
    for (i = 0; i < count; i++)
    {
        printf("%d ", value[i]);
    }
    printf("\n");
}