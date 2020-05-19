#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "exprLinkedStack.h"
#include "StackCalc.h"

// 스택 푸시 함수 pushLS()를 편하게 사용하기 위한 함수
int pushLSExprToken(LinkedStack *pStack, ExprToken data)
{
    // 임시로 StackNode 변수 node를 만들어 함수 pushLS 호출
    StackNode node = {
        0,
    };
    node.data = data;
    return pushLS(pStack, node);
}

// 후위 표식 계산
void calcExpr(ExprToken *pExprTokens, int tokenCount)
{
    LinkedStack *pStack = NULL;
    StackNode *pNode1 = NULL, *pNode2 = NULL;
    Precedence tokenType;
    int i = 0;

    // 소스 토큰 배열이 NULL인지 점검
    if (pExprTokens == NULL)
    {
        return;
    }

    // 스택 생성 및 점검
    pStack = createLinkedStack();
    if (pStack != NULL)
    {
        // 토큰 배열의 크기(토큰 개수)만큼 루프를 돌면서 수식을 계산한다
        for (i = 0; i < tokenCount; i++)
        {
            tokenType = pExprTokens[i].type;

            // (1) 피연산자를 만나면 스택에 푸시한다
            if (tokenType == operand)
            {
                pushLSExprToken(pStack, pExprTokens[i]);
            }
            // 연산자를 만났을 떄의 처리
            else
            {
                pNode2 = popLS(pStack);
                if (pNode2 != NULL)
                {
                    // (2) 연산에 필요한 갯수만큼, 2개의 피연산자를 스택에서 팝한다
                    pNode1 = popLS(pStack);
                    if (pNode1 != NULL)
                    {
                        float op1 = pNode1->data.value;
                        float op2 = pNode2->data.value;

                        ExprToken newToken;
                        newToken.type = operand;
                        // 연산자의 종류에 따라 연산을 실시한다.
                        switch (tokenType)
                        {
                        case plus:
                            newToken.value = op1 + op2;
                            break;
                        case minus:
                            newToken.value = op1 - op2;
                            break;
                        case times:
                            newToken.value = op1 * op2;
                            break;
                        case divide:
                            newToken.value = op1 / op2;
                            break;
                        }

                        // (3) 연산한 결과는 다시 스택에 푸시한다
                        pushLSExprToken(pStack, newToken);
                        free(pNode1);
                    }
                    free(pNode2);
                }
            } // end-of-else
        }
        pNode1 = popLS(pStack); // 수식의 최종 처리 결과 값을 스택에서 팝한다
        if (pNode1 != NULL)
        {
            printf("Result : [%f]\n", pNode1->data.value);
            free(pNode1);
        }
        else
        {
            printf("Error. Equation has an error.\n");
        }
        deleteLinkedStack(pStack);
    }
}

// 중위 표기법을 후위 표기법으로
void convertInfixToPostfix(ExprToken *pExprTokens, int tokenCount)
{
    LinkedStack *pStack = NULL;
    StackNode *pNode = NULL;
    Precedence tokenType;
    Precedence inStoackTokenType;
    int i = 0;

    // 소스 토큰 배열이 NULL인지 점검
    if (pExprTokens == NULL)
        return;

    // 스택 생성 및 점검
    pStack = createLinkedStack();
    if (pStack != NULL)
    {
        // 토큰 배열의 크기(토큰 개수)만큼 루프를 돌면서 수식을 변환
        for (i = 0; i < tokenCount; i++)
        {
            tokenType = pExprTokens[i].type;
            switch (tokenType)
            {
            // (1) 피연산자를 만나면 바로 출력
            case operand:
                printf("%f\n", pExprTokens[i].value);
                break;

            // (5) 닫는 괄호 연산자를 만난 경우 처리
            // 여는 괄호를 만날 때까지 while 루프를ㄷ 돌면서
            // 스택 안의 연산자들을 팝하고 출력한다
            case rparen:
                pNode = popLS(pStack);
                while (pNode != NULL && pNode->data.type != lparen)
                {
                    printToken(pNode->data);
                    free(pNode);

                    pNode = popLS(pStack);
                }

                if (pNode != NULL)
                    free(pNode);
                break;

            // (2) (3) (4) 닫는 괄호 연산자 이외의 연산자인 경우 처리
            default:
                while (isLinkedStackEmpty(pStack) == FALSE)
                {
                    inStoackTokenType = peekLS(pStack)->data.type;
                    // 스택 내에 저장된 연산자들 중 현재 연산자보다 우선순위가
                    // 높은 연산자는 팝(pop) & 출력을 한다
                    if (outStackPrecedence(tokenType) <= inStackPrecedence(inStoackTokenType))
                    {
                        pNode = popLS(pStack);
                        if (pNode != NULL)
                        {
                            printToken(pNode->data);
                            free(pNode);
                        }
                    }
                    else
                    {
                        break;
                    }
                }
                // 현재 연산자를 스택에 푸시
                pushLSExprToken(pStack, pExprTokens[i]);
                break;
            } // end-of-switch
        }     // end-of-for

        // 스택에 남아있는 연산자들을 팝하고 출력한다
        while (isLinkedStackEmpty(pStack) == FALSE)
        {
            pNode = popLS(pStack);
            if (pNode != NULL)
            {
                printToken(pNode->data);
                free(pNode);
            }
        }
        deleteLinkedStack(pStack);
    }
}

// 스택 안에서의 연산자 우선순위 반환
int inStackPrecedence(Precedence oper)
{
    switch (oper)
    {
    case lparen:
        return 0;
    case rparen:
        return 4;
    case times:
    case divide:
        return 2;
    case plus:
    case minus:
        return 1;
    }
    return -1;
}

// 스택 밖에서의 연산자 우선순위 반환
int outStackPrecedence(Precedence oper)
{
    switch (oper)
    {
    case lparen:
        return 5;
    case rparen:
        return 4;
    case times:
    case divide:
        return 2;
    case plus:
    case minus:
        return 1;
    }
    return -1;
}

void printToken(ExprToken element)
{
    switch (element.type)
    {
    case lparen:
        printf("(\n");
        break;
    case rparen:
        printf(")\n");
        break;
    case plus:
        printf("+\n");
        break;
    case minus:
        printf("-\n");
        break;
    case times:
        printf("*\n");
        break;
    case divide:
        printf("/\n");
        break;
    case operand:
        printf("%f\n", element.value);
        break;
    }
}