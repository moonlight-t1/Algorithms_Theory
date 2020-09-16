# 스택

class Stack:
    def __init__(self):
        self.top = []

    def isEmpty(self):
        return len(self.top) == 0

    def size(self):
        return len(self.top)

    def clear(self):
        self.top = []

    def push(self, item):
        self.top.append(item)

    def pop(self):
        if not self.isEmpty():
            return self.top.pop(-1)

    def peek(self):
        if not self.isEmpty():
            return self.top[-1]

    def __str__(self):
        return str(self.top[::-1])  # 역순으로 출력


if __name__ == "__main__":
    # 스택 객체 생성
    odd = Stack()
    even = Stack()

    for i in range(10):
        if i % 2 == 0:
            even.push(i)
        else:
            odd.push(i)

    # 리스트 객체 출력
    print(odd.top)
    print(even.top)

    for _ in range(2):
        even.pop()
    for _ in range(2):
        odd.pop()

    print("After Pop: ")
    print(odd.top)
    print(even.top)

    print("Using __str__ print: ")
    print(odd)
    print(even)
