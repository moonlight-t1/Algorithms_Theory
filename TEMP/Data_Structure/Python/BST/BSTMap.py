# 이진탐색트리를 이용한 맵

from BinarySearchTree import *


class BSTMap():
    def __init__(self):
        self.root = None

    def is_empty(self): return self.root == None
    def clear(self): self.root = None

    def size(self):
        return count_node(self.root)

    def search(self, key):
        return search_bst(self.root, key)

    def search_value(self, key):
        return search_value_bst(self.root, key)

    def find_max(self):
        return search_max_bst(self.root)

    def find_min(self):
        return search_min_bst(self.root)

    def insert(self, key, value=None):
        n = BSTNode(key, value)
        if self.is_empty():
            self.root = n
        else:
            insert_bst(self.root, n)

    def delete(self, key):
        self.root = delete_bst(self.root, key)

    def inorder(self, n):
        if n is not None:
            BSTMap.inorder(self, n.left)
            print(n.key, end=' ')
            BSTMap.inorder(self, n.right)

    def display(self, msg="BSTMap : "):
        print(msg, end='')
        BSTMap.inorder(self, self.root)
        print()


if __name__ == "__main__":
    map = BSTMap()
    data = [35, 18, 7, 26, 12, 3, 68, 22, 30, 99]

    print("[삽입 연산] : ", data)
    for key in data:
        map.insert(key)
    map.display("[중위 순회] : ")

    if map.search(26) != None:
        print("[탐색 26 ] : 성공")
    else:
        print("[탐색 26 ] : 실패")
    if map.search(25) != None:
        print("[탐색 25 ] : 성공")
    else:
        print("[탐색 25 ] : 실패")

    map.delete(3)
    map.display("[ 3 삭제]: ")
