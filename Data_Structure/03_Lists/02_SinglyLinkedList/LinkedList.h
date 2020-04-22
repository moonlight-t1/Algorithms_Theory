#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

// 구조체 ListNode 선언
typedef struct ListNodeType
{
    int data;
    struct ListNodeType *pLink;
} ListNode;

// 구조체 LinkedList 선언
typedef struct LinkedListType
{
    int currentElementCount; // 현재 저장된 원소의 개수
    ListNode headerNode;     // 헤더 노드(Header Node)
} LinkedList;

LinkedList *createLinkedList();
int AddLLElement(LinkedList *pList, int position, ListNode element);
int removeLLElement(LinkedList *pList, int position);
ListNode *getLLElement(LinkedList *pList, int position);

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
