# 큐의 응용 : 큐를 이용한 너비우선탐색

from CircularQueue import *

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


def bfs():
    que = CircularQueue()
    que.enqueue((0, 1))
    print("BFS: ")

    while not que.isEmpty():
        here = que.dequeue()
        print(here, end=" => ")
        x, y = here
        if (map[y][x] == 'x'):
            return True
        else:
            map[y][x] = '.'
            if is_valid_pos(x, y - 1):
                que.enqueue((x, y - 1))
            if is_valid_pos(x, y + 1):
                que.enqueue((x, y + 1))
            if is_valid_pos(x - 1, y):
                que.enqueue((x - 1, y))
            if is_valid_pos(x + 1, y):
                que.enqueue((x + 1, y))
    return False


if __name__ == "__main__":
    result = bfs()
    if result:
        print("=> 탐색 성공")
    else:
        print("=> 탐색 실패")
