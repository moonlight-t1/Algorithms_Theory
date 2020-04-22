#ifndef __ARRAYLIST_H__
#define __ARRAYLIST_H__

// 구조체 ArrayListNode 선언
typedef struct ArrayListNodeType
{
    int data;
} ArrayListNode;

// 구조체 ArrayList 선언
typedef struct ArrayListType
{
    int maxElementCount; // 최대 원소 개수
    int currentElementCount; // 현재 원소의 개수
    ArrayListNode *pElement; // 원소 저장을 위한 1차원 배열
}ArrayList;


#endif