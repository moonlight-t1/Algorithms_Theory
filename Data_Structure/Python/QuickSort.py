def partition(A, left, right):
    low = left + 1
    high = right
    pivot = A[left]  # 피벗 설정
    while (low <= high):  # low와 high가 역전되지 않는 한 반복
        while low <= right and A[low] < pivot:
            low += 1
        while high >= left and A[high] > pivot:
            high -= 1

        if low < high:
            A[low], A[high] = A[high], A[low]

    A[left], A[high] = A[high], A[left]
    return high  # 피벗의 위치 반환


def quick_sort(A, left, right):
    if left < right:
        q = partition(A, left, right)
        quick_sort(A, left, q - 1)
        quick_sort(A, q + 1, right)


if __name__ == "__main__":
    l = [5, 3, 8, 4, 9, 1, 6, 2, 7]
    print("Original : ", l)
    quick_sort(l, 0, 7)
    print(l)
