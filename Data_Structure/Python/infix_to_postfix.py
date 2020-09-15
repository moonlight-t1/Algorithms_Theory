#  스택 응용 : 중위표기식의 후위 변환 구현

from Stack import *
from eval_postfix import *


# 연산자 우선순위 반환
def precedence(op):
    if op == '(' or op == ')':
        return 0
    elif op == '+' or op == '-':
        return 1
    elif op == '*' or op == '/':
        return 2
    else:
        return -1


# 중위표기식 -> 후위표기식
def infix_to_postfix(expr):
    s = Stack()
    output = []
    for term in expr:
        if term in '(':  # 여는 괄호이면
            s.push('(')
        elif term in ')':  # 닫는 괄호이면
            while not s.isEmpty():
                op = s.pop()
                if op == '(':  # 여는 괄호가 나올때까지 스택에서 연산자 꺼내 ouput에 append
                    break
                else:
                    output.append(op)
        elif term in "+-*/":  # 연산자이면
            while not s.isEmpty():  # 우선순위가 높거나 같은 연산다들을 스택에서 모두 꺼낸다
                op = s.peek()
                if (precedence(term) <= precedence(op)):
                    output.append(op)
                    s.pop()
                else:
                    break
            s.push(term)  # 마지막으로 현재 연산자 삽입
        else:
            output.append(term)  # 피연산자이면 바로 출력

    while not s.isEmpty():  # 스택에 남은 항목들 append
        output.append(s.pop())

    return output


if __name__ == "__main__":
    infix1 = "8 / 2 - 3 + ( 3 * 2 )".split()
    infix2 = "1 / 2 * 4 * ( 1 / 4 ) ".split()
    postfix1 = infix_to_postfix(infix1)
    postfix2 = infix_to_postfix(infix2)
    result1 = eval_postfix(postfix1)
    result2 = eval_postfix(postfix2)
    print("중위표기1: ", infix1)
    print("후위표기1: ", postfix1)
    print("계산결과: ", result1, end='\n\n')

    print("중위표기2: ", infix2)
    print("후위표기2 ", postfix2)
    print("계산결과: ", result2)
