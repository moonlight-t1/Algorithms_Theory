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


def bfsST(graph, start):
    visited = set([start])
    queue = collections.deque([start])
    while queue:
        v = queue.popleft()
        nbr = graph[v] - visited
        for u in nbr:
            print("(", v, ",", u, ") ", end="")
            visited.add(u)
            queue.append(u)


if __name__ == "__main__":
    bfsST(mygraph, "A")
