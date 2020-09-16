# 맵의 응용 : 단어장
# 리스트를 이용한 순차탐색 맵

class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __str__(self):
        return str("%s : %s" % (self.key, self.value))


# 순차 탐색 맵
class SequentialMap:
    def __init__(self):
        self.table = []

    def size(self):
        return len(self.table)

    def display(self, msg):
        print(msg)
        for entry in self.table:
            print(" ", entry)

    def insert(self, key, value):
        self.table.append(Entry(key, value))

    # 순차 탐색
    def sequential_search(self, key):
        for i in range(self.size()):
            if self.table[i].key == key:
                return i
        return None

    def search(self, key):
        pos = SequentialMap.sequential_search(self, key)
        if pos is not None:
            return self.table[pos]
        else:
            return None

    def delete(self, key):
        for i in range(self.size()):
            if self.table[i].key == key:
                self.table.pop(i)
                return


if __name__ == "__main__":
    map = SequentialMap()
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
