#include <stdio.h>
#include <stdlib.h>
#include "BinSearchTree.h"

// 이진 탐색 트리 생성
BinSearchTree *createBinSearchTree()
{
    BinSearchTree *pReturn = NULL;
    pReturn = (BinSearchTree *)malloc(sizeof(BinSearchTree));
    if (pReturn != NULL)
    {
        pReturn->pRootNode = NULL;
    }
    else
    {
        printf("Error. Memory Allocation Failed. createBinSearchTree()\n");
    }
    return pReturn;
}

// 이진 탐색 트리 삽입 연산
int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element)
{
    int ret = TRUE;
    BinSearchTreeNode *pParentNode = NULL;
    BinSearchTreeNode *pNewNode = NULL;
    if (pBinSearchTree == NULL)
    {
        ret = FALSE;
        return ret;
    }
    pParentNode = pBinSearchTree->pRootNode;

    // 검색
    while (pParentNode != NULL)
    {
        // Case 1 : 중복된 키가 발견된 경우
        if (element.key == pParentNode->key)
        {
            printf("Error. Duplicated Key - [%d]. insertElementBST()\n", element.key);
            ret = FALSE;
            return ret;
        }
        // Case 2 : 현재 노드 키 값보다 작은 경우 - 왼쪽 서브트리로 이동
        else if (element.key < pParentNode->key)
        {
            // 왼쪽 자식 노드가 NULL 이면, 새로운 노드를 삽입할 위치를 발견
            if (pParentNode->pLeftChild == NULL)
            {
                break;
            }
            // 왼쪽 자식 노드가 NULL이 아니면, 계속 왼쪽 자식 노드로 이동
            else
            {
                pParentNode = pParentNode->pLeftChild;
            }
        }
        // Case 3 : 현재 노드의 키 값보다 큰 경우 - 오른쪽 서브 트리로 이동
        else
        {
            // 오른쪽 자식 노드가 NULL이면, 새로운 노드를 삽입할 위치를 발견
            if (pParentNode->pRightChild == NULL)
            {
                break;
            }
            // 오른쪽 자식 노드가 NULL이 아니면, 계속 오른쪽 자식 노드로 이동
            else
            {
                pParentNode = pParentNode->pRightChild;
            }
        }
    }

    // 새로운 노드의 메모리 할당, 점검 및 초기화
    pNewNode = (BinSearchTreeNode *)malloc(sizeof(BinSearchTreeNode));
    if (pNewNode != NULL)
    {
        *pNewNode = element;
        pNewNode->pLeftChild = NULL;
        pNewNode->pRightChild = NULL;
        // 새로 추가되는 노드의 부모 노드가 NULL인 경우
        // 즉, 루트 노드가 NULL인 경우이며 새로 추가되는 노드를 이진 탐색 트리의 루트 노드가 된다
        if (pParentNode == NULL)
        {
            pBinSearchTree->pRootNode = pNewNode;
        }
        else
        {
            // 새로운 노드의 키 값과 부모 노드 pParentNode의 키 값을 비교
            // 부모 노드의 키 값보다 작다면 왼쪽 자식 노드로 추가 그렇지 않다면 오른쪽 자식 노드로 추가
            if (pNewNode->key < pParentNode->key)
            {
                pParentNode->pLeftChild = pNewNode;
            }
            else
            {
                pParentNode->pRightChild = pNewNode;
            }
        }
        ret = TRUE;
    }
    else
    {
        printf("Error. Memory Allocation Failed. insertElementBST()\n");
        ret = FALSE;
    }
    return ret;
}

