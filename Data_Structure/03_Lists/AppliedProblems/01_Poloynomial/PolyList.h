#ifndef _POLYLIST_H_
#define _POLYLIST_H_

#include "LinkedList.h"

int addPolyNodeLast(LinkedList *pList, float coef, int degree);
LinkedList *PolyAdd(LinkedList *pListA, LinkedList *pListB);
void displayPolyList(LinkedList *pList);

#endif