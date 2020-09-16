class Set:
    def __init__(self):
        self.items = []

    def size(self):
        return len(self.items)

    def display(self, msg):
        print(msg, self.items)

    # item이 있는지 조사
    def contains(self, item):
        return item in self.items

    # 삽입
    def insert(self, elem):
        if elem not in self.items:  # 중복 검사
            self.items.append(elem)

    # 삭제
    def delete(self, elem):
        if elem in self.items:
            self.items.remove(elem)

    # 합집합
    def union(self, setB):
        setC = Set()
        setC.items = list(self.items)  # self의 리스트를 setC에 복사
        # setB에 대해 self에 없으면 중복이 아니므로 setC에 추가
        for elem in setB.items:
            if elem not in self.items:
                setC.items.append(elem)
        return setC

    # 교집합
    def intersect(self, setB):
        setC = Set()
        # set와 setB 양쪽 모두에 있으면 setC에 추가
        for elem in setB.items:
            if elem in self.items:
                setC.items.append(elem)
        return setC

    # 차집합
    def difference(self, setB):
        setC = Set()
        # self에 있고 setB에 없으면 setC에 추가
        for elem in self.items:
            if elem not in setB.items:
                setC.items.append(elem)
        return setC


if __name__ == "__main__":
    setA = Set()
    setA.insert("C")
    setA.insert("Programming")
    setA.insert("Dennis Ritchie")
    setA.display("Set A: ")

    setB = Set()
    setB.insert("Python")
    setB.insert("Programming")
    setB.insert("Guido van Rossum")
    setB.display("Set B: ")

    setA.union(setB).display('A U B:')
    setA.intersect(setB).display('A ^ B: ')
    setA.difference(setB).display('A - B: ')
