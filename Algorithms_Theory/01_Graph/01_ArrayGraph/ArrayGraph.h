#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

typedef struct ArrayGraphType
{
    int maxVertexCount;     // 최대 노드 개수
    int currentVertexCount; // 현재 사용되는 노드의 개수
    int graphType;          // 그래프의 종류1: 1-Undirected, 2-Directed
    int *pVertex;           // 노드 저장을 위한 1차원 array
    int **ppAdjEdge;        // 간선 저장을 위힌 2차원 array
} ArrayGraph;

ArrayGraph *createArrayGraph(int maxVertexCount); // 무방향 그래프 생성
ArrayGraph *createArrayDirectedGraph(int maxVertexCount);
void deleteArrayGraph(ArrayGraph *pGraph);
int isEmptyAG(ArrayGraph *pGraph);
int addVertexAG(ArrayGraph *pGraph, int VertexID);
int addEdgeAG(ArrayGraph *pGraph, int fromVertetID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight);
int removeVertexAG(ArrayGraph *pGraph, int VertexID);
int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);
void displayArrayGraph(ArrayGraph *pGraph);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

#endif