# 맵의 응용 : 단어장
# 리스트를 이용한 순차탐색 맵

class Entry:
    def __init__(self, key, value):
        self.key = key
        self.value = value

    def __str__(self):
        return str("%s : %s" % (self.key, self.value))
