#ifndef _ARRAYLIST_H_
#define _ARRAYLIST_H_

// 구조체 ArrayListNode 선언
typedef struct ArrayListNodeType
{
    int data;
} ArrayListNode;

// 구조체 ArrayList 선언
typedef struct ArrayListType
{
    int maxElementCount;     // 최대 원소 개수
    int currentElementCount; // 현재 원소의 개수
    ArrayListNode *pElement; // 원소 저장을 위한 1차원 배열
} ArrayList;

ArrayList *createArrayList(int maxElementCount);                         // 리스트 생성
void deleteArrayList(ArrayList *pList);                                  // 리스트 삭제
int isArrayListFull(ArrayList *pList);                                   // 원소 추가 가능 여부 판단
int addALElement(ArrayList *pList, int position, ArrayListNode element); // 원소 추가
int removeALElement(ArrayList *pList, int poistion);                     // 원소 제거
void clearArrayList(ArrayList *pList);                                   // 원소 초기화
int getArrayListLength(ArrayList *pList);                                // 원소 갯수
ArrayListNode *getALElement(ArrayList *pList, int position);             // 원소 반환
void displayArrayList(ArrayList *pList);

int addALElementFirst(ArrayList *pList, int element);
int addALElementLast(ArrayList *pList, int element);

#endif

// 기타 상수값 선언
#ifndef _CONMMON_LIST_DEF_
#define _COMMONT_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
