vertex = ['A', 'B', 'C', 'D', 'E', 'F']
graphAM = [
    [0, 0, 1, 1, 0, 0],
    [0, 0, 0, 1, 1, 0],
    [0, 0, 0, 1, 0, 1],
    [0, 0, 0, 0, 0, 1],
    [0, 0, 0, 0, 0, 1],
    [0, 0, 0, 0, 0, 0],
]


def topological_sort_AM(vertex, graph):
    n = len(vertex)
    in_deg = [0] * n  # 정점의 진입차수

    for i in range(n):
        for j in range(n):
            if graph[i][j] > 0:
                in_deg[j] += 1  # 정점의 진입차수를 1 증가시킨다

    vlist = []
    for i in range(n):
        if in_deg[i] == 0:
            vlist.append(i)

    while len(vlist) > 0:  # 리스트가 공백이 아닐 때까지
        v = vlist.pop()  # 진입 차수가 0인 정점을 하나 꺼낸다
        print(vertex[v], end=' ')

        for u in range(n):
            if v != u and graph[v][u] > 0:
                in_deg[u] -= 1  # 연결된 정점의 진입 차수 감소
                if in_deg[u] == 0:  # 진입 차수가 0이면 vlist에 추가
                    vlist.append(u)


if __name__ == "__main__":
    print("Topologial Sort : ")
    topological_sort_AM(vertex, graphAM)
    print()
