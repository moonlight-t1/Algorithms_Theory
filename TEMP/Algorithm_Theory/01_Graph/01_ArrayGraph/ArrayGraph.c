#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayGraph.h"

// 무방향 그래프의 생성
ArrayGraph *createArrayGraph(int maxVertexCount)
{
    int i = 0, j = 0;
    ArrayGraph *pReturn = NULL;

    // 최대 노드의 갯수는 0보다 커야하는 조건을 검증
    if (maxVertexCount > 0)
    {
        // 그래프 구조체에 대한 메모리를 할당하고 이를 검증
        pReturn = (ArrayGraph *)malloc(sizeof(ArrayGraph));
        if (pReturn == NULL)
        {
            printf("Error. Memory Allocation Failed(1) in createArrayGraph()\n");
            return NULL;
        }
        // 초기화 실시, 그래프 종류를 무방향 그래프로 설정하고 최대 노드 개수를 설정
        pReturn->graphType = GRAPH_UNDIRECTED;
        pReturn->maxVertexCount = maxVertexCount;
    }
    else
    {
        printf("Error. Maximum number of nodes should be greater than 0.\n");
        return 0;
    }

    // 노드의 사용 여부를 저장하는 배열 pVertex의 메모리를 할당하고 이를 검증
    pReturn->pVertex = (int *)malloc(sizeof(int) * maxVertexCount);
    if (pReturn->pVertex == NULL)
    {
        printf("Error. Memory Allocation Failed(2) in createArrayGraph()\n");
        if (pReturn != NULL)
        {
            free(pReturn);
        }
        return NULL;
    }

    // 간선을 저장하기 위해 '포인터 변수'들의 1차원 배열을 위한 메모리를 할당하고 메모리 검증
    pReturn->ppAdjEdge = (int **)malloc(sizeof(int *) * maxVertexCount);
    if (pReturn->ppAdjEdge == NULL)
    {
        printf("Error. Memory Allocatio Failed(3) in createArrayGraph()\n");
        if (pReturn->pVertex != NULL)
        {
            free(pReturn->pVertex);
        }
        if (pReturn != NULL)
        {
            free(pReturn);
        }
        return NULL;
    }

    // 최대 노드 개수 maxVertexCount만큼 루프를 돌면서 각 행마다 칼럼갯수 만큼의
    // 1차원 배열에 대한 메모리를 할당하고 메모리 검증
    for (i = 0; i < maxVertexCount; i++)
    {
        pReturn->ppAdjEdge[i] = (int *)malloc(sizeof(int) * maxVertexCount);
        if (pReturn->ppAdjEdge[i] == NULL)
        {
            printf("Error. Memory Allocation Failed(4), in createArrayGraph()\n");
            for (j = 0; j < i - 1; j++)
            {
                if (pReturn->ppAdjEdge[j] != NULL)
                {
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
    }

    // 노드 생성 여부를 저장하는 변수 pReturn->pVertex와 간선의 정보를 저장하는
    // 각 pReturn->ppAdjEdge[i]에 대한 메모리 값 초기화
    memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    for (i = 0; i < maxVertexCount; i++)
    {
        memset(pReturn->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
    }
    return pReturn;
}

// 방향 그래프 생성
ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph *pReturn = NULL;
    pReturn = createArrayGraph(maxVertexCount);
    // 무방향 그래프에 타입만 방향으로 설정해준다
    if (pReturn != NULL)
    {
        pReturn->graphType = GRAPH_DIRECTED;
    }
    return pReturn;
}

// 노드 추가
int addVertexAG(ArrayGraph *pGraph, int vertexID)
{
    int ret = SUCCESS;

    if (pGraph != NULL)
    {
        // 노드의 id가 유효한 범위인지, 추가하려는 노드가 이미 존재하는 노드인지를 점검
        if (vertexID < pGraph->maxVertexCount)
        {
            if (pGraph->pVertex[vertexID] == NOT_USED)
            {
                // 추가하려는 노드의 해당 정보를 변경
                pGraph->pVertex[vertexID] = USED; // 노드의 상태를 USED로 변경
                pGraph->currentVertexCount++;     // 현재 사용되는 노드의 개수를 1 증가
            }
            else
            {
                printf("Error. Already exists node [%d], in addVertexAG()\n", vertexID);
                ret = FAIL;
            }
        }
        else
        {
            printf("Error. Maximum number of nodes exceeded [%d], in AddVertexAG()\n", pGraph->maxVertexCount);
        }
    }
    return ret;
}

// 가중치 간선 추가
int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight)
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

        // 추가 되는 간선의 정보(가중치 값)을 변경
        pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;

        // 무방향 그래프일 경우 대칭성을 처리
        // 대칭되는 위치의 간선 정보도 같이 변경
        if (pGraph->graphType == GRAPH_UNDIRECTED)
        {
            pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
        }
    }
    return ret;
}

// 간선 유효성 점검
int checkVertexValid(ArrayGraph *pGraph, int vertexID)
{
    int ret = SUCCESS;

    // 노드의 id가 최대 노드 개수 미만인지 점검
    // 해당 노드의 상태가 사용중(USED)인지 점검
    if (vertexID >= pGraph->maxVertexCount || pGraph->pVertex[vertexID] == NOT_USED)
    {
        printf("Error. Node information [%d]\n", vertexID);
        ret = FAIL;
    }
}

// 간선 추가
int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
{
    // 가중치 USED(1)로 설정
    return addEdgewithWeightAG(pGraph, fromVertexID, toVertexID, USED);
}

// 간선 제거 함수
int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID)
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

        // 간선 정보 초기화
        pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;

        // 무방향 그래프인 경우 대칭성을 처리
        // 대칭되는 위치의 간선 정보도 같이 변경
        if (pGraph->graphType == GRAPH_UNDIRECTED)
        {
            pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
        }
    }
    return ret;
}

// 노드 제거 함수
int removeVertexAG(ArrayGraph *pGraph, int vertexID)
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

        // 제거하려는 노드에 부속된(incident) 간선 정보를 먼저 제거
        for (i = 0; i < pGraph->maxVertexCount; i++)
        {
            removeEdgeAG(pGraph, vertexID, i);
            removeEdgeAG(pGraph, i, vertexID);
        }

        // 노드 정보 초기화
        pGraph->pVertex[vertexID] = NOT_USED;
    }
    return ret;
}

void displayArrayGraph(ArrayGraph *pGraph)
{
    int i = 0;
    int j = 0;

    if (pGraph != NULL)
    {
        for (i = 0; i < pGraph->maxVertexCount; i++)
        {
            for (j = 0; j < pGraph->maxVertexCount; j++)
            {
                printf("%d ", pGraph->ppAdjEdge[i][j]);
            }
            printf("\n");
        }
    }
}

void deleteArrayGraph(ArrayGraph *pGraph)
{
    int i = 0;

    if (pGraph != NULL)
    {
        for (i = 0; i < pGraph->maxVertexCount; i++)
        {
            free(pGraph->ppAdjEdge[i]);
        }
        free(pGraph->ppAdjEdge);
        free(pGraph->pVertex);
        free(pGraph);
    }
}

int isEmptyAG(ArrayGraph *pGraph)
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
