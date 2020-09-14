def print_step(arr, val):
    print("Step %2d : " % val, end='')
    print(arr)


# 선택 정렬
def insertion_sort(A):
    n = len(A)
    for i in range(1, n):
        key = A[i]
        j = i - 1
        while j >= 0 and A[j] > key:
            A[j + 1] = A[j]  # 항목들을 뒤로 한 칸씩 이동
            j -= 1
        A[j + 1] = key  # 항목 삽입
        print_step(A, i)


data = [5, 3, 8, 4, 9, 1, 6, 2, 7]
print("Original : ", data)
insertion_sort(data)
print("Sorted : ", data)
