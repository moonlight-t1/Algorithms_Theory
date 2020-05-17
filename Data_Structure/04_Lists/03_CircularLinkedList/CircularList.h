#ifndef _CIRCULAR_LIST_H_
#define _CICUULAR_LIST_H_

typedef struct CircularListNodeType
{
    int data;
    struct CircularListNodeType *pLink;
} CircularListNode;

typedef struct CircularListType
{
    int currentElementCount; // 현재 저장된 원소의 개수
    CircularListNode *pLink; // 헤드 포인터(Head Pointer)
} CircularList;

CircularList *createCircularList();                                            // 원형 연결리스트 생성
void deleteCircularList(CircularList *pList);                                  // 원형 연결리스트 삭제
int addCLElement(CircularList *pList, int position, CircularListNode element); // 원소 추가
int removeCLElement(CircularList *pList, int position);                        // 원소 제거
void clearCircularList(CircularList *pList);                                   // 원형 연결 리스트 초기화
int getCircularListLength(CircularList *pList);                                // 원형 연결 리스트 길이
CircularListNode *getCLElement(CircularList *pList, int position);             // 원소 반환
void displayCircularList(CircularList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif