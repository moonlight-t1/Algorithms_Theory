# 삽입 정렬

def print_step(arr, val):
    print("Step %2d = " % val, end='')
    print(arr)


def insertion_sort(A):
    n = len(A)
    for i in range(1, n):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = key
        print_step(A, i)


if __name__ == "__main__":
    data = [5, 3, 8, 4, 9, 2, 1, 6, 2, 7]
    print("Before Sorted: ", data)
    insertion_sort(data)
    print("After Sorted: ", data)
