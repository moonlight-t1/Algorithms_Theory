# Dijkstra의 최단 경로 알고리즘


INF = 999


# 최소 dist 정점을 찾는 함수
def choose_vertex(dist, found):
    min = INF
    min_pos = -1
    for i in range(len(dist)):  # 모든 접점 중애서 방문하지 않은 최소 dist 정점
        if dist[i] < min and found[i] == False:
            min = dist[i]
            min_pos = i
    return min_pos  # 최소 dist 정점의 인덱스 반환


# Dijkstra
def shortest_path_dijkstra(vtx, adj, start):
    v_size = len(vtx)  # 정점 수
    dist = list(adj[start])  # dist 배열 생성 및 초기화
    path = [start] * v_size  # path 배열 생성 및 초기화
    found = [False] * v_size  # found 배열 생성 및 초기화
    found[start] = True  # 시작 정점 : 이미 찾아짐
    dist[start] = 0  # 시작 정점의 거리 0

    for i in range(v_size):
        print("Step %2d: " % (i + 1), dist)  # 단계별 dist 출력
        u = choose_vertex(dist, found)  # 최소 dist 정점 u 탐색
        found[u] = True  # u는 이제 찾아짐

        for w in range(v_size):  # 모든 정점에 대해
            if not found[w]:
                if dist[u] + adj[u][w] < dist[w]:
                    dist[w] = dist[u] + adj[u][w]
                    path[w] = u
    return path


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

    print("Shortest Path By Dikstra Algorithm")
    start = 0
    path = shortest_path_dijkstra(vertex, weight, start)

    for end in range(len(vertex)):
        if end != start:
            print("[최단경로: %s->%s] %s" %
                  (vertex[start], vertex[end], vertex[end]), end='')
            while (path[end] != start):
                print(" <- %s " % vertex[path[end]], end='')
                end = path[end]
            print(" <- %s" % vertex[path[end]])
