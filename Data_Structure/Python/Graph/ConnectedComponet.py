mygraph = {
    "A": set(["B", "C"]),
    "B": set(["A"]),
    "C": set(["A"]),
    "D": set(["E"]),
    "E": set(["D"])
}


def find_connected_component(graph):
    visited = set()
    color_list = []

    for vtx in graph:
        if vtx not in visited:  # 방문하지 않은 정점이 있으면 새로운 컬러 리스트 추가
            color = dfs_cc(graph, [], vtx, visited)
            color_list.append(color)
    print("그래프 연결성분 개수 = %d " % len(color_list))
    print(color_list)


def dfs_cc(graph, color, vertex, visited):
    if vertex not in visited:
        visited.add(vertex)
        color.append(vertex)  # 같은 색의 정점 리스트에 추가
        nbr = graph[vertex] - visited  # nbr 차집합 연산
        for v in nbr:
            dfs_cc(graph, color, v, visited)
        return color


if __name__ == "__main__":
    print('find_connected_component: ')
    find_connected_component(mygraph)
