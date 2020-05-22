#ifndef _LINKED_STACK_H_
#define _LINKED_STACK_H_

// 구조체 StackNode 선언
typedef struct StackNodeType
{
    char data;
    struct StackNodeType *pLink;
} StackNode;

// 구조체 LinkedStack 선언
typedef struct LinkedStackType
{
    int currentElementCount; // 현재 원소의 개수
    StackNode *pTopElement;  // Top 노드의 포인터
} LinkedStack;

LinkedStack *createLinkedStack();
int pushLS(LinkedStack *pStack, StackNode element);
StackNode *popLS(LinkedStack *pStack);
StackNode *peekLS(LinkedStack *pStack);
void deleteLinkedStack(LinkedStack *pStack);
int isLinkedStackFull(LinkedStack *pStack);
int isLinkedStackEmpty(LinkedStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif