#include <stdio.h>
#include <stdlib.h>
#include "DoublyList.h"

int main(int argc, char *argv[])
{
    int i = 0;
    int arrayCount = 0;
    DoublyList *pList = NULL;
    DoublyListNode *pNode = NULL;
    DoublyListNode node;

    pList = createDoublyList();

    // 리스트가 정상적으로 생성되었는지 점검
    if (pList != NULL)
    {
        node.data = 1;
        addDLElement(pList, 0, node);

        node.data = 3;
        addDLElement(pList, 1, node);

        node.data = 5;
        addDLElement(pList, 2, node);
        displayDoublyList(pList);

        removeDLElement(pList, 0);
        displayDoublyList(pList);

        deleteDoublyList(pList);
    }

    return 0;
}