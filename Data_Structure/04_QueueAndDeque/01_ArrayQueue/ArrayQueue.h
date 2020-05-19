#ifndef _ARRAY_QUEUE_
#define _ARRAY_QUEUE_

// 구조체 ARrayQueueNode 선언
typedef struct ArrayQueueNodeType
{
    char element;
} ArrayQueueNode;

typedef struct ArrayQueueType
{
    int maxElementCount;      // 최대 원소 개수
    int currentElementCount;  // 현재 원소의 개수
    int front;                // 프런트(front)의 위치
    int rear;                 // 리어(rear)의 위치
    ArrayQueueNode *pElement; // 노드 저장을 위한 1차원 배열 포인터
} ArrayQueue;

ArrayQueue *createArrayQueue(int maxElementCount);
int enqueueAQ(ArrayQueue *pQueue, ArrayQueueNode element);
ArrayQueueNode *dequeueAQ(ArrayQueue *pQueue);
ArrayQueueNode *peekAQ(ArrayQueue *pQueue);
void deleteArrayQueue(ArrayQueue *pQueue);
int isArrayQueueFull(ArrayQueue *pQueue);
int isArrayQueueEmpty(ArrayQueue *pQueue);

#endif

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE 1
#define FALSE 0

#endif