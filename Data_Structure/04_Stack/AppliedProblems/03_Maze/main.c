#include <stdio.h>
#include <stdlib.h>
#include "MapDef.h"
#include "MapLinkedStack.h"
#include "MapUtil.h"

int main(int argc, char *argv[])
{
    LinkedStack *pStack = NULL;

    MapPosition startPos, endPos;

    int mazeArray[HEIGHT][WIDTH] = {
        {0, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 0},
    };

    // 스택 생성
    pStack = createLinkedStack();
    if (pStack != NULL)
    {
        startPos.x = 0;
        startPos.y = 0;
        endPos.x = 7;
        endPos.y = 7;

        printMaze(mazeArray);

        findPath(mazeArray, startPos, endPos, pStack);

        ShowPath(pStack, mazeArray);

        deleteLinkedStack(pStack);
    }
    return 0;
}