# 버블 정렬

def print_step(arr, val):
    print("Step %2d = " % val, end='')
    print(arr)


def bubble_sort(A):
    n = len(A)
    for i in range(n - 1, 0, -1):
        changed = False
        for j in range(i):
            if (A[j] > A[j + 1]):
                A[j], A[j + 1] = A[j + 1], A[j]
                changed = True
        if not changed:
            break
        print_step(A, n - i)


if __name__ == "__main__":
    data = [5, 3, 8, 4, 9, 2, 1, 6, 2, 7]
    print("Before Sorted: ", data)
    bubble_sort(data)
    print("After Sorted: ", data)
