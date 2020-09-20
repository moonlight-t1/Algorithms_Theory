def heapify(arr, n, i):
    largest = i  # 1번째가 가장 크다고 한다.
    l = 2 * i + 1  # 왼쪽 자식: left = 2 * i + 1
    r = 2 * i + 2  # 오른쪽 자식: right = 2 * i + 2

    if l < n and arr[i] < arr[l]:  # 교환조건 검사
        largest = l
    if r < n and arr[largest] < arr[r]:  # 교환조건 검사
        largest = r
    if largest != i:  # 교환이 필요하면 교환
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)


def heap_sort(arr):
    n = len(arr)
    print("최대 힙을 만드는 과정")
    print("i = ", 0, arr)
    for i in range(n // 2, -1, -1):  # 최대 힙을 만든다
        heapify(arr, n, i)
        print("i = ", i, arr)
    print()

    print("최대 힙에서 맨 앞의 항목을 계속 꺼내 정렬하는 과정")
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)
        print("i = ", i, arr)


if __name__ == "__main__":
    l = [5, 3, 8, 4, 9, 1, 6, 2, 7]
    print("Original : ", l)
    heap_sort(l)
    print(l)
