#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "LinkedListOP.h"

int main(int argc, char *argv[])
{
    int i = 0;
    int arrayCount = 0;
    LinkedList *pListA = NULL, *pListB = NULL;
    ListNode node;

    pListA = createLinkedList();
    pListB = createLinkedList();

    // 리스트가 정상적으로 생성되었는지 점검
    if (pListA != NULL && pListB != NULL)
    {
        node.data = 1;
        AddLLElement(pListA, 0, node);
        node.data = 2;
        AddLLElement(pListA, 1, node);
        node.data = 3;
        AddLLElement(pListA, 2, node);

        node.data = 1;
        node.data = 4;
        AddLLElement(pListB, 0, node);
        node.data = 5;
        AddLLElement(pListB, 1, node);

        printf("<List A>\n");
        iteratedLinkedList(pListA);
        printf("<List B>\n");
        iteratedLinkedList(pListB);

        // 리스트B를 리스트A에 붙이기
        concatLinekdList(pListA, pListB);
        printf("After concatLinkedList()\n");
        iteratedLinkedList(pListA);
        iteratedLinkedList(pListB);

        // 리스트 A를 역순 만들기
        reverseLinkedList(pListA);
        printf("After reverseLinkedList()\n");
        iteratedLinkedList(pListA);

        deleteLinkedList(pListA);
        deleteLinkedList(pListB);
    }
    return 0;
}