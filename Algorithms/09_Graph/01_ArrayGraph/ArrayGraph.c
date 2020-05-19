#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayGraph.h"

// 그래프의 생성
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

    // 최대 노드 개수 maxVertextCount만큼 루프를 돌면서 각 행마다 칼럼갯수 만큼의
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

    // 노드 생성 여부를 저장하는 변수 pReturn->pVertext와 간선의 정보를 저장하는
    // 각 pReturn->ppAdjEdge[i]에 대한 메모리 값 초기화
    memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    for (i = 0; i < maxVertexCount; i++)
    {
        memset(pReturn->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
    }
    return pReturn;
}

ArrayGraph *createArrayDirectedGraph(int maxVertexCount)
{
    ArrayGraph *pReturn = NULL;
    pReturn = createArrayGraph(maxVertexCount);
    if (pReturn != NULL)
    {
        pReturn->graphType = GRAPH_DIRECTED;
    }
    return pReturn;
}

void deleteArrayGraph(ArrayGraph *pGraph);
int isEmptyAG(ArrayGraph *pGraph);
int addVertexAG(ArrayGraph *pGraph, int vertextID);
int addEdgeAG(ArrayGraph *pGraph, int fromVertextID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertextID, int toVertextID, int weight);
int removeVertextAG(ArrayGraph *pGraph, int vertextID);
int removeEdgeAG(ArrayGraph *pGraph, int fromVertextID, int toVertextID);
void displayArrayGraph(ArrayGraph *pGraph);