# 링크드 리스트 Linked List

# 노드 클래스
class Node:
    def __init__(self, elem, link=None):
        self.data = elem
        self.link = link


class LinkedList:
    def __init__(self):
        self.head = None

    def isEmpty(self):
        return self.head == None

    def clear(self):
        self.head = None

    def size(self):
        n = self.head
        size = 0
        while not n == None:
            n = n.link
            size += 1
        return size

    def display(self, msg="Linked List: "):
        print(msg, end='')
        n = self.head
        while not n == None:
            print(n.data, end=' ')
            n = n.link
        print()

    # pos 번째 노드 반환
    def getNode(self, pos):
        if pos < 0:
            return None
        node = self.head
        while pos > 0 and node != None:
            node = node.link
            pos -= 1
        return node

    # 항목의 데이터만 반환
    def getEntry(self, pos):
        node = self.getNode(pos)
        if node == None:
            return None
        else:
            return node.data

    # 다른 데이터로 변경
    def replace(self, pos, elem):
        node = self.getNode(pos)
        if node != None:
            node.data = elem

    # 원하는 데이터를 가진 노드 찾기
    def find(self, data):
        node = self.head
        while node is not None:
            if node.data == data:
                return Node
            node = node.link
        return node

    # 삽입
    def insert(self, pos, elem):
        before = self.getNode(pos - 1)
        if before == None:  # 맨 앞에 삽입하는 경우
            self.head = Node(elem, self.head)
        else:  # 중간에 앞에 삽입하는 경우
            node = Node(elem, before.link)
            before.link = node

    # 삭제
    def delete(self, pos):
        before = self.getNode(pos - 1)  # before 노들르 찾음
        if before == None:  # 시작 노드를 삭제
            if self.head is not None:
                self.head = self.head.link
        elif before.link != None:  # 중간에 있는 노드를 삭제
            before.link = before.link.link


if __name__ == "__main__":
    s = LinkedList()
    s.display("삽입 전")
    s.insert(0, 10)
    s.insert(0, 20)
    s.insert(1, 30)
    s.insert(s.size(), 40)
    s.insert(2, 50)

    s.display("삽입 후")

    s.replace(2, 90)
    s.display("교체")

    s.delete(2)
    s.delete(s.size() - 1)
    s.delete(0)
    s.display("삭제")

    s.clear()
    s.display("초기화")
