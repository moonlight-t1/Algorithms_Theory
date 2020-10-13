#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GraphLinkedList.h"
#include "LinkedGraph.h"

// 그래프 생성
LinkedGraph *createLinkedGraph(int maxVertexCount)
{
    int i = 0, j = 0;
    LinkedGraph *pReturn = NULL;

    // 최대 노드 개수는 0보다 커야 하는 조건을 검증
    if (maxVertexCount > 0)
    {
        // 그래프 구조체를 할당하고 이를 검증
        pReturn = (LinkedGraph *)malloc(sizeof(LinkedGraph));
        if (pReturn == NULL)
        {
            printf("Error. Memory Allocation Failed(1), in createLinkedGraph()\n");
            return NULL;
        }

        // 초기화 실시
        pReturn->graphType = GRAPH_UNDIRECTED;    // 그래프 종류 무방향 그래프
        pReturn->maxVertexCount = maxVertexCount; // 최대 노드 개수
        pReturn->currentEdgeCount = 0;            // 간선 개수 0
        pReturn->currentVertexCount = 0;          // 노드 개수 0
    }
    else
    {
        printf("Error. Maximum number of nodes should be larger than 0.\n");
        return NULL;
    }

    // 노드 사용 여부를 저장하는 배열 pVertex의 메모리를 할당하고 이를 검증
    pReturn->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
    if (pReturn->pVertex == NULL)
    {
        printf("Error. Memory Allocation Failed(2), in createArrayGraph()\n");
        if (pReturn != NULL)
            free(pReturn);
        return NULL;
    }
    memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);

    // 간선 저장을 휘한 '연결 리스트'들의 1차원 배열을 위한 메모리를 할당하고 메모리 검증
    pReturn->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
    if (pReturn->ppAdjEdge == NULL)
    {
        printf("Error. Memory Allocation Failed(3), in createLinkedGraph()\n");
        if (pReturn->pVertex != NULL)
            free(pReturn->pVertex);
        if (pReturn != NULL)
            free(pReturn);
        return NULL;
    }

    // 최대 노드 개수(maxVertexCount)만큼 루프를 돌면서,
    // 각 시작 노드마다 연결 리스트에 대한 메모리를 할당하고 메모리 검증
    for (i = 0; i < maxVertexCount; i++)
    {
        pReturn->ppAdjEdge[i] = createLinkedList();
        if (pReturn->ppAdjEdge[i] == NULL)
        {
            printf("Error. Memory Allocation Failed(4), in createLinkedGraph()\n");
            for (j = 0; j < i - 1; j++)
            {
                if (pReturn->ppAdjEdge[j] != NULL)
                    free(pReturn->ppAdjEdge[j]);
            }
            if (pReturn->ppAdjEdge != NULL)
                free(pReturn->ppAdjEdge);
            if (pReturn->pVertex != NULL)
                free(pReturn->pVertex);
            if (pReturn != NULL)
                free(pReturn);
            return NULL;
        }
    }

    return pReturn;
}

// 방향 그래프 생성
LinkedGraph *createLinkedDirectedGraph(int maxVertexCount)
{
    LinkedGraph *pReturn = NULL;

    pReturn = createLinkedGraph(maxVertexCount);
    if (pReturn != NULL)
    {
        pReturn->graphType = GRAPH_DIRECTED; // 방향 그래프의 타입 설정
    }

    return pReturn;
}

// 노드 추가
int addVertexLG(LinkedGraph *pGraph, int vertexID)
{
    int ret = SUCCESS;

    if (pGraph != NULL)
    {
        // 노드의 id가 유효한 범위인지 추가하려는 노드가 이미 존재하는 노드인지 점검
        if (vertexID < pGraph->maxVertexCount)
        {
            if (pGraph->pVertex[vertexID] == NOT_USED)
            {
                // 추가하려는 노드의 정보 변경
                pGraph->pVertex[vertexID] = USED; // 노드의 상태 'USED'
                pGraph->currentVertexCount++;     // 현재 사용되는 노드의 개수 1 증가
            }
            else
            {
                printf("Error. Node ID(1) [%d],in addVertexLG()\n",
                       vertexID);
                ret = FAIL;
            }
        }
        else
        {
            printf("Error. Node ID(2) [%d], in addVertexLG()\n",
                   vertexID, pGraph->maxVertexCount);
            ret = FAIL;
        }
    }

    return ret;
}

// 간선 추가 (가중치 1)
int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    return addEdgewithWeightLG(pGraph, fromVertexID, toVertexID, USED);
}

// 간선 정보를 해당 연결 리스트에 추가
int addLLElementForVertex(LinkedList *pList, int position, GraphVertex vertex)
{
    ListNode node = {
        0,
    };
    node.data = vertex;
    return addLLElement(pList, position, node);
}

// 가중치 간선 추가
int addEdgewithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight)
{
    int ret = SUCCESS;
    GraphVertex toNode = {
        0,
    };

    if (pGraph != NULL)
    {
        // 시작 노드 유효성 점검
        if (checkVertexValid(pGraph, fromVertexID) != SUCCESS)
        {
            ret = FAIL;
            return ret;
        }
        // 종료 노드 유효성 점검
        if (checkVertexValid(pGraph, toVertexID) != SUCCESS)
        {
            ret = FAIL;
            return ret;
        }

        // 추가되는 노드 정보 저장
        toNode.vertexID = toVertexID;
        toNode.weight = weight;
        addLLElementForVertex(pGraph->ppAdjEdge[fromVertexID], 0, toNode);
        pGraph->currentEdgeCount++;

        // 무방향 그래프의 대칭성(Symmetry) 처리.
        // 방향 그래프라면 필요없음.
        if (pGraph->graphType == GRAPH_UNDIRECTED)
        {
            GraphVertex fromNode;
            fromNode.vertexID = fromVertexID;
            fromNode.weight = weight;
            addLLElementForVertex(pGraph->ppAdjEdge[toVertexID], 0, fromNode);
            pGraph->currentEdgeCount++;
        }
    }

    return ret;
}

