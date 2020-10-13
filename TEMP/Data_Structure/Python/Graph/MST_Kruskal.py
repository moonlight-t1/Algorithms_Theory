# Kruskal 알고리즘

from UnionFind import *


def MSTKruskal(vertex, adj):
    v_size = len(vertex)  # 정잠의 개수
    init_set(v_size)  # 정점 집합 초기화
    e_list = []  # 간선 리스트

    for i in range(v_size - 1):
        for j in range(i + 1, v_size):
            if adj[i][j] != None:
                e_list.append((i, j, adj[i][j]))  # 튜플로 저장

    # 간선 리스트를 가중치의 내림차순으로 정렬
    e_list.sort(key=lambda e: e[2], reverse=True)

    edge_accepted = 0
    while (edge_accepted < v_size - 1):
        e = e_list.pop(-1)  # 가장 작은 가중치를 가진 간선
        u_set = find(e[0])  # 두 정점이 속한 집합 번호
        v_set = find(e[1])

        if u_set != v_set:  # 두 정점이 다른 집합의 원소라면
            print("간선 추가 : (%s, %s, %d)" % (vertex[e[0]], vertex[e[1]], e[2]))
            union(u_set, v_set)  # 두 집합을 합한다
            edge_accepted += 1  # 간선 하나 추가


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
    print("MST By Kruskal's Algorithm")
    MSTKruskal(vertex, weight)
