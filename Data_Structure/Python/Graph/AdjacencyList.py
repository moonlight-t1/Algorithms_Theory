graph = {
    'A': {('B', 29), ('F', 10)},
    'B': {('A', 29), ('C', 16), ('G', 15)},
    'C': {('B', 16), ('D', 12)},
    'D': {('C', 12), ('E', 22), ('G', 18)},
    'E': {('D', 22), ('F', 27), ('G', 25)},
    'F': {('A', 10), ('E', 27)},
    'G': {('B', 15), ('D', 18), ('E', 25)},
}


# 인접 리스트에서의 가중치 합 계산
def weight_sum(graph):
    sum = 0
    for v in graph:
        for e in graph[v]:
            sum += e[1]
    return sum / 2


# 인접 리스트에서의 간선 출력
def print_all_edges(graph):
    for v in graph:
        for e in graph[v]:
            print("(%s, %s, %d)" % (v, e[0], e[1]), end=' ')


if __name__ == "__main__":
    print("AL : weight sum = ", weight_sum(graph))
    print_all_edges(graph)
