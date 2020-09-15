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

    # 정렬된 상태를 유지하면서 elem을 삽입
    def insert(self, elem):
        if elem in self.items:
            return
        for idx in range(len(self.items)):
            if elem < self.items[idx]:
                self.items.insert(idx, elem)
                return
        self.items.append(elem)

    # 삭제
    def delete(self, elem):
        if elem in self.items:
            self.items.remove(elem)

    # 원소를 크기 순으로 합집합
    def union(self, setB):
        newSet = Set()
        a = 0
        b = 0
        while a < len(self.items) and b < len(setB.items):
            valueA = self.items[a]
            valueB = self.items[b]
            if valueA < valueB:
                newSet.items.append(valueA)
                a += 1
            elif valueA > valueB:
                newSet.items.append(valueB)
                b += 1
            else:
                newSet.items.append(valueA)
                a += 1
                b += 1
        while a < len(self.items):
            newSet.items.append(self.items[a])
            a += 1
        while b < len(setB.items):
            newSet.items.append(setB.items[b])
            b += 1
        return newSet

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

    # 비교 연산
    def __eq__(self, setB):
        if self.size() != setB.size():  # 원소의 개수가 같아야 한다
            return False
        for idx in range(len(self.items)):
            if self.items[idx] != setB.items[idx]:
                return False
        return True


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
