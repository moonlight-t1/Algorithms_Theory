// 연결리스트 입력을 받으면 맨 앞에 노드를 추가

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node *next;
} Node;

int main(void)
{
    Node *head = NULL; // NULL 포인터 초기화
    Node *tail = NULL;
    Node *cur = NULL;

    Node *newNode = NULL;
    int readData;

    // 데이터 입력
    while (1)
    {
        printf("자연수 입력: ");
        scanf("%d", &readData);
        if (readData < 1)
            break;

        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else // 맨 앞에 노드 추가
        {
            newNode->next = head;
            head = newNode;
        }
    }
    printf("\n");

    // 데이터 출력
    printf("PRINT DATA \n");
    if (head == NULL)
    {
        printf("Does not exist \n");
    }
    else
    {
        cur = head;
        printf("%d  ", cur->data); // 첫 번째 데이터 출력

        while (cur->next != NULL) // 두 번째 이후의 데이터 출력
        {
            cur = cur->next;
            printf("%d  ", cur->data);
        }
    }
    printf("\n\n");

    // 메모리 해제
    if (head == NULL)
    {
        return 0; // 해제할 노드가 존재하지 않는다.
    }
    else
    {
        Node *delNode = head;
        Node *delNextNode = head->next;

        printf("Delete %d\n", head->data);
        free(delNode); // 첫 번째 노드의 삭제

        while (delNextNode != NULL) // 두 번째 이후의 노드 삭제 위한 반복문
        {
            delNode = delNextNode;
            delNextNode = delNextNode->next;

            printf("Delete %d\n", delNode->data);
            free(delNode); // 두 번째 이후의 노드 삭제
        }
    }

    return 0;
}