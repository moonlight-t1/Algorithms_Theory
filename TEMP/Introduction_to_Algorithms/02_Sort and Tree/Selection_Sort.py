# 선택 정렬
def selection_sort(A):
    n = len(A)
    for i in range(n - 1):
        least = i  # 최소값 인덱스
        for j in range(i + 1, n):
            if (A[j] < A[least]):
                least = j
        A[i], A[least] = A[least], A[i]  # Swap
        printStep(A, i + 1)


def printStep(arr, val):
    print("  Step %2d = " % val, end='')
    print(arr)


data = [5, 3, 8, 4, 9, 1, 6, 2, 7]
print("Original : ", data)
selection_sort(data)
print("Selection : ", data)
