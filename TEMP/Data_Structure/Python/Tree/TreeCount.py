class TNode:
    def __init__(self, data, left, right):
        self.data = data
        self.left = left
        self.right = right


# 노드 개수 구하기
def count_node(n):
    if n is None:
        return 0
    else:
        return 1 + count_node(n.left) + count_node(n.right)


# 단말 노드 개수 구하기
def count_leaf(n):
    if n is None:
        return 0
    elif n.left is None and n.right is None:
        return 1
    else:
        return count_leaf(n.left) + count_leaf(n.right)


# 트리의 높이 구하기
def calc_height(n):
    if n is None:
        return 0
    h_left = calc_height(n.left)
    h_right = calc_height(n.right)
    if (h_left > h_right):
        return h_left + 1
    else:
        return h_right + 1


if __name__ == "__main__":
    d = TNode('D', None, None)
    e = TNode('E', None, None)
    b = TNode('B', d, e)
    f = TNode('F', None, None)
    c = TNode('C', f, None)
    root = TNode('A', b, c)

    print("노드의 개수 = %d개" % count_node(root))
    print("단말의 개수 = %d개" % count_leaf(root))
    print("트리의 높이 = %d" % calc_height(root))
