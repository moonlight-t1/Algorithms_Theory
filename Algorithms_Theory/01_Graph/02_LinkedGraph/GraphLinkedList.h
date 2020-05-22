#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct GraphVertexType
{
    int vertexID;
    int weight;
} GraphVertex;

// 구조체 ListNode 선언
typedef struct ListNodeType
{
    GraphVertex data;
    struct ListNodeType *pLink;
} ListNode;

// 구조체 LinkedList 선언
typedef struct LinkedListType
{
    int currentElementCount; // 현재 저장된 원소의 개수
    ListNode headerNode;     // 헤더 노드(Header Node)
} LinkedList;

LinkedList *createLinkedList();                                      // 연결 리스트 생성
int addLLElement(LinkedList *pList, int position, ListNode element); // 노드 추가
int removeLLElement(LinkedList *pList, int position);                // 노드 삭제
ListNode *getLLElement(LinkedList *pList, int position);             // 리스트 원소 반환

void clearLinkedList(LinkedList *pList);
int getLinkedListLength(LinkedList *pList);
void deleteLinkedList(LinkedList *pList);
int isEmpty(LinkedList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
