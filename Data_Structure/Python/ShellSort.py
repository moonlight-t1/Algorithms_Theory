# gap 만큼 떨어진 요소들을 삽입 정렬
def sort_get_insertion(A, first, last, gap):
    for i in range(first, last + 1, gap):
        key = A[i]
        j = i - gap
        while j >= first and key < A[j]:  # 삽입 위치를 찾는다
            A[j + gap] = A[j]  # 항목 이동
            j = j - gap
        A[j + gap] = key  # 최종 위치에 삽입


# 셸 정렬 알고리즘
def shell_sort(A):
    n = len(A)
    gap = n//2  # 최초의 gap : 리스트 크기의 절반
    while gap > 0:
        if (gap % 2) == 0:
            gap += 1  # gap 이 짞수이면 1을 더한다
        for i in range(gap):
            sort_get_insertion(A, i, n-1, gap)
        print(' Gap = ', gap, A)
        gap = gap // 2


if __name__ == "__main__":
    l = [5, 3, 8, 4, 9, 1, 6, 2, 7]
    print("Original : ", l)
    shell_sort(l)