// 이진 탐색 트리에서의 삭제 연산
int deleteElementBST(BinSearchTree *pBinSearchTree, int key)
{
    int ret = TRUE;
    BinSearchTreeNode *pDelNode = NULL, *pParentNode = NULL;
    BinSearchTreeNode *pPredecessor = NULL, *pSuccessor = NULL;
    BinSearchTreeNode *pChildNode = NULL;

    if (pBinSearchTree == NULL)
    {
        ret = FALSE;
        return ret;
    }

    pParentNode = NULL;
    pDelNode = pBinSearchTree->pRootNode;

    // 검색
    while (pDelNode != NULL)
    {
        // Case 1 : 키가 발견된 경우
        if (key == pDelNode->key)
        {
            break;
        }

        pParentNode = pDelNode;
        // Case 2 : 키가 현재 노드보다 작은 경우. 왼쪽 자식 노드로 이동
        if (key < pDelNode->key)
        {
            pDelNode = pDelNode->pLeftChild;
        }
        // Case 3 : 키가 현재 노드보다 큰 경우. 오른쪽 자식 노드로 이동
        else
        {
            pDelNode = pDelNode->pRightChild;
        }
    } // end-of-while

    if (pDelNode == NULL)
    {
        printf("Error. Key doesn't exists - [%d], deleteElementBST()\n", key);
        ret = FALSE;
        return ret;
    }

    // (a) 삭제 대상의 자식 노드가 0개인 경우
    if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL)
    {
        if (pParentNode != NULL)
        {
            if (pParentNode->pLeftChild == pDelNode)
            {
                pParentNode->pLeftChild = NULL;
            }
            else
            {
                pParentNode->pRightChild = NULL;
            }
        }
        else
        {
            pBinSearchTree->pRootNode = NULL;
        }
    }
    // (b) 삭제 대상 노드의 자식 노드가 2개인 경우
    else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL)
    {
        pPredecessor = pDelNode;
        // 왼쪽 서브트리에서 가장 큰 키 값을 가지는 노드 찾기
        pSuccessor = pDelNode->pLeftChild; // 삭제 노드의 왼쪽 서브트리로 이동
        // 왼쪽 서브트리의 오른쪽 자식 노드를 따라 계속 이동
        while (pSuccessor->pRightChild != NULL)
        {
            pPredecessor = pSuccessor;
            pSuccessor = pSuccessor->pRightChild;
        }

        // 포인터 변수 pSuccessor는 (삭제할 노드를 대체할) 대체 노드를 가리킨다
        // 삭제할 노드 pDelNode의 자식 노드를 대체 노드 pSuccessor의 자식 노드로 변경
        pPredecessor->pRightChild = pSuccessor->pLeftChild;
        pSuccessor->pLeftChild = pDelNode->pLeftChild;
        pSuccessor->pRightChild = pDelNode->pRightChild;

        // 대체 노드 pSuccessor를 기존 삭제 노드의 부모 노드 pParentNode의 새로운 자식 노드로 설정
        if (pParentNode != NULL)
        {
            if (pParentNode->pLeftChild == pDelNode)
            {
                pParentNode->pLeftChild = pSuccessor;
            }
            else
            {
                pParentNode->pRightChild = pSuccessor;
            }
        }
        else
        {
            // 부모 노다 pParentNode가 NULL이면 루트 노드가 삭제되었다는 의미이기 때문에
            // 이진 탐색 트리으 새로운 루트 노드로 설정
            pBinSearchTree->pRootNode = pSuccessor;
        }
    }
    // (c) 삭제 대상 노드의 자식 노드가 1개인 경우 처리
    else
    {
        // 삭제 노드를 대체할 노드 찾기
        if (pDelNode->pLeftChild != NULL)
        {
            pChildNode = pDelNode->pLeftChild;
        }
        else
        {
            pChildNode = pDelNode->pRightChild;
        }

        // 대체할 노드를 삽입
        if (pParentNode != NULL)
        {
            if (pParentNode->pLeftChild == pDelNode)
            {
                pParentNode->pLeftChild = pChildNode;
            }
            else
            {
                pParentNode->pRightChild = pChildNode;
            }
        }
        // 만약 부모 노드가 NULL이면 루트 노드를 삭제한 경우이다
        else
        {
            pBinSearchTree->pRootNode = pChildNode;
        }
    }

    free(pDelNode);
    return ret;
}

// 이진 탐색 트리에서의 검색 연산
BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key)
{
    BinSearchTreeNode *pReturn = NULL;

    if (pBinSearchTree == NULL)
    {
        return NULL;
    }
    pReturn = searchInternalRecursiveBST(pBinSearchTree->pRootNode, key);

    return pReturn;
}

BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key)
{
    BinSearchTreeNode *pReturn = NULL;

    if (pTreeNode == NULL)
    {
        return NULL;
    }

    if (key == pTreeNode->key)
    {
        pReturn = pTreeNode;
    }
    else if (key < pTreeNode->key)
    {
        pReturn = searchInternalRecursiveBST(pTreeNode->pLeftChild, key);
    }
    else
    {
        pReturn = searchInternalRecursiveBST(pTreeNode->pRightChild, key);
    }

    return pReturn;
}

BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key)
{
    BinSearchTreeNode *pReturn = NULL;

    if (pBinSearchTree == NULL)
    {
        return NULL;
    }
    pReturn = pBinSearchTree->pRootNode;
    while (pReturn != NULL)
    {
        if (key == pReturn->key)
        {
            break;
        }
        else if (key < pReturn->key)
        {
            pReturn = pReturn->pLeftChild;
        }
        else
        {
            pReturn = pReturn->pRightChild;
        }
    }

    return pReturn;
}

// 이진 탐색 트리 삭제
void deleteBinSearchTree(BinSearchTree *pBinSearchTree)
{
    if (pBinSearchTree != NULL)
    {
        deleteBinSearchTreeInternal(pBinSearchTree->pRootNode);
        free(pBinSearchTree);
    }
}

// 후위 순회 방식으로 메모리 해제
void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode)
{
    if (pTreeNode != NULL)
    {
        deleteBinSearchTreeInternal(pTreeNode->pLeftChild);
        deleteBinSearchTreeInternal(pTreeNode->pRightChild);
        free(pTreeNode);
    }
}
