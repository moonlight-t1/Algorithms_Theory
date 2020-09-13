from CircularQueue import CircularQueue


# 이진트리 노드 클래스
class TNode:
    def __init__(self, data, left, right):
        self.data = data
        self.left = left
        self.right = right

    # 전위 순회
    def preorder(self, n):
        if n is not None:
            print(n.data, end=' ')
            TNode.preorder(self, n.left)
            TNode.preorder(self, n.right)

    # 중위 순회
    def inorder(self, n):
        if n is not None:
            TNode.inorder(self, n.left)
            print(n.data, end=' ')
            TNode.inorder(self, n.right)

    # 후위 순회
    def postorder(self, n):
        if n is not None:
            TNode.postorder(self, n.left)
            TNode.postorder(self, n.right)
            print(n.data, end=' ')

    # 레벨 순회
    def levelorder(self, root):
        queue = CircularQueue()
        queue.enqueue(root)  # 최초의 큐에는 루트 노드만 들어있다
        while not queue.isEmpty():
            n = queue.dequeue()
            if n is not None:
                print(n.data, end=' ')
                queue.enqueue(n.left)  # n의 왼쪽 자식 노드를 큐에 삽입
                queue.enqueue(n.right)  # n의 오른쪽 자식 노드를 큐에 삽입


d = TNode('D', None, None)
e = TNode('E', None, None)
b = TNode('B', d, e)
f = TNode('F', None, None)
c = TNode('C', f, None)
root = TNode('A', b, c)

print('In-Order: ', end='')
root.inorder(root)
print('\nPre-Order: ', end='')
root.preorder(root)
print('\nPost-Order: ', end='')
root.postorder(root)
print('\nLevel-Order: ', end='')
root.levelorder(root)
print()
