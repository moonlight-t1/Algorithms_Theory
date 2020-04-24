#ifndef _EXPR_DEF_
#define _EXPR_DEF_

// 연산자들의 종류(type)
typedef enum PrecedenceType
{
    lparen,
    rparen,
    times,
    divide,
    plus,
    minus,
    operand
} Precedence;

typedef struct ExprTokenType
{
    float value;
    Precedence type;
} ExprToken;

#endif