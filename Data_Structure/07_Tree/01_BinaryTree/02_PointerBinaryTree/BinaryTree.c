#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 이진 트리의 생성
BinTree *makeBinTree(BinTreeNode rootNode)
{
    BinTree *pReturn = NULL;
    pReturn = (BinTree *)malloc(sizeof(BinTree)); // 이진 트리 메모리 할당

    if (pReturn != NULL)
    {
        pReturn->pRootNode = (BinTreeNode *)malloc(sizeof(BinTreeNode)); // 루트 노드 메모리 할당

        if (pReturn->pRootNode != NULL)
        {
            // 이진 트리와 루트 노드 연결
            *(pReturn->pRootNode) = rootNode;
            pReturn->pRootNode->pLeftChild = NULL;
            pReturn->pRootNode->pRightChild = NULL;
        }
        else
        {
            printf("Error. Memory Allocation Failed (2). makeBinTree()\n");
            free(pReturn);
            pReturn = NULL;
        }
    }
    else
    {
        printf("Error. Memory Allcation Failed (1). makeBinTree()\n");
    }
    return pReturn;
}

// 트리의 루트 노드 반환
BinTreeNode *getRootNodeBT(BinTree *pBinTree)
{
    BinTreeNode *pReturn = NULL;

    if (pBinTree != NULL)
    {
        pReturn = pBinTree->pRootNode;
    }

    return pReturn;
}

// 왼쪽 자식 노드 추가
BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
    BinTreeNode *pReturn = NULL;
    if (pParentNode != NULL)
    {
        if (pParentNode->pLeftChild == NULL)
        {
            // 왼쪽 자식 노드 메모리 할당 및 초기화
            pParentNode->pLeftChild = (BinTreeNode *)malloc(sizeof(BinTreeNode));
            if (pParentNode->pLeftChild != NULL)
            {
                *(pParentNode->pLeftChild) = element;
                pParentNode->pLeftChild->pLeftChild = NULL;
                pParentNode->pLeftChild->pRightChild = NULL;
                pReturn = pParentNode->pLeftChild;
            }
            else
            {
                printf("Error. Memory Allocation Failed. insertLeftChildNodeBT\n");
            }
        }
        else
        {
            printf("Error. Left child node is already exist. insertLeftChildNodeBT()\n");
        }
    }
    return pReturn;
}

// 오른쪽 자식 노드 추가
BinTreeNode *insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
    BinTreeNode *pReturn = NULL;
    if (pParentNode != NULL)
    {
        if (pParentNode->pRightChild == NULL)
        {
            // 오른쪽 자식 노드 메모리 할당 및 초기화
            pParentNode->pRightChild = (BinTreeNode *)malloc(sizeof(BinTreeNode));
            if (pParentNode->pRightChild != NULL)
            {
                *(pParentNode->pRightChild) = element;
                pParentNode->pRightChild->pLeftChild = NULL;
                pParentNode->pRightChild->pRightChild = NULL;
                pReturn = pParentNode->pRightChild;
            }
            else
            {
                printf("Error. Memory Allocation Failed. insertLeftChildNodeBT\n");
            }
        }
        else
        {
            printf("Error. Left child node is already exist. insertLeftChildNodeBT()\n");
        }
    }
    return pReturn;
}

// 왼쪽 자식 노드 반환
BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode)
{
    BinTreeNode *pReturn = NULL;

    if (pNode != NULL)
    {
        pReturn = pNode->pLeftChild;
    }

    return pReturn;
}

// 오른쪽 자식 노드 반환
BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode)
{
    BinTreeNode *pReturn = NULL;

    if (pNode != NULL)
    {
        pReturn = pNode->pRightChild;
    }

    return pReturn;
}

// 이진 트리의 삭제
void deleteBinTree(BinTree *pBinTree)
{
    if (pBinTree != NULL)
    {
        deleteBinTreeNode(pBinTree->pRootNode);
        free(pBinTree);
    }
}

// 노드의 서브트리 재귀적으로 삭제
void deleteBinTreeNode(BinTreeNode *pNode)
{
    if (pNode != NULL)
    {
        deleteBinTreeNode(pNode->pLeftChild);
        deleteBinTreeNode(pNode->pRightChild);
        free(pNode);
    }
}