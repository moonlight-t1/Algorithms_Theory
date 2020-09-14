def binary_search(A, key, low, high):
    while(low <= high):  # 항목들이 남아 있으면 (종료 조건)
        # 탐색 값과 위치는 비례한다는 가정에서 탐색 위치 결정 -> 보간 탐색
        middle = int(low + (high - low) *
                     (key-A[low].key) / (A[high].key - A[low].key))
        if key == A[middle].key:  # 탐색 성공
            return middle
        elif (key > A[middle].key):  # key가 middle의 값보다 크면
            low = middle + 1
        else:  # key가 middle의 값보다 작으면
            high = middle - 1
    return None  # 탐색 실패
