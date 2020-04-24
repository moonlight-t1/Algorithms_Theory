#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "BinTreeTraversalRec.h"

// 재귀 전위 순회
void preorderTraversalRecursiveBinTree(BinTree *pBinTree)
{
    if (pBinTree != NULL)
    {
        preorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
    }
}
void preorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode)
{
    if (pRootNode != NULL)
    {
        printf("%c ", pRootNode->data);
        preorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
        preorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
    }
}

// 재귀 중위 순회
void inorderTraversalRecursiveBinTree(BinTree *pBinTree)
{
    if (pBinTree != NULL)
    {
        inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
    }
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode)
{
    if (pRootNode != NULL)
    {
        inorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
        printf("%c ", pRootNode->data);
        inorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
    }
}

// 재귀 후위 순회
void postorderTraversalRecursiveBinTree(BinTree *pBinTree)
{
    if (pBinTree != NULL)
    {
        postorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
    }
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode)
{
    if (pRootNode != NULL)
    {
        postorderTraversalRecursiveBinTreeNode(pRootNode->pLeftChild);
        postorderTraversalRecursiveBinTreeNode(pRootNode->pRightChild);
        printf("%c ", pRootNode->data);
    }
}