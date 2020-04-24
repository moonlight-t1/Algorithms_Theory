#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

void displayLinkedStack(LinkedStack *pStack)
{
    StackNode *pNode = NULL;
    int i = 0;
    if (pStack != NULL)
    {
        printf("Current Number of Nodes : %d\n", pStack->currentElementCount);

        pNode = pStack->pTopElement;
        while (pNode != NULL)
        {
            printf("[%d] - [%c]\n", pStack->currentElementCount - i, pNode->data);
            i++;
            pNode = pNode->pLink;
        }
    }
}

int main(int argc, char *argv[])
{
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;
    char value = 0;

    pStack = createLinkedStack(6);
    if (pStack != NULL)
    {
        StackNode node1 = {'A'};
        StackNode node2 = {'B'};
        StackNode node3 = {'C'};
        StackNode node4 = {'D'};

        pushLS(pStack, node1);
        pushLS(pStack, node2);
        pushLS(pStack, node3);
        pushLS(pStack, node4);
        displayLinkedStack(pStack);

        pNode = popLS(pStack);
        if (pNode != NULL)
        {
            printf("Pop >> [%c]\n", pNode->data);
            free(pNode);
        }
        else
        {
            printf("Pop >> NULL\n");
        }
        displayLinkedStack(pStack);

        pNode = peekLS(pStack);
        if (pNode != NULL)
        {
            printf("Peek >> [%c]\n", pNode->data);
        }
        else
        {
            printf("Peek >> NULL\n");
        }
        displayLinkedStack(pStack);

        deleteLinkedStack(pStack);
    }
    return 0;
}