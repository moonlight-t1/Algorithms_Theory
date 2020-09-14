# 앤트리 클래스
class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __str__(self):
        return str("%s: %s" % (self.key, self.value))


class Node:
    def __init__(self, elem, link=None):
        self.data = elem
        self.link = link


class HashChainMap:  # 해시 체인 맵
    def __init__(self, M):
        self.table = [None] * M  # 크기 M인 테이블을 먼저 만듦
        self.M = M

    # 해시 함수
    def hashFn(self, key):
        sum = 0
        for c in key:  # 문자열의 모든 문자에 대해 아스키 코드값을 모두 더한다
            sum = sum + ord(c)
        return sum % self.M  # 더한 값을 테이블 크기로 나머지 처리

    # 삽입 연산
    def insert(self, key, value):
        idx = self.hashFn(key)  # 해시 주소 계산
        self.table[idx] = Node(Entry(key, value), self.table[idx])  # 전단 삽입
        # entry = Entry(key, value)  # (1) 엔트리를 생성
        # node = Node(entry)  # (2) 엔트리로 노드를 생성
        # node.link = self.table[idx]  # (3) 노드의 링크필드 처리
        # self.table[idx] = node  # (4) 테이블의 idx 항목: node로 시작

    # 탐색 연산
    def search(self, key):
        idx = self.hashFn(key)
        node = self.table[idx]
        while node is not None:
            if node.data.key == key:
                return node.data
            node = node.link
        return None

    # 삭제 연산
    def delete(self, key):
        idx = self.hashFn(key)
        node = self.table[idx]
        before = None  # 삭제할 노드의 선행 노드
        while node is not None:
            if node.data.key == key:
                if before == None:  # 첫번째 항목 삭제
                    self.table[idx] = node.link
                else:  # 두 번째 이후 항목 삭제
                    before.link = node.link
                return
            before = node
            node = node.link

    # 맵 출력
    def display(self, msg):
        print(msg)
        for idx in range(len(self.table)):
            node = self.table[idx]
            if node is not None:
                print("[%2d] -> " % idx, end='')
                while node is not None:
                    print(node.data, end=' -> ')
                    node = node.link
                print()


map = HashChainMap(5)
map.insert('data', '자료')
map.insert('structure', '구조')
map.insert('sequential search', '선형 탐색')
map.insert('binary search', '이진 탐색')

# map.delete('data')
print(map.search('data'))
map.display("단어장")
