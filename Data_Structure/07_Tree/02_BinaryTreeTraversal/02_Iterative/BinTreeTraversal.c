#include <stdio.h>
#include <stdlib.h>
#include "BinTreeTraversal.h"

// 스택에 자료를 푸시하는 래핑(Wrapping) 함수
int pushLSBinTreeNode(LinkedStack *pStack, BinTreeNode *pNode)
{
    StackNode node = {
        0,
    };
    node.data = pNode;
    return pushLS(pStack, node);
}

// 큐에 자료를 인큐하는 래핑(Wrapping) 함수
int enqueueLQBinTreeNode(LinkedQueue *pQueue, BinTreeNode *pNode)
{
    QueueNode node = {
        0,
    };
    node.data = pNode;
    return enqueueLQ(pQueue, node);
}

// 반복 전위 순회
void preorderTraversalBinTree(BinTree *pBinTree)
{
    LinkedStack *pStack = NULL;
    StackNode *pStackNode = NULL;
    BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;

    if (pBinTree == NULL)
    {
        return;
    }
    pRootNode = getRootNodeBT(pBinTree);
    if (pRootNode == NULL)
    {
        return;
    }
    pStack = createLinkedStack();
    if (pStack == NULL)
    {
        return;
    }

    // 루트 노드를 먼저 스택에 푸시한다
    pushLSBinTreeNode(pStack, pRootNode);

    while (1)
    {
        // 스택에 더 이상 노드가 없을 때까지 루프를 돈다
        if (isLinkedStackEmpty(pStack) == TRUE)
        {
            break;
        }
        else
        {
            // 스택에서 팝을 해, 현재 노드를 반환하고 방문 처리 한다
            pStackNode = popLS(pStack);
            if (pStackNode != NULL)
            {
                pRootNode = pStackNode->data;
                printf("%c ", pRootNode->data);

                pLeftChildNode = getLeftChildNodeBT(pRootNode);
                pRightChildNode = getRightChildNodeBT(pRootNode);

                // 오른쪽 서브트리를 푸시한다
                if (pRightChildNode != NULL)
                {
                    pushLSBinTreeNode(pStack, pRightChildNode);
                }

                // 왼쪽 서브트리를 푸시한다
                if (pLeftChildNode != NULL)
                {
                    pushLSBinTreeNode(pStack, pLeftChildNode);
                }
                free(pStackNode);
            }
        }
    }
    deleteLinkedStack(pStack);
}

// 반복 중위 순회
void inorderTraversalBinTree(BinTree *pBinTree)
{
    LinkedStack *pStack = NULL;
    StackNode *pStackNode = NULL;
    BinTreeNode *pRootNode = NULL, *pNode = NULL;

    if (pBinTree == NULL)
    {
        return;
    }

    pRootNode = getRootNodeBT(pBinTree);
    if (pRootNode == NULL)
    {
        return;
    }

    pStack = createLinkedStack();

    if (pStack == NULL)
    {
        return;
    }

    // 루트 노드가 첫 번째 노드이다
    pNode = pRootNode;

    while (1)
    {
        // 현재 노드부터 시작하여, 왼쪽 서브트리를 스택에 푸시한다
        for (; pNode != NULL; pNode = getLeftChildNodeBT(pNode))
        {
            pushLSBinTreeNode(pStack, pNode);
        }

        // 스택에 더 이상 노드가 없을 때까지 루프를 돈다
        if (isLinkedStackEmpty(pStack) == TRUE)
        {
            break;
        }
        // 스택에서 팝된 노드가 새로운 현재 노드가 된다.
        else
        {
            pStackNode = popLS(pStack);
            if (pStackNode != NULL)
            {
                // 현재 노드의 방문 처리
                pNode = pStackNode->data;
                printf("%c ", pNode->data);
                // 현재 노드의 오른쪽 서브트리가 새로운 pNode가 된다
                // 왼쪽 서버트리들이 스택에 푸시된다
                pNode = getRightChildNodeBT(pNode);
                free(pStackNode);
            }
        }
    }
    deleteLinkedStack(pStack);
}

// 반복 후위 순회
void postorderTraversalBinTree(BinTree *pBinTree)
{
    LinkedStack *pStack = NULL;
    StackNode *pStackNode = NULL;
    BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;

    if (pBinTree == NULL)
    {
        return;
    }
    pRootNode = getRootNodeBT(pBinTree);
    if (pRootNode == NULL)
    {
        return;
    }
    pStack = createLinkedStack();
    if (pStack == NULL)
    {
        return;
    }
    pushLSBinTreeNode(pStack, pRootNode);
    while (1)
    {
        if (isLinkedStackEmpty(pStack) == TRUE)
        {
            break;
        }
        else
        {
            pStackNode = peekLS(pStack);
            if (pStackNode != NULL)
            {
                pRootNode = pStackNode->data;

                pLeftChildNode = getLeftChildNodeBT(pRootNode);
                if (pLeftChildNode != NULL && pLeftChildNode->visited == FALSE)
                {
                    pushLSBinTreeNode(pStack, pLeftChildNode);
                }
                else
                {
                    pRightChildNode = getRightChildNodeBT(pRootNode);
                    if (pRightChildNode != NULL && pRightChildNode->visited == FALSE)
                    {
                        pushLSBinTreeNode(pStack, pRightChildNode);
                    }
                    else
                    {
                        pRootNode->visited = TRUE;
                        printf("%c ", pRootNode->data);

                        free(popLS(pStack));
                    }
                }
            } // end-of-if
        }     //end-of-else
    }         //end-of-while
    deleteLinkedStack(pStack);
}

// 반복 레벨 순회
void levelOrderTraversalBinTree(BinTree *pBinTree)
{
    LinkedQueue *pQueue = NULL;
    QueueNode *pQueueNode = NULL;
    BinTree *pSubTree = NULL;
    BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;

    if (pBinTree == NULL)
    {
        return;
    }

    pRootNode = getRootNodeBT(pBinTree);
    if (pRootNode == NULL)
    {
        return;
    }

    pQueue = createLinkedQueue();
    if (pQueue == NULL)
    {
        return;
    }

    // 루트 노드가 처음으로 인큐된다
    enqueueLQBinTreeNode(pQueue, pRootNode);

    while (1)
    {
        // 큐에 더 이상 노드가 없을 때까지 루프를 돈다
        if (isLinkedQueueEmpty(pQueue) == TRUE)
        {
            break;
        }
        else
        {
            // 큐에서 디큐하고, 방문 처리한다
            pQueueNode = dequeueLQ(pQueue);
            if (pQueueNode != NULL)
            {
                pRootNode = pQueueNode->data;
                if (pRootNode != NULL)
                {
                    printf("%c ", pRootNode->data);
                }
                pLeftChildNode = getLeftChildNodeBT(pRootNode);
                pRightChildNode = getRightChildNodeBT(pRootNode);
                if (pLeftChildNode != NULL)
                {
                    // 현재 노드의 왼쪽 자식 노드를 큐에 인큐한다
                    enqueueLQBinTreeNode(pQueue, pLeftChildNode);
                }
                if (pRightChildNode != NULL)
                {
                    // 현재 노드의 오른쪽 자식 노드를 큐에 인큐한다
                    enqueueLQBinTreeNode(pQueue, pRightChildNode);
                }
                free(pQueueNode);
            }
        }
    }
    deleteLinkedQueue(pQueue);
}
