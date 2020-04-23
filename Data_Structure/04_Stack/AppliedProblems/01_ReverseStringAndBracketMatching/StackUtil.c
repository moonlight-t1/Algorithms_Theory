#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedStack.h"
#include "StackUtil.h"

char *reverseString(char *pSource)
{
    char *pReturn = NULL;
    int i = 0, size = 0;
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;

    // 전처리(preprocessing)
    if (pSource == NULL)
    {
        return NULL;
    }

    // 소스 문자열의 길이가 0인지 점검
    size = strlen(pSource);
    if (size == 0)
    {
        return NULL;
    }

    // 결과 문자열 메모리 할당 및 점검
    pReturn = (char *)malloc(sizeof(char) * (size + 1));
    if (pReturn == NULL)
    {
        printf("Error. Memory Allocation Failed. reverseString()\n");
        return NULL;
    }

    // 스택 생성
    pStack = createLinkedStack();
    if (pStack != NULL)
    {
        StackNode node;

        // 문자열의 문자들을 스택에 푸시
        for (i = 0; i < size; i++)
        {
            node.data = pSource[i];
            pushLS(pStack, node);
        }

        // 스택에서 팝을 하여, 역순 문자열 생성
        for (i = 0; i < size; i++)
        {
            pNode = popLS(pStack);
            if (pNode != NULL)
            {
                if (pNode != NULL)
                {
                    pReturn[i] = pNode->data;
                    free(pNode);
                }
            }
        }
        pReturn[i] = '\0'; // 결과 문자열의 마지막에 널문자 대입

        deleteLinkedStack(pStack);
    }
    // 스택 생성 오류 처리
    else
    {
        if (pReturn != NULL)
        {
            free(pReturn);
            pReturn = NULL;
        }
    }
    return pReturn;
}

int checkBracketMatching(char *pSource)
{
    int ret = TRUE, i = 0, size = 0;
    char symbol = '\0', checkSymbol = '\0';
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;

    // 소스 문자열이 NULL 인지 점검
    if (pSource == NULL)
    {
        ret = TRUE;
        return ret;
    }

    // 소스 문자열의 길이가 0인지 점검
    size = strlen(pSource);
    if (size == 0)
    {
        ret = TRUE;
        return ret;
    }

    // 스택 생성 및 점검
    pStack = createLinkedStack();
    if (pStack != NULL)
    {
        StackNode node;
        // 수식 문자열을 한 글자씩 읽어나간다.
        // 조건에 의해 ret==FALSE이면 루프를 빠져나간다.
        // 수식에 오류가 있으면 더 이상 검사할 필요가 없기 때문이다.
        for (i = 0; i < size && ret == TRUE; i++)
        {
            symbol = pSource[i];
            switch (symbol)
            {
            case '(':
            case '[':
            case '{':
                // 읽어 들인 문자가 여는 괄호이면 스택에 푸시
                node.data = symbol;
                pushLS(pStack, node);
                break;
            case ')':
            case ']':
            case '}':
                // 읽어들인 문자가 닫는 괄호이면 스택에서 팝
                pNode = popLS(pStack);
                // 만약 팝 된 문자가 없다면 오류가 발생
                // 여는 괄호와 닫는 괄호의 갯수가 맞지 않는 경우이다.
                if (pNode == NULL)
                {
                    ret = FALSE;
                    break;
                }
                // 팝된 문자 checkSymbol이 앞서 읽어 들인 여는 괄호 symbol과 맞는 닫는 괄호인지 점검
                else
                {
                    checkSymbol = pNode->data;
                    if ((symbol == ')' && checkSymbol == '(') || (symbol == ']' && checkSymbol == '[') || (symbol == '}' && checkSymbol == '{'))
                    {
                        // Right Code. do nothing
                    }
                    // 만약 맞지 않는다면 오류가 발생한 경우이다
                    else
                    {
                        ret = FALSE;
                    }
                    free(pNode); // 팝 된 노드에 대한 메모리 해제
                }
                break;
            } // end-of-switch
        }     // end-of-for
        // 스택에 남아 있는 노드가 있으면 오류
        // 여는 과롷와 닫는괄호의 갯수가 맞지 않는 경우이다.
        if (isLinkedStackEmpty(pStack) == FALSE)
        {
            ret = FALSE;
        }
        deleteLinkedStack(pStack);
    }
    else
    {
        printf("Error. LinkedStack is NULL. checkBracketMatching()\n");
        ret = FALSE;
    }
    return ret;
}