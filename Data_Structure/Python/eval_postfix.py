# 스택 응용: 후위표기 수식 계산 구현

from Stack import *


def eval_postfix(expr):
    s = Stack()
    for token in expr:
        if token in "+-*/":
            val2 = s.pop()
            val1 = s.pop()
            if (token == "+"):
                s.push(val1 + val2)
            elif (token == "-"):
                s.push(val1 - val2)
            elif (token == "*"):
                s.push(val1 * val2)
            elif (token == "/"):
                s.push(val1 / val2)
        else:
            s.push(float(token))
    return s.pop()


if __name__ == "__main__":
    expr1 = "8 2 / 3 - 3 2 * +".split()
    expr2 = "1 2 / 4 * 1 4 / *".split()
    print(expr1, " ---> ", eval_postfix(expr1))
    print(expr2, " ---> ", eval_postfix(expr2))
