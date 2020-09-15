# 덱

from CircularQueue import *


class CircularDeque(CircularQueue):
    def __init__(self):
        super().__init__()

    def addRear(self, item):
        self.enqueue(item)

    def deleteFront(self):
        return self.dequeue()

    def getFront(self):
        return self.peek()

    # 전단 삽입
    def addFront(self, item):
        if not self.isFull():
            self.items[self.front] = item
            self.front = self.front - 1
            if self.front < 0:
                self.front = MAX_QSIZE - 1

    # 후단 삭제
    def deleteRear(self):
        if not self.isEmpty():
            item = self.items[self.rear]
            self.rear = self.rear - 1
            if self.rear < 0:
                self.rear = MAX_QSIZE - 1
            return item

    # 후단 peek
    def getRear(self):
        return self.items[self.rear]


if __name__ == "__main__":
    dq = CircularDeque()
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
