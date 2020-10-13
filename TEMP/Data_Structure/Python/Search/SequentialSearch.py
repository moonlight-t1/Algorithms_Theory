# 순차 탐색

def sequential_search(A, key, low, high):
    for i in range(low, high + 1):
        if A[i] == key:
            return i
    return None


if __name__ == "__main__":
    l = [9, 5, 8, 3, 7]
    i = sequential_search(l, 3, 0, 4)
    print(i)
