# 선택 정렬

def print_step(arr, val):
    print("Step %2d = " % val, end='')
    print(arr)


def selection_sort(A):
    n = len(A)
    for i in range(n - 1):
        least = i
        for j in range(i + 1, n):
            if (A[j] < A[least]):
                least = j
        A[j], A[least] = A[least], A[j]
        print_step(A, i + 1)


if __name__ == "__main__":
    data = [5, 3, 8, 4, 9, 2, 1, 6, 2, 7]
    print("Before Sorted: ", data)
    selection_sort(data)
    print("After Sorted: ", data)
