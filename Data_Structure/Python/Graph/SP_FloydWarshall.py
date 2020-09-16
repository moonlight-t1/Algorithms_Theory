# Floyd Algorithm

INF = 9999


def printA(A):
    v_size = len(A)
    print("=" * 35)
    for i in range(v_size):
        for j in range(v_size):
            if (A[i][j] == INF):
                print(" INF ", end='')
            else:
                print("%4d " % A[i][j], end='')
        print("")


def shortest_path_floyd(vertex, adj):
    v_size = len(vertex)  # 정점의 개수
    A = list(adj)
    for i in range(v_size):
        A[i] = list(adj[i])

    for k in range(v_size):  # 정점 k를 추가할 때
        for i in range(v_size):
            for j in range(v_size):  # 모든 A[i][j]를 갱신
                if (A[i][k] + A[k][j] < A[i][j]):
                    A[i][j] = A[i][k] + A[k][j]
        printA(A)


if __name__ == "__main__":
    vertex = ['A', 'B', 'C', 'D', 'E', 'F', 'G']
    weight = [
        [0, 7, INF, INF, 3, 10, INF],
        [7, 0, 4, 10, 2, 6, INF],
        [INF, 4, 0, 2, INF, INF, INF],
        [INF, 10, 2, 0, 11, 9, 4],
        [3, 2, INF, 11, 0, 13, 5],
        [10, 6, INF, 9, 13, 0, INF],
        [INF, INF, INF, 4, 5, INF, 0]
    ]

    print("Shortest Path By Floyd Algorithm")
    shortest_path_floyd(vertex, weight)
