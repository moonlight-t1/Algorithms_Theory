def binary_search(A, key, low, high):
    if (low <= high):  # 항목들이 남아 있으면 (종료 조건)
        middle = (low + high) // 2
        if key == A[middle].key:  # 탐색 성공
            return middle
        elif (key < A[middle].key):  # 왼쪽 부분 리스트 탐색
            return binary_search(A, key, low, middle - 1)
        else:  # 오른쪽 부분 리스트 탐색
            return binary_search(A, key, middle + 1, high)
    return None  # 탐색 실패
