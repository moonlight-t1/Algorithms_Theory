#include <stdio.h>
#include <stdlib.h>
#include "MapUtil.h"

// 스택에 푸시 함수
int pushLSMapPosition(LinkedStack *pStack, MapPosition data)
{
    StackNode node = {
        0,
    };
    node.data = data;
    return pushLS(pStack, node);
}

// 경로 찾는 함수
void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
    StackNode *pNode = NULL;
    int isEmpty = FALSE, isFound = FALSE, i = 0;
    int markArray[HEIGHT][WIDTH] = {
        0,
    };

    if (pStack != NULL)
    {
        // 입구 위치를 스택에 푸쉬
        MapPosition newPosition = startPos;
        newPosition.direction = 0;
        pushLSMapPosition(pStack, newPosition);

        // 움직일 다른 곳이 있고, 아직 출구를 못 찾았다면 경로를 계속 찾는다
        while (isEmpty == FALSE && isFound == FALSE)
        {
            // 스택에서 위치 정보 및 방향 정보 팝
            pNode = popLS(pStack);

            if (pNode != NULL)
            {
                int x = pNode->data.x;
                int y = pNode->data.y;
                int direction = pNode->data.direction;

                // 현 위치에서, 아직 가보지 못한(이동 가능한) 방향이 있는가?
                while (isFound == FALSE && direction < NUM_DIRECTIONS)
                {
                    int newX = x + DIRECTION_OFFSET[direction][0];
                    int newY = y + DIRECTION_OFFSET[direction][1];

                    // (새로운 방향에 의해)새로운 위치로 이동이 가능한가?
                    if (newX >= 0 && newX < WIDTH && newY >= 0 && newY < HEIGHT && mazeArray[newY][newX] == NOT_VISIT && markArray[newY][newX] == NOT_VISIT)
                    {
                        // 이동 가능하다면 현재의 위치 정보 및 방향 정보를 스택에 푸시push
                        MapPosition newPosition;
                        newPosition.x = x;
                        newPosition.y = y;
                        newPosition.direction = direction + 1;
                        pushLSMapPosition(pStack, newPosition);
                        markArray[y][x] = VISIT;

                        // 새 위치로 이동, 단 이때 뱡향 정보는 초기화
                        x = newX;
                        y = newY;
                        direction = 0;

                        // 출구를 찾은 경우 마지막 출구를 스택에 푸시push
                        if (newX == endPos.x && newY == endPos.y)
                        {
                            isFound = TRUE;
                            newPosition.x = newX;
                            newPosition.y = newY;
                            newPosition.direction = 0;
                            pushLSMapPosition(pStack, newPosition);
                            markArray[newY][newX] = VISIT;
                        }
                    }
                    // 기존 방향에 의한 새로운 위치로 이동할 수 없다면
                    // 다른 방향으로 시도해 본다
                    else
                    {
                        direction++;
                    }

                } // end-of-if
                free(pNode);

            } // end-of-if
            isEmpty = isLinkedStackEmpty(pStack);

        } // end-of-while
    }
}

void ShowPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
    StackNode *pNode = NULL;
    int resultArray[HEIGHT][WIDTH] = {
        0,
    };
    int isEmpty = FALSE;

    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            resultArray[i][j] = mazeArray[i][j];
        }
    }

    if (pStack != NULL)
    {
        i = 0;
        while (isEmpty == FALSE)
        {
            pNode = popLS(pStack);
            if (pNode != NULL)
            {
                int x = pNode->data.x;
                int y = pNode->data.y;
                resultArray[y][x] = VISIT;

                if (i > 0)
                {
                    printf(" <- ");
                }
                printf("[%d, %d]", x, y);

                i++;
                free(pNode);
            }
            isEmpty = isLinkedStackEmpty(pStack);
        }
        printf("\n");
        printMaze(resultArray);
    }
}

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            if (mazeArray[i][j] == WALL)
            {
                printf("*");
            }
            else if (mazeArray[i][j] == VISIT)
            {
                printf(".");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}