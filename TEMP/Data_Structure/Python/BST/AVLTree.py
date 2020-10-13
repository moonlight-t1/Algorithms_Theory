# AVL Tree
from BSTMap import *
from CircularQueue import *
from TreeCount import *


# LL 회전
def rotateLL(A):
    B = A.left
    A.left = B.right
    B.right = A
    return B


# RR 회전
def rotateRR(A):
    B = A.right
    A.right = B.left
    B.left = A
    return B


# RL 회전
def rotateRL(A):
    B = A.right
    A.right = rotateLL(B)
    return rotateRR(A)


# LR 회전
def rotateLR(A):
    B = A.left
    A.left = rotateRR(B)
    return rotateLL(A)


# 트리의 높이차 구하기
def calc_height_diff(parent):
    return calc_height(parent.left) - calc_height(parent.right)


# 레벨 순회
def levelorder(root):
    queue = CircularQueue()
    queue.enqueue(root)  # 최초의 큐에는 루트 노드만 들어있다
    while not queue.isEmpty():
        n = queue.dequeue()
        if n is not None:
            print(n.key, end=' ')
            queue.enqueue(n.left)  # n의 왼쪽 자식 노드를 큐에 삽입
            queue.enqueue(n.right)  # n의 오른쪽 자식 노드를 큐에 삽입


# 재균형 함수
def rebalance(parent):
    h_diff = calc_height_diff(parent)

    if h_diff > 1:
        if calc_height_diff(parent.left) > 0:
            parent = rotateLL(parent)
        else:
            parent = rotateLR(parent)

    elif h_diff < -1:
        if calc_height_diff(parent.right) < 0:
            parent = rotateRR(parent)
        else:
            parent = rotateRL(parent)

    return parent


# 삽입함수
def insert_avl(parent, node):
    if node.key < parent.key:
        if parent.left != None:
            parent.left = insert_avl(parent.left, node)
        else:
            parent.left = node
        return rebalance(parent)

    elif node.key > parent.key:
        if parent.right != None:
            parent.right = insert_avl(parent.right, node)
        else:
            parent.right = node
        return rebalance(parent)
    else:
        print("중복된 키 에러")


class AVLMap(BSTMap):
    def __init__(self):
        super().__init__()  # 부모 클래스의 생성자 호출

    def insert(self, key, value=None):
        n = BSTNode(key, value)
        if self.is_empty():
            self.root = n
        else:
            self.root = insert_avl(self.root, n)

    def display(self, msg="AVLMap : "):
        print(msg, end='')
        levelorder(self.root)
        print()


if __name__ == "__main__":
    node = [7, 8, 9, 2, 1, 5, 3, 6, 4]
    map = AVLMap()

    for i in node:
        map.insert(i)
        map.display("AVL(%d): " % i)

    print("노드의 개수 = %d" % count_node(map.root))
    print("단말의 개수 = %d" % count_leaf(map.root))
    print("트리의 높이 = %d" % calc_height(map.root))
