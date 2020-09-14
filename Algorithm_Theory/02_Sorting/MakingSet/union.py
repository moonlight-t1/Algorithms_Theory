def union(self, setB):  # 집합 self와 집합 setB의 합집합
    newSet = Set()  # 반환할 합집합
    a = 0  # 집합 self의 원소에 대한 인덱스
    b = 0  # 집합 setB의 원소에 대한 인덱스
    while a < len(self.items) and b < len(setB.items):
        valueA = self.items[a]  # 집합 self의 현재 원소
        valueB = setB.items[b]  # 집합 setB의 현재 원소
        if valueA < valueB:  # self의 원소가 더 작으면
            newSet.items.append(valueA)
            a += 1
        elif valueA > valueB:  # setB의 원소가 더 작으면
            newSet.items.append(valueB)
            b += 1
        else:  # 중복되는 원소
            newSet.items.append(valueA)
            a += 1
            b += 1
    while a < len(self.items):  # self에 남은 원소를 모두 추가
        newSet.items.append(self.items[a])
        a += 1
    while b < len(setB.items):  # setB에 남은 원소를 모두 추가
        newSet.items.append(setB.items[b])
        b += 1
    return newSet  # 합집합 반환
