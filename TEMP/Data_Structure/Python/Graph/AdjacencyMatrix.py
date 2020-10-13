vertex = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
weight = [
    [None, 29, None, None, None, 10, None],
    [29, None, 16, None, None, None, 15],
    [None, 16, None, 12, None, None, None],
    [None, None, 12, None, 22, None, 18],
    [None, None, None, 22, None, 27, 25],
    [10, None, None, None, 27, None, None],
    [None, 15, None, 18, 25, None, None],
]

graph = (vertex, weight)


# 인접 행렬에서의 가중치 합 계산
def weight_sum(vlist, W):
    sum = 0  # 가중의 합
    for i in range(len(vlist)):
        for j in range(i + 1, len(vlist)):
            if W[i][j] != None:  # 간선이 있으면 sum에 합
                sum += W[i][j]
    return sum


# 인접 행렬에서의 모든 간선 출력
def print_all_edges(vlist, W):
    for i in range(len(vlist)):
        for j in range(i + 1, len(W[i])):
            if W[i][j] != None and W[i][j] != 0:
                print("(%s, %s, %s)" % (vlist[i], vlist[j], W[i][j]), end=' ')
    print()


if __name__ == "__main__":
    print("AM : weight sum = ", weight_sum(vertex, weight))
    print_all_edges(vertex, weight)
