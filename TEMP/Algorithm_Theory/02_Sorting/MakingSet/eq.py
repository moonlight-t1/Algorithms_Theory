def __eq__(self, setB):  # 두 집합 self, setB가 같은 집합인가?
    if self.size() != setB.size():  # 원소의 개수가 같아야 한다
        return False
    for idx in range(len(self.items)):
        if self.items[idx] != setB.items[idx]:  # 원소별로 같은지 검사
            return False
    return True
