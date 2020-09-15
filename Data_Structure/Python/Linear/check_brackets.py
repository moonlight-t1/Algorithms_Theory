# 스택 응용 : 괄호 검사

from Stack import *


def check_brackets(statement):
    stack = Stack()
    for ch in statement:
        if ch in ('{', '[', '('):
            stack.push(ch)
        elif ch in ('}', ']', ')'):
            if stack.isEmpty():
                return False
            else:
                left = stack.pop()
                if (ch == '}' and left != "{") or (ch == ']' and left != '[') or (ch == ')' and left != '('):
                    return False

    return stack.isEmpty()


if __name__ == "__main__":
    str = ("{A[(i + 1)]}", "if((i == 0) && (j == 0)", "A[(i + !])=0")
    for s in str:
        m = check_brackets(s)
        print(s, " ---> ", m)
