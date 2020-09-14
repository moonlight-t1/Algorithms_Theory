def insert(self, elem):
    if elem in self.items:  # 이미 원소 존재하는 경우
        return
    for idx in range(len(self.items)):
        if elem < self.items[idx]:  # 삽입할 위치의 인덱스 찾음
            self.items.insert(idx, elem)
            return
    self.items.append(elem)  # 맨 뒤에 삽입
