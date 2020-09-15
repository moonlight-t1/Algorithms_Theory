# 순환 구조 이진 탐색
def binary_search(A, key, low, high):
    if (low <= high):
        middle = (low + high) // 2
        if key == A[middle]:
            return middle
        elif (key < A[middle]):
            return binary_search(A, key, low, middle - 1)
        else:
            return binary_search(A, key, middle + 1, high)
    return None


# 반복 구조 이진 탐색
def binary_search_iter(A, key, low, high):
    while (low <= high):
        middle = (low + high) // 2
        if key == A[middle]:
            return middle
        elif (key > A[middle]):
            low = middle + 1
        else:
            high = middle - 1
    return None


# 보간 탐색(interpolation search)
def interpolation_search(A, key, low, high):
    while (low <= high):
        middle = int(low + (high - low) * (key - A[low]) / (A[high] - A[low]))
        if key == A[middle]:
            return middle
        elif (key > A[middle]):
            low = middle + 1
        else:
            high = middle - 1
    return None


if __name__ == "__main__":
    l = [1, 2, 3, 4, 5]  # 정렬되어 있어야 한다
    i1 = binary_search(l, 3, 0, 4)
    i2 = binary_search_iter(l, 3, 0, 4)
    i3 = interpolation_search(l, 3, 0, 4)
    print(i1)
    print(i2)
    print(i3)
