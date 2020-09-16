import sys  # maxsize

INF = sys.maxsize


# 현재 트리에 인접한 정점들 중에서 가장 가까운 정점을 찾는 함수
def get_min_vertex(dist, selected):
    min_v = 0
    min_dist = INF
    for v in range(len(dist)):  # 모든 정점들에 대해
        if not selected[v] and dist[v] < min_dist:  # 선택이 안되었고
            min_dist = dist[v]  # 가중치가 작으면
            min_v = v  # min_v 갱신
    return min_v


# Prim의 최소 비용 신장 트리 프로그램
def MSTPrim(vertex, adj):
    v_size = len(vertex)
    dist = [INF] * v_size
    selected = [False] * v_size
    dist[0] = 0

    for _ in range(v_size):
        u = get_min_vertex(dist, selected)
        selected[u] = True
        print(vertex[u], end=' ')
        for v in range(v_size):
            if (adj[u][v] != None):
                if selected[v] == False and adj[u][v] < dist[v]:
                    dist[v] = adj[u][v]


if __name__ == "__main__":
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
    print("MST By Prim's Algorithm")
    MSTPrim(vertex, weight)
