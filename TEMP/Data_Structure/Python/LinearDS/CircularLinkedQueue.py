# 연결된 큐

# 노드 클래스
class Node:
    def __init__(self, elem, link=None):
        self.data = elem
        self.link = link


class CircularLinkedQueue:
    def __init__(self):
        self.tail = None

    def isEmpty(self):
        return self.tail == None

    def clear(self):
        self.tail = None

    def peek(self):
        if not self.isEmpty():
            return self.tail.link.data

    # 삽입
    def enqueue(self, item):
        node = Node(item, None)
        if self.isEmpty():  # 큐가 공백 상태
            node.link = node
            self.tail = node
        else:
            node.link = self.tail.link
            self.tail.link = node
            self.tail = node

    # 삭제
    def dequeue(self):
        if not self.isEmpty():  # 큐가 하나의 데이터만 가지고 있는 경우
            data = self.tail.link.data
            if self.tail.link == self.tail:
                self.tail = None
            else:  # 큐에 여러개의 데이터가 있는 경우
                self.tail.link = self.tail.link.link
            return data

    # 사이즈
    def size(self):
        if self.isEmpty():
            return 0
        else:
            count = 1
            node = self.tail.link
            while not node == self.tail:
                node = node.link
                count += 1
            return count

    # display
    def display(self, msg="CircularLinkedQueue: "):
        print(msg, end='')
        if not self.isEmpty():
            node = self.tail.link
            while not node == self.tail:
                print(node.data, end=' ')
                node = node.link
            print(node.data, end=' ')
        print()


if __name__ == "__main__":
    q = CircularLinkedQueue()
    for i in range(8):
        q.enqueue(i)
    q.display()
    for i in range(5):
        q.dequeue()
    q.display()
    for i in range(8, 14):
        q.enqueue(i)
    q.display()
