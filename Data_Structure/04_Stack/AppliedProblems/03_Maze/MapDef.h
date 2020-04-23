#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8

#define NUM_DIRECTIONS 4

// offset: x, y
static int DIRECTION_OFFSET[NUM_DIRECTIONS][2] = {
    {0, -1}, // 위쪽으로 이동
    {1, 0},  // 오른쪽으로 이동
    {0, 1},  // 아래쪽으로 이동
    {-1, 0}  // 왼쪽으로 이동
};

// 미방문, 벽, 방문
enum PosStatus
{
    NOT_VISIT = 0,
    WALL = 1,
    VISIT = 2
};

typedef struct MapPositionType
{
    int x;         // 현재 위치 x 좌표
    int y;         // 현재 위치 y 좌표
    int direction; // 다음 위치로 이동 방향
} MapPosition;

#endif