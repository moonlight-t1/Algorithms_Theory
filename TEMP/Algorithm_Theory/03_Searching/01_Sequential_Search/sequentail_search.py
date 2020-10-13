def sequential_search(A, key, low, high):  # 순차 탐색
    for i in range(low, high + 1):
        if A[i].key == key:  # 탐색에 성공하면 인덱스 반환
            return i
    return None  # 탐색에 실패하면 None 반환