// 노드 유효성 검사
int checkVertexValid(LinkedGraph *pGraph, int vertexID)
{
    int ret = SUCCESS;

    if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED)
    {
        printf("Error. Node ID[%d]\n", vertexID);
        ret = FAIL;
    }

    return ret;
}

// 노드 제거
int removeVertexLG(LinkedGraph *pGraph, int vertexID)
{
    int ret = SUCCESS;
    int i = 0;

    if (pGraph != NULL)
    {
        // 유효한 노드인지 점검
        if (checkVertexValid(pGraph, vertexID) != SUCCESS)
        {
            ret = FAIL;
            return ret;
        }

        // 제거하려는 노드에 부속된 간선 정보를 먼저 제거
        for (i = 0; i < pGraph->maxVertexCount; i++)
        {
            removeEdgeLG(pGraph, vertexID, i);
            removeEdgeLG(pGraph, i, vertexID);
        }
        // 노드 정보 초기화
        pGraph->pVertex[vertexID] = NOT_USED;
    }

    return ret;
}

// 간선 제거
int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID)
{
    int ret = SUCCESS;

    if (pGraph != NULL)
    {
        // 시작 노드가 유효한 노드인지 점검
        if (checkVertexValid(pGraph, fromVertexID) != SUCCESS)
        {
            ret = FAIL;
            return ret;
        }
        // 종료 노드가 유효한 노드인지 점검
        if (checkVertexValid(pGraph, toVertexID) != SUCCESS)
        {
            ret = FAIL;
            return ret;
        }
        // 실제 간선을 제거
        deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);

        // 무방향 그래프의 대칭성(Symmetry) 처리.
        // 방향 그래프라면 필요없음.
        if (pGraph->graphType == GRAPH_UNDIRECTED)
        {
            deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
        }
    }

    return ret;
}

// 연결 리스트의 노드 삭제
void deleteGraphNode(LinkedList *pList, int delVertexID)
{
    int i = 0, position = 0;
    ListNode *pNode = NULL;

    // 연결 리스트에서의 저장된 위치 인덱스를 찾고 연결 리스트에서 실제 삭제
    position = findGraphNodePosition(pList, delVertexID);
    if (position >= 0)
    {
        removeLLElement(pList, position);
    }
}

// 삭제할 노드를 찾는 함수
int findGraphNodePosition(LinkedList *pList, int vertexID)
{
    int i = 0, position = 0;
    ListNode *pNode = NULL;

    if (pList != NULL)
    {
        // 연결 리스트에서 저장된 각 노드 정보를 루프를 돌면서 확인한다.
        // 즉, 종료 노드 id vertexID에 해당하는 간선이 있는지 점검한다
        pNode = pList->headerNode.pLink;
        while (pNode != NULL)
        {
            if (pNode->data.vertexID == vertexID)
            {
                return position;
            }

            pNode = pNode->pLink;
            position++;
        }
    }

    return -1;
}

int getEdgeCountLG(LinkedGraph *pGraph)
{
    int ret = 0;

    if (pGraph != NULL)
    {
        ret = pGraph->currentEdgeCount;
    }

    return ret;
}

int getVertexCountLG(LinkedGraph *pGraph)
{
    int ret = 0;

    if (pGraph != NULL)
    {
        ret = pGraph->currentVertexCount;
    }

    return ret;
}

int getMaxVertexCountLG(LinkedGraph *pGraph)
{
    int ret = 0;

    if (pGraph != NULL)
    {
        ret = pGraph->maxVertexCount;
    }

    return ret;
}

int getGraphTypeLG(LinkedGraph *pGraph)
{
    int ret = 0;

    if (pGraph != NULL)
    {
        ret = pGraph->graphType;
    }

    return ret;
}

void displayLinkedGraph(LinkedGraph *pGraph)
{
    int i = 0;
    int j = 0;
    int position = 0;
    ListNode *pNode = NULL;

    if (pGraph != NULL)
    {
        for (i = 0; i < pGraph->maxVertexCount; i++)
        {
            for (j = 0; j < pGraph->maxVertexCount; j++)
            {
                position = findGraphNodePosition(pGraph->ppAdjEdge[i], j);

                if (position >= 0)
                {
                    pNode = getLLElement(pGraph->ppAdjEdge[i], position);
                    printf("%d ", pNode->data.weight);
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
}

void deleteLinkedGraph(LinkedGraph *pGraph)
{
    int i = 0;

    if (pGraph != NULL)
    {
        for (i = 0; i < pGraph->maxVertexCount; i++)
        {
            deleteLinkedList(pGraph->ppAdjEdge[i]);
        }
        if (pGraph->ppAdjEdge != NULL)
            free(pGraph->ppAdjEdge);
        if (pGraph->pVertex != NULL)
            free(pGraph->pVertex);
        free(pGraph);
    }
}

int isEmptyLG(LinkedGraph *pGraph)
{
    int ret = TRUE;

    if (pGraph != NULL)
    {
        if (pGraph->currentVertexCount > 0)
        {
            ret = FALSE;
        }
    }

    return ret;
}
