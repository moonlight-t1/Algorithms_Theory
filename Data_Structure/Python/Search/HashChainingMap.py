# 맵의 응용 : 단어장
# 체이닝을 이용한 해시 맵

class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __str__(self):
        return str("%s : %s" % (self.key, self.value))


class Node:
    def __init__(self, elem, link=None):
        self.data = elem
        self.link = link


# 해시 체인 맵
class HashChainMap:
    def __init__(self, M):
        self.table = [None] * M
        self.M = M

    # 해시 함수
    def hashFn(self, key):
        sum = 0
        for c in key:
            sum = sum + ord(c)  # 아스키 코드 값을 모두 더한다
        return sum % self.M

    def insert(self, key, value):
        idx = self.hashFn(key)
        self.table[idx] = Node(Entry(key, value), self.table[idx])  # 전단 삽입

    def search(self, key):
        idx = self.hashFn(key)
        node = self.table[idx]
        while node is not None:
            if node.data.key == key:
                return node.data
            node = node.link
        return None

    def delete(self, key):
        idx = self.hashFn(key)
        node = self.table[idx]
        before = None
        while node is not None:
            if node.data.key == key:
                if before == None:  # 첫 번째 항목 삭제
                    self.table[idx] = node.link
                else:  # 두 번째 이후 항목 삭제
                    before.link = node.link
                return
            before = node
            node = node.link

    def display(self, msg):
        print(msg)
        for idx in range(len(self.table)):
            node = self.table[idx]
            if node is not None:
                print("[%d] -> " % idx, end='')
                while node is not None:
                    print(node.data, end=' -> ')
                    node = node.link
                print()


if __name__ == "__main__":
    map = HashChainMap(5)
    map.insert("Linked List", "링크드 리스트")
    map.insert("Stack", "스택")
    map.insert("Queue", "큐")
    map.insert("Tree", "트리")
    map.insert("Graph", "그래프")
    map.insert("Hash", "해쉬")

    map.display("자료구조 : ")

    print("탐색 : Stack => ", map.search("Stack"))

    map.delete("Stack")
    map.display("자료구조 : ")
