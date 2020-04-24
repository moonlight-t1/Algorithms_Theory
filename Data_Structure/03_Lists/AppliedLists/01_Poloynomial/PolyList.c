#include <stdio.h>
#include <stdlib.h>
#include "PolyList.h"

// 다항식의 항 추가
int addPolyNodeLast(LinkedList *pList, float coef, int degree)
{
    int ret = FALSE, i = 0;

    ListNode node = {
        0,
    };
    node.coef = coef;
    node.degree = degree;

    if (pList != NULL)
    {
        int length = getLinkedListLength(pList);
        ret = AddLLElement(pList, length, node); // 연결 리스트 pList의 가장 마지막 노드로 추가
    }
    return ret;
}

// 다항식의 항 연산
LinkedList *PolyAdd(LinkedList *pListA, LinkedList *pListB)
{
    LinkedList *pReturn = NULL;
    ListNode *pNodeA = NULL, *pNodeB = NULL;
    float coefSum = 0;

    if (pListA != NULL && pListB != NULL)
    {
        pReturn = createLinkedList();
        if (pReturn == NULL)
        {
            printf("Memory Allocation Failed. polyAdd()\n");
            return NULL;
        }
        // 각각 다항식 A, B의 첫번째 노드를 가리킨다
        pNodeA = pListA->headerNode.pLink;
        pNodeB = pListB->headerNode.pLink;

        // 다항식 A 또는 다항식 B의 마지막 노드까지 이동하면 루프를 빠져나온다
        while (pNodeA != NULL && pNodeB != NULL)
        {
            int degreeA = pNodeA->degree;
            int degreeB = pNodeB->degree;

            // A의 차수 > B의 차수
            if (degreeA > degreeB)
            {
                coefSum = pNodeA->coef;
                addPolyNodeLast(pReturn, coefSum, degreeA); // 다항식 A의 항을 이용하여 결과 다항식에 새로운 항을 추가
                pNodeA = pNodeA->pLink;                     // 다항식 A의 다음 항으로 이동
            }

            // A의 차수 == B의 차수
            else if (degreeA == degreeB)
            {
                coefSum = pNodeA->coef + pNodeB->coef;
                addPolyNodeLast(pReturn, coefSum, degreeA); // 다항식 A의 항을 이용하여 결과 다항식에 새로운 항을 추가
                pNodeA = pNodeA->pLink;                     // 다항식 A와 B 모두 다음항으로 이동
                pNodeB = pNodeB->pLink;
            }

            // A의 차수 < B의 차수
            else
            {
                coefSum = pNodeB->coef;
                addPolyNodeLast(pReturn, coefSum, degreeB); // 다항식 B의 항을 이용하여 결과 다항식에 새로운 항을 추가
                pNodeB = pNodeB->pLink;                     // 다항식 B의 다음 항으로 이동
            }
        }

        // 다항식 A에 남은 항이 있다면 남은 항으로 결과 다항식에 새로운 항을 추가
        while (pNodeA != NULL)
        {
            coefSum = pNodeA->coef;
            addPolyNodeLast(pReturn, coefSum, pNodeA->degree);
            pNodeA = pNodeA->pLink;
        }

        // 다항식 B에 남은 항이 있다면 남은 항으로 결과 다항식에 새로운 항을 추가
        while (pNodeB != NULL)
        {
            coefSum = pNodeB->coef;
            addPolyNodeLast(pReturn, coefSum, pNodeB->degree);
            pNodeB = pNodeB->pLink;
        }
    }
    else
    {
        printf("Error. NULL poloynomial is passed. polyAdd()\n");
    }
    return pReturn;
}

void displayPolyList(LinkedList *pList)
{
    int i = 0;
    if (pList != NULL)
    {
        for (i = 0; i < pList->currentElementCount; i++)
        {
            ListNode *pNode = getLLElement(pList, i);
            if (pNode != NULL)
            {
                printf("%4.1fx^%d", pNode->coef, pNode->degree);

                if (i == pList->currentElementCount - 1)
                {
                    printf("\n");
                }
                else
                {
                    printf(" + ");
                }
            }
        }
    }
    else
    {
        printf("It is an empty polynomial.\n");
    }
}