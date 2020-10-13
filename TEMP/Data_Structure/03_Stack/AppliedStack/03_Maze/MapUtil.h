#ifndef _MAP_UTIL_
#define _MAP_UTIL_
#include "MapDef.h"
#include "MapLinkedStack.h"

void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack);
int pushLSMapPosition(LinkedStack *pStack, MapPosition data);
void ShowPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH]);
void printMaze(int mazeArray[HEIGHT][WIDTH]);

#endif