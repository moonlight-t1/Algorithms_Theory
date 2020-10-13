#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
    List list;
    NameCard *pcard;
    ListInit(&list);

    pcard = MakeNameCard("Lee Jin Soo", "010-1111-2222");
    LInsert(&list, pcard);

    pcard = MakeNameCard("Han Ji Young", "010-2222-5555");
    LInsert(&list, pcard);

    pcard = MakeNameCard("Cho Soo Jin", "010-3333-7777");
    LInsert(&list, pcard);

    // Han Ji Young의 정보를 조회하여 출력
    if (LFirst(&list, &pcard))
    {
        if (!NameCompare(pcard, "Han Ji Young"))
        {
            ShowNameCardInfo(pcard);
        }
        else
        {
            while (LNext(&list, &pcard))
            {
                if (!NameCompare(pcard, "Han Ji Young"))
                {
                    ShowNameCardInfo(pcard);
                    break;
                }
            }
        }
    }

    // Lee Jin Soo의 정보를 변경
    if (LFirst(&list, &pcard))
    {
        if (!NameCompare(pcard, "Lee Jin Soo"))
        {
            ChangePhoneNum(pcard, "010-9999-9999");
        }
        else
        {
            while (LNext(&list, &pcard))
            {
                if (!NameCompare(pcard, "Lee Jin Soo"))
                {
                    ChangePhoneNum(pcard, "010-9999-9999");
                    break;
                }
            }
        }
    }

    // Cho Soo Jin의 정보를 삭제
    if (LFirst(&list, &pcard))
    {
        if (!NameCompare(pcard, "Cho Soo Jin"))
        {
            pcard = LRemove(&list);
            free(pcard);
        }
        else
        {
            while (LNext(&list, &pcard))
            {
                if (!NameCompare(pcard, "Cho Soo Jin"))
                {
                    pcard = LRemove(&list);
                    free(pcard);
                    break;
                }
            }
        }
    }

    // 모든 사람의 정보 출력
    printf("Current number of data: %d \n", LCount(&list));

    if (LFirst(&list, &pcard))
    {
        ShowNameCardInfo(pcard);

        while (LNext(&list, &pcard))
            ShowNameCardInfo(pcard);
    }

    return 0;
}