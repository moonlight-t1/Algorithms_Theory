# 앤트리 클래스
class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __str__(self):
        return str("%s: %s" % (self.key, self.value))


# 순차 탐색 맵
class SequentialMap:
    def __init__(self):
        self.table = []  # 맵의 레코드 테이블

    # 레코드 개수
    def size(self):
        return len(self.table)

    # 보기 좋게 출력
    def display(self, msg):
        print(msg)
        for entry in self.table:
            print(" ", entry)

    # 삽입 연산
    def insert(self, key, value):
        self.table.append(Entry(key, value))  # 리스트의 맨 뒤에 Entry object 추가

    # 순차 탐색
    def sequential_search(self, key):
        for i in range(self.size()):
            if self.table[i].key == key:
                return i
        return None

    # 순차 탐색 연산
    def search(self, key):
        pos = SequentialMap.sequential_search(self, key)
        if pos is not None:
            return self.table[pos]
        else:
            return None

    # 삭제 연산
    def delete(self, key):
        for i in range(self.size()):
            if self.table[i].key == key:
                self.table.pop(i)
                return


map = SequentialMap()
map.insert('data', '자료')
map.insert('structure', '구조')
map.insert('sequential search', '선형 탐색')
map.insert('binary search', '이진 탐색')

# map.delete('data')
print(map.search('data'))
map.display("단어장")
