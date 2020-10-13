#ifndef _BIN_TREE_TRAVERSAL_
#define _BIN_TREE_TRAVERSAL_

#include "BinaryTree.h"
#include "BinTreeLinkedStack.h"
#include "BinTreeLinkedQueue.h"

void preorderTraversalBinTree(BinTree *pBinTree);   // 전위 순회
void inorderTraversalBinTree(BinTree *pBinTree);    // 중위 순회
void postorderTraversalBinTree(BinTree *pBinTree);  // 후위 순회
void levelOrderTraversalBinTree(BinTree *pBinTree); // 레벨 순회

#endif