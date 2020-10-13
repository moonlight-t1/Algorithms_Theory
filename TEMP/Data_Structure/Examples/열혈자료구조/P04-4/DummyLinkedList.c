#include <stdio.h>
#include <stdlib.h>
#include "DummyLinkedList.h"

// 리스트 초기화
void ListInit(List *plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

// 맨 앞에 노드 추가
void FInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->head->next;
    plist->head->next = newNode;

    (plist->numOfData)++;
}

// 정렬 기준(comp 함수)맞게 삽입
void SInsert(List *plist, LData data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *pred = plist->head;
    newNode->data = data;

    while (pred->next != NULL &&
           plist->comp(data, pred->next->data) != 0)
    {
        pred = pred->next;
    }

    newNode->next = pred->next;
    pred->next = newNode;

    (plist->numOfData)++;
}

// 정렬 기준 존재 여부에 따라 삽입
void LInsert(List *plist, LData data)
{
    if (plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

// 첫 번째 노드 가리키게 하는 함수
int LFirst(List *plist, LData *pdata)
{
    if (plist->head->next == NULL) // 더미 노드가 NULL을 가리킨다면
        return FALSE;

    plist->before = plist->head;
    plist->cur = plist->head->next;

    *pdata = plist->cur->data;
    return TRUE;
}

// 다음 노드를 가리키게 하는 함수
int LNext(List *plist, LData *pdata)
{
    if (plist->cur->next == NULL)
        return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;

    *pdata = plist->cur->data;
    return TRUE;
}

// 노드 삭제
LData LRemove(List *plist)
{
    Node *rpos = plist->cur;
    LData rdata = rpos->data;

    plist->before->next = plist->cur->next;
    plist->cur = plist->before;

    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List *plist)
{
    return plist->numOfData;
}

// 정렬을 위한 리스트 멤버 comp 초기화
void SetSortRule(List *plist, int (*comp)(LData d1, LData d2))
{
    plist->comp = comp;
}