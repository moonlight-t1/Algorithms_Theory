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

ArrayList *createArrayList(int maxElementCount);
void deleteArrayList(ArrayList *pList);
int isArrayListFull(ArrayList *pList);
int addALElement(ArrayList *pList, int position, ArrayListNode element);
int removeALElement(ArrayList *pList, int poistion);
ArrayListNode *getALElement(ArrayList *pList, int position);
void displayArrayList(ArrayList *pList);
void clearArrayList(ArrayList *pList);
int getArrayListLength(ArrayList *pList);

int AddALElementFirst(ArrayList *pList, int element);
int addALElementLast(ArrayList *pList, int element);

#endif

// 기타 상수값 선언
#ifndef _CONMMON_LIST_DEF_
#define _COMMONT_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif
