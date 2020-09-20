# 힙을 이용한 정렬

from MaxHeap import *


def heap_sort(data):
    heap = MaxHeap()
    for n in data:
        heap.insert(n)

    for i in range(1, len(data) + 1):
        data[-i] = heap.delete()


if __name__ == "__main__":
    l = [5, 3, 8, 4, 9, 1, 6, 2, 7]
    print("Original : ", l)
    heap_sort(l)
    print(l)
