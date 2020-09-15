# Linked List로 구현한 Linked Stack

# 노드 클래스
class Node:
    def __init__(self, elem, link=None):
        self.data = elem
        self.link = link


# 링크드 스택
class LinkedStack:
    def __init__(self):
        self.top = None

    def isEmpty(self):
        return self.top == None

    def clear(self):
        self.top = None

    def push(self, item):
        n = Node(item, self.top)  # 노드 생성 및 n의 링크가 새 노드를 가리키게 한다
        self.top = n  # n이 새로운 top이 된다

    def pop(self):
        if not self.isEmpty():
            n = self.top  # 변수 n이 top을 가리킨다
            self.top = n.link  # 새로운 탑은 n의 이전 노드가 된다
            return n.data

    def peek(self):
        if not self.isEmpty():
            return self.top.data

    def size(self):
        n = self.top
        count = 0
        while not n == None:
            n = n.link
            count += 1
        return count

    def display(self, msg="LinkedStack: "):
        print(msg, end='')
        n = self.top
        while not n == None:
            print(n.data, end=' ')
            n = n.link
        print()


if __name__ == "__main__":
    odd = LinkedStack()
    even = LinkedStack()
    for i in range(10):
        if i % 2 == 0:
            even.push(i)
        else:
            odd.push(i)

    # 리스트 객체 출력
    odd.display()
    even.display()

    for _ in range(2):
        even.pop()
    for _ in range(2):
        odd.pop()

    print("After Pop: ")
    odd.display()
    even.display()
