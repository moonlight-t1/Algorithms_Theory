#include <stdio.h>
#include <stdlib.h>
#include "GraphLinkedList.h"
#include "LinkedStack.h"
#include "LinkedGraph.h"
#include "GraphArrayHeap.h"
#include "KruskalMST.h"

LinkedGraph *mstKruskal(LinkedGraph *pGraph)
{
    LinkedGraph *pReturn = NULL;
    int i = 0;
    int maxNodeCount = 0;
    int currentNodeCounde = 0;
    int edgeCount = 0;
    int isCycle = 0;
    ArrayMinHeap *pMinHeap = NULL;
    HeapNode *pHeapNode = NULL;

    if (pGraph == NULL)
    {
        printf("Graph is NULL\n");
        return NULL;
    }

    // 입력 파라미터인 pGraph 조사
    maxNodeCount = getMaxVertexCountLG(pGraph);   // pGraph의 최대 노드 개수
    currentNodeCounde = getVertexCountLG(pGraph); // pGraph의 노드 개수
    edgeCount = getEdgeCountLG(pGraph);           // pGraph의 간선 개수

    // 최소 비용 신장 트리 생성 및 메모리 점검
    pReturn = createLinkedGraph(maxNodeCount); // pGraph의 최대 노드 개수를 이용해 생성

    if (pReturn == NULL)
    {
        return NULL;
    }

    // 간선들의 가중치를 오름차순으로 정렬 및 결과가 점검
    pMinHeap = orderEdges(pGraph); // 최소 히프 이용

    if (pMinHeap == NULL)
    {
        return NULL;
    }

    // (최대) 간선 개수만큼 루프를 돈다
    for (i = 0; i < edgeCount; i++)
    {
        // 가중치가 가장 작은 간선을 '최소 히프'에서 추출한다.
        pHeapNode = deleteMinHeapAH(pMinHeap);

        if (pHeapNode != NULL)
        {
            // 순환이 발생하는지 점검한다.
            isCycle = checkCycle(pReturn, pHeapNode->fromVertexID,
                                 pHeapNode->toVertexID);

            // 신장 트리에 간선과 노드 추가
            if (isCycle == FALSE)
            {
                // 추가되는 간선의 두 노드를 '신장 트리'에 추가한다.
                if (pReturn->pVertex[pHeapNode->fromVertexID] != USED)
                {
                    addVertexLG(pReturn, pHeapNode->fromVertexID);
                }
                if (pReturn->pVertex[pHeapNode->toVertexID] != USED)
                {
                    addVertexLG(pReturn, pHeapNode->toVertexID);
                }

                // 간선을 추가한다
                addEdgewithWeightLG(pReturn, pHeapNode->fromVertexID,
                                    pHeapNode->toVertexID, pHeapNode->key);

                printf("[%d], Minimum Weight: (%d,%d)->%d\n",
                       i, pHeapNode->fromVertexID, pHeapNode->toVertexID,
                       pHeapNode->key);
            }
            free(pHeapNode);

            // 신장 트리의 노드와 그래프의 노드 개수가 동일하면 종료한다
            if (getVertexCountLG(pReturn) == currentNodeCounde)
            {
                break;
            }
        }
    }

    return pReturn;
}

ArrayMinHeap *orderEdges(LinkedGraph *pGraph)
{
    int i = 0;
    int edgeCount = 0;
    ArrayMinHeap *pReturn = NULL;
    ListNode *pListNode = NULL;
    LinkedList *pEdgeList = NULL;

    if (pGraph == NULL)
    {
        printf("Graph is NULL\n");
        return pReturn;
    }

    edgeCount = getEdgeCountLG(pGraph);
    if (edgeCount == 0)
    {
        printf("Error, Number of edge is 0.\n");
        return pReturn;
    }

    pReturn = createArrayMinHeap(edgeCount);
    if (pReturn == NULL)
    {
        return pReturn;
    }

    for (i = 0; i < pGraph->maxVertexCount; i++)
    {
        if (pGraph->pVertex[i] == USED)
        {
            pEdgeList = pGraph->ppAdjEdge[i];
            pListNode = pEdgeList->headerNode.pLink;
            while (pListNode != NULL)
            {
                int vertexID = pListNode->data.vertexID;
                int weight = pListNode->data.weight;

                // 무방향 그래프라면, 동일한 간선이 2개 리턴되므로,
                // 시작 노드 id가 종료 노드 id보다 작은 경우만 리턴되도록 한다.
                // 즉, 간선 1개만 리턴되도록 한다.
                if (pGraph->graphType == GRAPH_DIRECTED || (pGraph->graphType == GRAPH_UNDIRECTED && i < vertexID))
                {
                    HeapNode heapNode = {
                        0,
                    };
                    heapNode.fromVertexID = i;
                    heapNode.toVertexID = vertexID;
                    heapNode.key = weight;
                    insertMinHeapAH(pReturn, heapNode);
                }

                pListNode = pListNode->pLink;
            }
        }
    }

    return pReturn;
}

int pushLSForDFS(LinkedStack *pStack, int nodeID)
{
    StackNode node = {
        0,
    };
    node.data = nodeID;
    return pushLS(pStack, node);
}

// 간선 추가로 인해 순환이 발생하는 지 검사.
// 기존에 경로가 있었다면, 순환이 발생한다.
// 기존의 깊이우선탐색(DFS)를 사용.
int checkCycle(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    int pReturn = FALSE;

    int i = 0;
    int vertextID = 0;
    LinkedStack *pStack = NULL;
    StackNode *pStackNode = NULL;
    ListNode *pListNode = NULL;
    int *pVisited = NULL;

    if (pGraph == NULL)
    {
        return pReturn;
    }

    pStack = createLinkedStack();
    if (pStack == NULL)
    {
        return pReturn;
    }

    pVisited = (int *)malloc(sizeof(int) * pGraph->maxVertexCount);
    if (pVisited == NULL)
    {
        printf("Error, malloc() in traversalDFS()\n");
        deleteLinkedStack(pStack);
        return pReturn;
    }

    // 초기화.
    for (i = 0; i < pGraph->maxVertexCount; i++)
    {
        pVisited[i] = FALSE;
    }

    pVisited[fromVertexID] = TRUE;
    pushLSForDFS(pStack, fromVertexID);

    while (isLinkedStackEmpty(pStack) == FALSE)
    {
        pStackNode = popLS(pStack);
        if (pStackNode != NULL)
        {
            vertextID = pStackNode->data;
            if (vertextID == toVertexID)
            {
                printf("(%d,%d)-The path already exists.\n",
                       fromVertexID, toVertexID);
                pReturn = TRUE;
                break;
            }

            pListNode = pGraph->ppAdjEdge[vertextID]->headerNode.pLink;
            while (pListNode != NULL)
            {
                int vertexID = pListNode->data.vertexID;
                if (pVisited[vertexID] == FALSE)
                {
                    pVisited[vertexID] = TRUE;
                    pushLSForDFS(pStack, vertexID);
                }

                pListNode = pListNode->pLink;
            }
        }
    }

    free(pVisited);
    deleteLinkedStack(pStack);

    return pReturn;
}
