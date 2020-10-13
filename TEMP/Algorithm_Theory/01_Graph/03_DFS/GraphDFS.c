#include <stdio.h>
#include <stdlib.h>
#include "GraphLinkedList.h"
#include "LinkedGraph.h"
#include "LinkedStack.h"
#include "GraphDFS.h"

// 스택에 방문 노드 id를 푸시하는 래퍼(wrapper) 함수
int pushLSForDFS(LinkedStack *pStack, int nodeID)
{
    StackNode node = {
        0,
    };
    node.data = nodeID;
    return pushLS(pStack, node);
}

// 깊이 우선 탐색
void traversalDFS(LinkedGraph *pGraph, int startVertexID)
{
    int i = 0;
    int vertextID = 0;
    LinkedStack *pStack = NULL;
    StackNode *pStackNode = NULL;
    ListNode *pListNode = NULL;
    int *pVisited = NULL;

    if (pGraph == NULL)
    {
        return;
    }

    // 스택 생성 및 점검
    pStack = createLinkedStack();
    if (pStack == NULL)
    {
        return;
    }

    // 각 노드별 방문 여부를 저장하기 위한 1차원 배열 생성 및 점검
    pVisited = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
    if (pVisited == NULL)
    {
        printf("Error, Memory allocation failed in traversalDFS()\n");
        return;
    }

    // 방문 여부 초기화
    for (i = 0; i < pGraph->maxVertexCount; i++)
    {
        pVisited[i] = FALSE;
    }

    // 탐색 시작 노드를 방문으로 처리하고, 스택에 푸시
    pVisited[startVertexID] = TRUE;
    pushLSForDFS(pStack, startVertexID);

    // 스택에 더 방문할 노드가 없을 때까지 루프를 돈다
    while (isLinkedStackEmpty(pStack) == FALSE)
    {
        // 스택에서 팝된 노드가 새로운 탐색 노드가 된다
        pStackNode = popLS(pStack);
        if (pStackNode != NULL)
        {
            vertextID = pStackNode->data;
            printf("[%d]-visited\n", vertextID);

            // 탐색 시작 노드의 간선 저장을 위한 1차원 포인터 배열
            pListNode = pGraph->ppAdjEdge[vertextID]->headerNode.pLink;
            // 간선이 저장된 1차원 포인터 배열을 순회하며 노드들을 스택에 푸시
            while (pListNode != NULL)
            {
                int vertexID = pListNode->data.vertexID;
                // 이미 방문한 노드는 푸시하면 안된다
                if (pVisited[vertexID] == FALSE)
                {
                    pVisited[vertexID] = TRUE;      // 방문 표시
                    pushLSForDFS(pStack, vertexID); // 현재 탐색 노드와 인접한 노드를 스택에 푸시
                }

                // 다음으로 이동
                pListNode = pListNode->pLink;
            }
        }
    }

    free(pVisited);
    deleteLinkedStack(pStack);
}
