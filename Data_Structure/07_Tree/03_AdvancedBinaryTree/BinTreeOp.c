#include <stdio.h>
#include <stdlib.h>
#include "BinTreeOp.h"

// 이진 트리 복사
BinTree *copyBinTree(BinTree *pSource)
{
    BinTree *pReturn = NULL;
    if (pSource != NULL)
    {
        pReturn = (BinTree *)malloc(sizeof(BinTree)); // 이진 트리 구조체 메모리 할당 및 점검
        if (pReturn != NULL)
        {
            // 재귀 전위 순회 방법으로 트리 복사.
            // 단, 이진 트리의 루트 노드가 시작 녿
            pReturn->pRootNode = copyBinTreeNode(pSource->pRootNode);
        }
        else
        {
            printf("Error. Memory Allocatio Failed. copyBinTree()\n");
        }
    }
    return pReturn;
}

BinTreeNode *copyBinTreeNode(BinTreeNode *pSourceNode)
{
    BinTreeNode *pReturn = NULL;
    if (pSourceNode != NULL)
    {
        pReturn = (BinTreeNode *)malloc(sizeof(BinTreeNode));
        // 현재 노드에 대한 메모리 할당 및 점검
        if (pReturn != NULL)
        {
            // 재귀 전위 순회 방식
            *pReturn = *pSourceNode;                                                  // 현재 노드 방문(복사)
            pReturn->pLeftChild = copyBinTreeNode(getLeftChildNodeBT(pSourceNode));   // 왼쪽 자식 노드 이동(복사)
            pReturn->pRightChild = copyBinTreeNode(getRightChildNodeBT(pSourceNode)); // 오른쪽 자식 노드 이동(복사)
        }
        else
        {
            printf("Error. Memory Allocation Failed. copyBinTreeNode()\n");
        }
    }
    return pReturn;
}

// 이진 트리 동일성 검사
int equalBinTree(BinTree *pFirst, BinTree *pSecond)
{
    int ret = FALSE;

    if (pFirst == NULL && pSecond == NULL) // 두 트리가 모두 NULL이면 동일
    {
        ret = TRUE;
    }
    else if (pFirst != NULL && pSecond != NULL && equalBinTreeNode(pFirst->pRootNode, pSecond->pRootNode) == TRUE)
    {
        ret = TRUE;
    }
    return ret;
}

int equalBinTreeNode(BinTreeNode *pFirst, BinTreeNode *pSecond)
{
    int ret = FALSE;

    if (pFirst == NULL && pSecond == NULL) // 두 노드가 모두 NULL이면 동일
    {
        ret = TRUE;
    }
    // 재귀 전위 순회 방식으로 비교
    else if (pFirst != NULL && pSecond != NULL && pFirst->data == pSecond->data     // 현재 노드 비교
             && equalBinTreeNode(pFirst->pLeftChild, pSecond->pLeftChild) == TRUE   // 왼쪽 자식 노드 비교
             && equalBinTreeNode(pFirst->pRightChild, pSecond->pLeftChild) == TRUE) // 오른쪽 자식 노드 비교
    {
        ret = TRUE;
    }
    return ret;
}

// 이진 트리 노드 개수 구하기
int getNodeCountBT(BinTree *pSource)
{
    int ret = 0;
    if (pSource != NULL)
    {
        ret = getNodeCountBTNode(pSource->pRootNode);
    }
    return ret;
}

int getNodeCountBTNode(BinTreeNode *pSource)
{
    int ret = 0;
    if (pSource != NULL)
    {
        // 왼쪽 서브트리의 노드 개수 + 오른쪽 서브트리의 노드 개수 + 현재 노드의 개수(1)
        ret = getNodeCountBTNode(pSource->pLeftChild) + getNodeCountBTNode(pSource->pRightChild) + 1;
    }
    return ret;
}

// 이진 트리의 단말 노드 개수
int getLeafNodeCountBT(BinTree *pSource)
{
    int ret = 0;
    if (pSource != NULL)
    {
        ret = getLeafNodeCountBTNode(pSource->pRootNode);
    }
    return ret;
}

int getLeafNodeCountBTNode(BinTreeNode *pSource)
{
    int ret = 0;
    if (pSource != NULL)
    {
        // 단말 노드인 경우에는 노드 개수 1 반환
        if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL)
        {
            ret = 1;
        }
        else
        {
            // 단말 노드가 아닌 경우에는 왼쪽 서브트리에서의 단말 노드 개수와 오른쪽 서브트리에서의 단말 노드 개수를 더한다
            ret = getLeafNodeCountBTNode(pSource->pLeftChild) + getLeafNodeCountBTNode(pSource->pRightChild) + 1;
        }
    }
    return ret;
}

// 이진 트리의 높이
int getHeightBT(BinTree *pSource)
{
    int ret = 0;
    if (pSource != NULL)
    {
        ret = getHeightBTNode(pSource->pRootNode);
    }
    return ret;
}

int getHeightBTNode(BinTreeNode *pSource)
{
    int ret = 0;
    if (pSource != NULL)
    {
        // 단말 노드라면 높이 1 반환
        if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL)
        {
            ret = 1;
        }
        else
        {
            // 단말 노드가 아니라면 두 개의 서브트리 높이 중 큰 값에 1을 더해 리턴한다
            int leftChildHeight = getHeightBTNode(pSource->pLeftChild);
            int rightChildHeight = getHeightBTNode(pSource->pRightChild);
            if (leftChildHeight >= rightChildHeight)
            {
                ret = 1 + leftChildHeight;
            }
            else
            {
                ret = 1 + rightChildHeight;
            }
        }
    }
    return ret;
}

// 이진 트리 구조 및 내용 출력
void displayBinTree(BinTree *pTree)
{
    if (pTree != NULL)
    {
        displayBinTreeNode(pTree->pRootNode, 0, '0');
    }
    else
    {
        printf("Tree is NULL.\n");
    }
}

void displayBinTreeNode(BinTreeNode *pNode, int level, char type)
{
    int i = 0;
    for (i = 0; i < level; i++)
    {
        printf("\t");
    }
    if (pNode != NULL)
    {
        printf("-[%i, %c]%c\n", level, type, pNode->data);

        displayBinTreeNode(pNode->pLeftChild, level + 1, 'L');
        displayBinTreeNode(pNode->pRightChild, level + 1, 'R');
    }
    else
    {
        printf("NULL\n");
    }
}