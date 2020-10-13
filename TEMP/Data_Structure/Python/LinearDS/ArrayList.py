# 배열로 구현한 리스트

class ArrayList:
    def __init__(self):
        self.items = []

    # 삽입
    def insert(self, pos, elem):
        self.items.insert(pos, elem)

    # 삭제
    def delete(self, pos):
        return self.items.pop(pos)

    # 공백 상태 검사
    def isEmpty(self):
        return self.size() == 0

    # 항목 꺼내지 않고 반환
    def getEntry(self, pos):
        return self.items[pos]

    # 전체 항목의 개수
    def size(self):
        return len(self.items)

    # 리스트 초기화
    def clear(self):
        self.items = []

    # 탐색
    def find(self, item):
        return self.items.index(item)

    # 대체
    def replace(self, pos, elem):
        self.items[pos] = elem

    # 정렬
    def sort(self):
        self.items.sort()

    # 병합
    def merge(self, lst):
        self.items.extend(lst)

    # 출력
    def display(self, msg="ArrayList: "):
        print(msg, self.size(), self.items)

    # 추가
    def append(self):
        pass


if __name__ == "__main__":
    s = ArrayList()
    s.display()
    s.insert(0, 10)
    s.insert(0, 20)
    s.insert(1, 30)
    s.insert(s.size(), 40)

    s.display()
    s.sort()
    s.display()
    s.replace(2, 90)
    s.delete(2)
    lst = [1, 2, 3]
    s.merge(lst)
    s.display()
    s.clear()
    s.display()
