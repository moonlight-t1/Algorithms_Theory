#include <stdio.h>
#include "DummyLinkedList.h"
#include "Point.h"

// 정렬 기준 함수
int WhoIsPrecede(Point *d1, Point *d2)
{
    if (d1->xpos < d2->xpos) // x 좌표 기준으로 오름차순 정렬
        return 0;
    else if (d1->xpos == d2->xpos) // x 좌표가 같다면 y 좌표를 기준
    {
        if (d1->ypos < d2->ypos)
            return 0;
        else
            return 1;
    }
    else
        return 1;
}

int main(void)
{
    // List의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);

    SetSortRule(&list, WhoIsPrecede);

    // 5개의 데이터 저장
    LInsert(&list, 11);
    LInsert(&list, 11);
    LInsert(&list, 22);
    LInsert(&list, 22);
    LInsert(&list, 33);

    // 저장된 데이터의 전체 출력
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");

    // 숫자 22을 검색하여 모두 삭제
    if (LFirst(&list, &data))
    {
        if (data == 22)
            LRemove(&list);

        while (LNext(&list, &data))
        {
            if (data == 22)
                LRemove(&list);
        }
    }

    // 삭제 후 저장된 데이터 전체 출력
    printf("현재 데이터의 수: %d \n", LCount(&list));

    if (LFirst(&list, &data))
    {
        printf("%d ", data);

        while (LNext(&list, &data))
            printf("%d ", data);
    }
    printf("\n\n");
    return 0;
}