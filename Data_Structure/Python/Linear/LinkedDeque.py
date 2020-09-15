# 연결된 덱

class DNode:
    def __init__(self, elem, prev=None, next=None):
        self.data = elem
        self.prev = prev
        self.next = next


class DoublyLinkedDeque:
    def __init__(self):
        self.front = None
        self.rear = None

    def isEmpty(self):
        return self.front == None

    def clear(self):
        self.front = self.rear = None

    def size(self):
        n = self.front
        count = 0
        while not n == None:
            n = n.next
            count += 1
        return count

    def display(self, msg="LinkedStack: "):
        print(msg, end='')
        n = self.front
        while not n == None:
            print(n.data, end=' ')
            n = n.next
        print()

    # 전단 삽입
    def addFront(self, item):
        node = DNode(item, None, self.front)
        if (self.isEmpty()):
            self.front = self.rear = node
        else:
            self.front.prev = node
            self.front = node

    # 후단 삽입
    def addRear(self, item):
        node = DNode(item, self.rear, None)
        if (self.isEmpty()):
            self.front = self.rear = node
        else:
            self.rear.next = node
            self.rear = node

    # 전단 삭제
    def deleteFront(self):
        if not self.isEmpty():
            data = self.front.data
            self.front = self.front.next
            if self.front == None:
                self.rear = None
            else:
                self.front.prev = None
            return data

    # 후단 삭제
    def deleteRear(self):
        if not self.isEmpty():
            data = self.rear.data
            self.rear = self.rear.prev
            if self.rear == None:
                self.front = None
            else:
                self.rear.next = None
            return data


if __name__ == "__main__":
    dq = DoublyLinkedDeque()
    for i in range(9):
        if i % 2 == 0:
            dq.addRear(i)
        else:
            dq.addFront(i)
    dq.display()

    for i in range(2):
        dq.deleteFront()
    for i in range(2):
        dq.deleteRear()
    dq.display()

    for i in range(9, 14):
        dq.addFront(i)
    dq.display()
