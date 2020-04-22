#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

int main(int argc, char *argv)
{
    int i = 0;
    int arrayCount = 0;
    CircularList *pList = NULL;
    CircularListNode *pNode = NULL;
    CircularListNode node;

    pList = createCircularList();

    // 리스트가 정상적으로 생성되었는지 점검
    if (pList != NULL)
    {
        node.data = 1;
        addCLElement(pList, 0, node);

        node.data = 3;
        addCLElement(pList, 1, node);

        node.data = 5;
        addCLElement(pList, 2, node);
        displayCircularList(pList);

        removeCLElement(pList, 0);
        displayCircularList(pList);

        deleteCircularList(pList);
    }

    return 0;
}