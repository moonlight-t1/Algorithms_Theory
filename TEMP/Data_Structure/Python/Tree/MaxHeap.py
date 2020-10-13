# 최대 힙
class MaxHeap:
    def __init__(self):
        self.heap = []
        self.heap.append(0)

    def size(self): return len(self.heap) - 1
    def isEmpty(self): return self.size() == 0
    def parent(self, i): return self.heap[i // 2]  # 부모 노드 반환
    def left(self, i): return self.heap[i * 2]  # 왼쪽 자식 노드 반환
    def right(self, i): return self.heap[i * 2 + 1]  # 오른쪽 자식 반환

    def display(self, msg="힙 트리: "):
        print(msg, self.heap[1:])

    # 삽입
    def insert(self, n):
        self.heap.append(n)
        i = self.size()
        while (i != 1 and n > self.parent(i)):  # 부모보다 큰 동안 계속 업
            self.heap[i] = self.parent(i)  # 부모를 끌어 내린다
            i = i // 2
        self.heap[i] = n

    # 삭제
    def delete(self):
        parent = 1
        child = 2
        if not self.isEmpty():
            hroot = self.heap[1]
            last = self.heap[self.size()]
            while (child <= self.size()):
                # 오른쪽 노드가 더 크면 child를 1증가
                if child < self.size() and self.left(parent) < self.right(parent):
                    child += 1
                if last >= self.heap[child]:  # 더 큰 자식이 더 작으면
                    break
                self.heap[parent] = self.heap[child]
                parent = child
                child *= 2

            self.heap[parent] = last  # 맨 마지막 노드를 parent 위치에 복사
            self.heap.pop(-1)
            return hroot


if __name__ == "__main__":
    heap = MaxHeap()
    data = [2, 5, 4, 8, 9, 3, 7, 3]
    print("[삽입 연산]: ", data)

    for elem in data:
        heap.insert(elem)

    heap.display('[삽입 후]: ')
    heap.delete()
    heap.display('[삭제 후]: ')
    heap.delete()
    heap.display('[삭제 후]: ')
