# 우선순위 큐의 응용: 전략적인 미로 탐색

from PriortyQueue import *
import math

map = [
    ['1', '1', '1', '1', '1', '1'],
    ['e', '0', '0', '0', '0', '1'],
    ['1', '0', '1', '0', '1', '1'],
    ['1', '1', '1', '0', '0', 'x'],
    ['1', '1', '1', '0', '1', '1'],
    ['1', '1', '1', '1', '1', '1']
]
MAZE_SIZE = 6


# (x, y)가 갈 수 있는 방인지 검사하는 함수
def is_valid_pos(x, y):
    if x < 0 or y < 0 or x >= MAZE_SIZE or y >= MAZE_SIZE:
        return False
    else:  # 갈 수 있는 방향이나 출구
        return map[y][x] == '0' or map[y][x] == 'x'


(ox, oy) = (5, 4)  # 출구의 위치


# 출구로부터의 거리 계산 함수
def dist(x, y):
    (dx, dy) = (ox - x, oy - y)
    return math.sqrt(dx * dx + dy * dy)


class PriorityQueueMaze(PriorityQueue):
    def findMaxIndex(self):
        if self.isEmpty():
            return None
        else:
            highest = 0  # 0번을 최대라 하고
            for i in range(1, self.size()):
                if self.items[i][2] > self.items[highest][2]:
                    highest = i  # 최고 우선순위 인덱스 갱신
            return highest


def my_smart_search():
    q = PriorityQueueMaze()
    q.enqueue((0, 1, -dist(0, 1)))
    print("PQueue: ")

    while not q.isEmpty():
        here = q.dequeue()
        print(here[0:2], end=' => ')  # 현재 위치 출력
        x, y, _ = here
        if (map[y][x] == 'x'):
            return True
        else:
            map[y][x] = '.'
            if is_valid_pos(x, y - 1):
                q.enqueue((x, y - 1, -dist(x, y - 1)))
            if is_valid_pos(x, y + 1):
                q.enqueue((x, y + 1, -dist(x, y + 1)))
            if is_valid_pos(x - 1, y):
                q.enqueue((x - 1, y, -dist(x - 1, y)))
            if is_valid_pos(x + 1, y):
                q.enqueue((x + 1, y, -dist(x + 1, y)))
        # print("우선순위큐: ", q.items)
    return False


if __name__ == "__main__":
    result = my_smart_search()
    if result:
        print("=> 탐색 성공")
    else:
        print("=> 탐색 실패")
