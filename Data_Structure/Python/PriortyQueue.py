# 리스트를 이용한 우선순위 큐 구현

class PriorityQueue:
    def __init__(self):
        self.items = []

    def isEmpty(self):
        return len(self.items) == 0

    def size(self):
        return len(self.items)

    def clear(self):
        self.items = []

    def enqueue(self, items):
        self.items.append(items)

    # 최대 우선순위 항목의 인덱스 반환
    def findMaxIndex(self):
        if self.isEmpty():
            return None
        else:
            highest = 0
            for i in range(1, self.size()):
                if self.items[i] > self.items[highest]:
                    highest = i
            return highest

    def dequeue(self):
        highest = self.findMaxIndex()
        if highest is not None:
            return self.items.pop(highest)

    def peek(self):
        highest = self.findMaxIndex()
        if highest is not None:
            return self.items[highest]


if __name__ == "__main__":
    q = PriorityQueue()
    q.enqueue(34)
    q.enqueue(18)
    q.enqueue(27)
    q.enqueue(45)
    q.enqueue(15)
    print("입력된 순서대로 우선순위 큐에 들어간다")
    print("PQueue: ", q.items)
    print("리스트에서 가장 큰 값을 반환")
    while not q.isEmpty():
        print("Max Priority = ", q.dequeue())
