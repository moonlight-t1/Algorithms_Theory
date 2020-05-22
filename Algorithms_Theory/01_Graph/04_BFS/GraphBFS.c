#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "linkedqueue.h"
#include "GraphBFS.h"

// 큐에 방문 노드 id를 인큐하는 함수 래퍼(Wrapper)
int enqueueLQForBFS(LinkedQueue *pQueue, int nodeID)
{
    QueueNode node = {
        0,
    };
    node.data = nodeID;
    return enqueueLQ(pQueue, node);
}

// BFS 그래프 탐색
void traversalBFS(LinkedGraph *pGraph, int startVertexID)
{
    int i = 0;
    int vertextID = 0;
    QueueNode *pTop = NULL;
    LinkedQueue *pQueue = NULL;
    QueueNode *pQueueNode = NULL;
    ListNode *pListNode = NULL;
    int *pVisited = NULL;

    if (pGraph == NULL)
    {
        return;
    }

    // 큐 생성 및 점검
    pQueue = createLinkedQueue();
    if (pQueue == NULL)
    {
        return;
    }

    // 노드별 방문 여부를 저장하기 위한 1차원 배열 생성 및 점검
    pVisited = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
    if (pVisited == NULL)
    {
        printf("Error, Memory allocation failed in traversalDFS()\n");
        return;
    }

    // 방문 여부 초기화(FALSE)
    for (i = 0; i < pGraph->maxVertexCount; i++)
    {
        pVisited[i] = FALSE;
    }

    // 탐색 시작 노드를 방문으로 처리하고, 큐이 인큐
    pVisited[startVertexID] = TRUE;
    enqueueLQForBFS(pQueue, startVertexID);

    // 큐에 더 이상 방문할 노드가 없을 때까지 루프를 돈다
    while (isLinkedQueueEmpty(pQueue) == FALSE)
    {
        // 디큐를 하여 탐색 시작 노드 지정
        pQueueNode = dequeueLQ(pQueue);
        if (pQueueNode != NULL)
        {
            vertextID = pQueueNode->data;
            printf("[%d]-visited\n", vertextID);

            // 현재 선택된 노드(vertextID)와 연결된 노드에 대한 순회 실시
            pListNode = pGraph->ppAdjEdge[vertextID]->headerNode.pLink;
            while (pListNode != NULL)
            {
                int vertexID = pListNode->data.vertexID;

                if (pVisited[vertexID] == FALSE) // 기존에 방문한 노드인지 점검
                {
                    pVisited[vertexID] = TRUE;         // 방문 처리
                    enqueueLQForBFS(pQueue, vertexID); // 큐에 인큐
                }

                pListNode = pListNode->pLink;
            }
        }
    }

    free(pVisited);
    deleteLinkedQueue(pQueue);
}
