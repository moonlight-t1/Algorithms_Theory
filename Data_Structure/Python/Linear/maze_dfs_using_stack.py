# 스택 응용 : 스택을 이용한 깊이우선탐색의 구현

from Stack import *

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


# 깊이 우선 탐색
def dfs():
    stack = Stack()
    stack.push((0, 1))  # 시작 위치
    print("DFS: ")

    while not stack.isEmpty():
        here = stack.pop()
        print(here, end=' => ')
        (x, y) = here  # 스택에 저장된 튜플

        if (map[y][x] == 'x'):  # 출구이면
            return True

        else:
            map[y][x] = '.'
            # 4 방향의 이웃 검사
            if is_valid_pos(x, y - 1):  # 상
                stack.push((x, y - 1))
            if is_valid_pos(x, y + 1):  # 하
                stack.push((x, y + 1))
            if is_valid_pos(x - 1, y):  # 좌
                stack.push((x - 1, y))
            if is_valid_pos(x + 1, y):  # 우
                stack.push((x + 1, y))
        # print("현재 스택: ", stack)
    return False  # 탐색 실패


if __name__ == "__main__":
    result = dfs()
    if result:
        print("=> 탐색 성공")
    else:
        print("=> 탐색 실패")
