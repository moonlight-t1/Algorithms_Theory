#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "graphsp.h"

// Dijkstra 알고리즘
int *shortestPathDijkstra(LinkedGraph *pGraph, int startVertexID)
{
    int *pReturn = NULL;
    int *pSelected = NULL;
    int nodeCount = 0, maxNodeCount = 0;
    int i = 0, j = 0, weight = 0;
    int vertexID = 0, y_w = 0, y_v = 0;
    ListNode *pListNode = NULL;
    LinkedList *pEdgeList = NULL;

    if (pGraph == NULL)
    {
        printf("Graph is NULL\n");
        return pReturn;
    }

    // 입력 파라미터 pGraph 조사
    maxNodeCount = getMaxVertexCountLG(pGraph); // pGraph 최대 노드 개수
    nodeCount = getVertexCountLG(pGraph);       // pGraph 노드 개수

    pReturn = (int *)malloc(sizeof(int) * maxNodeCount);   // 반환 값(최단 거리) 저장을 위한 메모리 할당
    pSelected = (int *)malloc(sizeof(int) * maxNodeCount); // 집합 S 저장을 위한 메모리 할당

    if (pReturn == NULL || pSelected == NULL)
    {
        if (pReturn != NULL)
            free(pReturn);
        printf("Error. Memory allocation has failed in shortestPathDijkstra()\n");
        return NULL;
    }

    // Step 0. 초기화
    for (i = 0; i < maxNodeCount; i++)
    {
        if (i == startVertexID)
        {
            pReturn[i] = 0; // 시작 노드의 거리 설정. 거리 0
        }
        else
        {
            // 시작 노드와 연결된 노드들에 대해서 초기 거리 설정
            if (pGraph->pVertex[i] == USED)
            {
                pSelected[i] = TRUE;
                // 만약 시작 노드와 연결되었다면 해당 간선의 가중치로 설정된다
                // 만약 시작 노드와 연결된 노드가 아니면 MAX_INT로 설정된다
                pReturn[i] = getEdgeWeight(pGraph, startVertexID, i);
            }
            else
            {
                pSelected[i] = FALSE;
                pReturn[i] = MAX_INT;
            }
        }
    }

    for (i = 0; i < maxNodeCount; i++)
    {
        printf("(%d,%d)->%d\n", startVertexID, i, pReturn[i]);
    }

    // 노드 개수보다 1 적게 루프를 돈다
    for (i = 0; i < nodeCount - 1; i++)
    {
        printf("[%d] - Iteration\n", i + 1);

        // Step-1.
        // 집합 S중 최단 거리를 가지는 정점(vertexID)을 선택
        vertexID = getMinDistance(pReturn, pSelected, maxNodeCount);
        pSelected[vertexID] = FALSE;

        // 선택된 정점(vertexID)에 인접한 정점들에 대해 거리 변경 조건 점검.
        pEdgeList = pGraph->ppAdjEdge[vertexID]; // 선택된 노드의 '연결 리스트'를 포인터 변수 pEdgeList에 저장
        pListNode = pEdgeList->headerNode.pLink;

        // 루프를 돌면서 현재 선택된 노드와 연결된 모든 노드에 대해서 최단 거리 변경을 실시
        while (pListNode != NULL)
        {
            int toVertexID = pListNode->data.vertexID;
            int weight = pListNode->data.weight;

            // 기존 최단 거리(y_w)와 새로운 최단 거리(y_v + weight)를 비교
            // 새로운 최단 거리가 더 짧다면 기존 최단 거리를 변경
            y_v = pReturn[vertexID];
            y_w = pReturn[toVertexID];
            if (y_v + weight < y_w)
            {
                pReturn[toVertexID] = y_v + weight;
            }
            pListNode = pListNode->pLink;
        }

        for (j = 0; j < maxNodeCount; j++)
        {
            printf("\t(%d, %d) -> %d\n", startVertexID, j, pReturn[j]);
        }
    }

    free(pSelected);

    return pReturn;
}

