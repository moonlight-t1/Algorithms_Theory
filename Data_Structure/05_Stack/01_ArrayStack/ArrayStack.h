#ifndef _ARRAY_STACK_H_
#define _ARRAY_STACK_H_

// 구조체 ArrayStackNode 선언
typedef struct ArrayStackNodeType
{
    char data;
} ArrayStackNode;

// 구조체 ArrayStack 선언
typedef struct ArrayStackType
{
    int maxElementCount;      // 최대 원소 개수
    int currentElementCount;  // 현재 원소의 개수
    ArrayStackNode *pElement; // 노즈 저장을 위한 1차원 array
} ArrayStack;

ArrayStack *createArrayStack(int maxElementCount);
int pushAS(ArrayStack *pStack, ArrayStackNode element);
ArrayStackNode *popAS(ArrayStack *pStack);
ArrayStackNode *peekAS(ArrayStack *pStack);
void deleteArrayStack(ArrayStack *pStack);
int isArrayStackFull(ArrayStack *pStack);
int isArrayStackEmpty(ArrayStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE 1
#define FALSE 0

#endif