# 이진 탐색 트리
class BSTNode:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None


# 이진탐색 트리의 탐색 연산(순환 함수)
def search_bst(n, key):
    if n == None:
        return None
    elif key == n.key:
        return n
    elif key < n.key:
        return search_bst(n.left, key)
    else:
        return search_bst(n.right, key)


# 이진 탐색트리의 탐색 연산(반복 함수)
def search_bst_iter(n, key):
    while n != None:
        if key == n.key:
            return n
        elif key < n.key:
            n = n.left
        else:
            n = n.right
    return None


# 이진 탐색트리의 탐색연산(preorder) : 값을 이용한 탐색
def search_value_bst(n, value):
    if n == None:
        return None
    elif value == n.value:
        return n
    res = search_value_bst(n.left, value)
    if res is None:
        return res
    else:
        return search_value_bst(n.right, value)


# 최대 값의 노드 탐색
def search_max_bst(n):
    while n != None and n.right != None:
        n = n.right
    return n


# 최소 값의 노드 탐색
def search_min_bst(n):
    while n != None and n.left != None:
        n = n.left
    return n


# 이진탐색트리 삽입연산 (노드를 삽입함): 순환구조 이용
def insert_bst(r, n):
    if n.key < r.key:  # 삽입할 노드의 키가 루트보다 작으면
        if r.left is None:  # 루트의 왼쪽 자식이 없으면
            r.left = n
            return True
        else:  # 루트의 왼쪽 자식이 있으면
            return insert_bst(r.left, n)
    elif n.key > r.key:  # 삽입할 노드의 키가 루트보다 크면
        if r.right is None:  # 루트의 오르쪽 자식이없으면
            r.right = n
            return True
        else:  # 루트의 오른쪽 자식이 있으면
            return insert_bst(r.right, n)
    else:  # 키가 중복되면 삽입하지 않는다
        return False


# 삭제 연산 1: 단말 노드의 삭제
def delete_bst_case1(parent, node, root):
    if parent is None:
        root = None
    else:
        if parent.left == node:
            parent.left = None
        else:
            parent.right = None
    return root


# 삭제 연산 2: 자식이 하나인 노드의 삭제
def delete_bst_case2(parent, node, root):
    if node.left is not None:
        child = node.left
    else:
        child = node.right

    if node == root:
        root = child
    else:
        if node is parent.left:
            parent.left = child
        else:
            parent.right - child
    return root


# 삭제 연산 3: 두 개의 자식을 모두 갖는 노드의 삭제
def delete_bst_case3(parent, node, root):
    succp = node  # 후계자의 부모 노드
    succ = node.right  # 후계자 노드
    while (succ.left != None):  # 후계자와 부모노드 탐색
        succp = succ
        succ = succ.left

    if (succp.left == succ):
        succp.left = succ.right
    else:
        succp.right = succ.right
    node.key = succ.key
    node.value = succ.value
    node = succ

    return root


# 모든 경우에 대한 삭제 연산
def delete_bst(root, key):
    if root == None:  # 공백 트리
        return None

    parent = None
    node = root
    while node != None and node.key != key:
        parent = node
        if key < node.key:
            node = node.left
        else:
            node = node.right

    if node == None:
        return None
    if node.left == None and node.right == None:  # 1 단말 노드
        root = delete_bst_case1(parent, node, root)
    elif node.left == None or node.right == None:
        root = delete_bst_case2(parent, node, root)
    else:
        root = delete_bst_case2(parent, node, root)
    return root