// 그래프 노드 집합 중 최단 거리를 가지는 노드를 반환하는 함수
int getMinDistance(int *distance, int *pSelected, int maxNodeCount)
{
    int pReturn = 0;
    int min_distance = MAX_INT;
    int i = 0;

    for (i = 0; i < maxNodeCount; i++)
    {
        if (pSelected[i] == TRUE && distance[i] < min_distance)
        {
            min_distance = distance[i];
            pReturn = i;
        }
    }

    return pReturn;
}

// 그래프 간선의 가중치를 반환하는 함수
int getEdgeWeight(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    int pReturn = MAX_INT;
    int position = 0;
    LinkedList *pEdgeList = NULL;
    ListNode *pListNode = NULL;

    if (pGraph != NULL)
    {
        pEdgeList = pGraph->ppAdjEdge[fromVertexID];
        if (pEdgeList != NULL)
        {
            position = findGraphNodePosition(pEdgeList, toVertexID);
            if (position >= 0)
            {
                pListNode = getLLElement(pEdgeList, position);
                if (pListNode != NULL)
                {
                    pReturn = pListNode->data.weight;
                }
            }
        }
    }

    return pReturn;
}

// Floyd 알고리즘
int **shortestPathFloyd(LinkedGraph *pGraph)
{
    int **pReturn = NULL;
    int r = 0, s = 0, v = 0;
    int weight = 0;
    int maxNodeCount = 0;

    if (pGraph == NULL)
    {
        printf("Graph is NULL\n");
        return NULL;
    }

    // 입력 파라미터인 그래프 pGraph의 최대 노드 개수 조사
    maxNodeCount = getMaxVertexCountLG(pGraph);
    printf("The number of nodes: %d\n", maxNodeCount);

    // 반환 값(최단 거리) 저장을 위한 메모리 할당 및 점검(2차원 배열)
    pReturn = (int **)malloc(sizeof(int *) * maxNodeCount);
    if (pReturn == NULL)
    {
        printf("Error. Memory Allocation Failed.(1) in shortestPathFloyd()\n");
        return NULL;
    }

    // 반환 값(최단 거리) 저장. 루프를 돌면서 각각 1차원 배열 생성
    for (r = 0; r < maxNodeCount; r++)
    {
        pReturn[r] = (int *)malloc(sizeof(int) * maxNodeCount);
        if (pReturn[r] == NULL)
        {
            for (s = 0; s < r - 1; s++)
            {
                if (pReturn[s] != NULL)
                    free(pReturn[s]);
            }
            if (pReturn != NULL)
                free(pReturn);
            printf("Error. Memory Allocation Failed.(2) in shortestPathFloyd()\n");
            return NULL;
        }
    }

    // 초기화. 배열 pReturn의 초기화
    // 각 노드 사이의 거리를 초기화. 두 노드를 연결시켜주는 간선의 가중치 값을 이용
    for (r = 0; r < maxNodeCount; r++)
    {
        for (s = 0; s < maxNodeCount; s++)
        {
            if (r == s)
            {
                pReturn[r][s] = 0;
            }
            else
            {
                pReturn[r][s] = getEdgeWeight(pGraph, r, s);
            }
        }
    }
    printMatrix(pReturn, maxNodeCount);

    // Step 1. 삼중 Loop (최단 거리 변경을 수행)
    for (v = 0; v < maxNodeCount; v++)
    {
        for (r = 0; r < maxNodeCount; r++)
        {
            for (s = 0; s < maxNodeCount; s++)
            {
                if (pReturn[r][v] + pReturn[v][s] < pReturn[r][s])
                {
                    pReturn[r][s] = pReturn[r][v] + pReturn[v][s];
                }
            }
        }
        printf("[%d] - Loop\n", v + 1);
        printMatrix(pReturn, maxNodeCount);
    }

    return pReturn;
}

void printMatrix(int **A, int maxNodeCount)
{
    int r = 0;
    int s = 0;

    for (s = 0; s < maxNodeCount; s++)
    {
        printf("\t%d", s);
    }
    printf("\n");

    for (r = 0; r < maxNodeCount; r++)
    {
        printf("%d:\t", r);
        for (s = 0; s < maxNodeCount; s++)
        {
            printf("%d\t", A[r][s]);
        }
        printf("\n");
    }
}