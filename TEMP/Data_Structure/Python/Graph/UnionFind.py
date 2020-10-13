parent = []  # 각 노드의 부모노드 인덱스
set_size = 0  # 전체 집합의 개수


# 집합의 초기화 함수
def init_set(n_sets):
    global set_size, parent
    set_size = n_sets
    for _ in range(n_sets):
        parent.append(-1)


# 정점 id가 속한 집합을 찾는 함수
def find(id):
    while (parent[id] >= 0):
        id = parent[id]
    return id


# 합집합 연산
def union(s1, s2):
    global set_size
    parent[s1] = s2  # s1을 s2에 병합
    set_size = set_size - 1  # 집합의 개수가 줄어든다
