import collections

mygraph = {
    "A": {"B", "C"},
    "B": {"A", "D"},
    "C": {"A", "D", "E"},
    "D": {"B", "C", "F"},
    "E": {"C", "G", "H"},
    "F": {"D"},
    "G": {"E", "H"},
    "H": {"E", "G"}
}


# 깊이 우선 탐색
def dfs(graph, start, visited=set()):
    if start not in visited:  # start가 방문하지 않은 정점이라면
        visited.add(start)
        print(start, end=' ')
        nbr = graph[start] - visited  # 차집합 연산
        for v in nbr:
            dfs(graph, v, visited)


# 넓이 우선 탐색
def bfs(graph, start):
    visited = set([start])  # 맨 처음은 start만 방문한 정점
    queue = collections.deque([start])
    while queue:
        vertex = queue.popleft()
        print(vertex, end=' ')
        nbr = graph[vertex] - visited
        for v in nbr:
            visited.add(v)
            queue.append(v)


if __name__ == "__main__":
    print("DFS : ", end='')
    dfs(mygraph, "A")
    print()
    print("BFS : ", end='')
    bfs(mygraph, "A")
