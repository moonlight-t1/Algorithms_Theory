def binary_search(A, key, low, high):
    while(low <= high):  # 항목들이 남아 있으면 (종료 조건)
        middle = (low + high) // 2
        if key == A[middle].key:  # 탐색 성공
            return middle
        elif (key > A[middle].key):  # key가 middle의 값보다 크면
            low = middle + 1
        else:  # key가 middle의 값보다 작으면
            high = middle - 1
    return None  # 탐색 실패
