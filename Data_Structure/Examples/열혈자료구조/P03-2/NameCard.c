#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

// 새 카드 만들기
NameCard *MakeNameCard(char *name, char *phone)
{
    NameCard *newCard = (NameCard *)malloc(sizeof(NameCard));
    strcpy(newCard->name, name);
    strcpy(newCard->phone, phone);
    return newCard;
}

// 카드 정보 출력
void ShowNameCardInfo(NameCard *pcard)
{
    printf("Name : %s\n", pcard->name);
    printf("Phone : %s\n", pcard->phone);
}

// 전화번호 변경
void ChangePhoneNum(NameCard *pcard, char *phone)
{
    strcpy(pcard->phone, phone);
}

// 이름 비교
int NameCompare(NameCard *pcard, char *name)
{
    return (strcmp(pcard->name, name));
}