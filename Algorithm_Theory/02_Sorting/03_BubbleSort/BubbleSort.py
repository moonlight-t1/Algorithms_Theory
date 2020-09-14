def print_step(arr, val):
    print("Step %2d : " % val, end='')
    print(arr)


# 버블 정렬
def bubble_sort(A):
    n = len(A)
    for i in range(n - 1, 0, -1):
        bChanged = False
        for j in range(i):
            if (A[j] > A[j + 1]):
                A[j], A[j + 1] = A[j + 1], A[j]  # Swap
                bChanged = True  # 교환이 발생
        if not bChanged:  # 교환이 없으면 종료
            break
        print_step(A, n - 1)


data = [5, 3, 8, 4, 9, 1, 6, 2, 7]
print("Original : ", data)
bubble_sort(data)
print("Sorted : ", data)
