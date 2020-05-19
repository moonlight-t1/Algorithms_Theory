#ifndef _BIN_SEARCH_TREE_
#define _BIN_SEARCH_TREE_

typedef struct BinSearchTreeNodeType
{
    int key;
    char value;

    struct BinSearchTreeNodeType *pLeftChild;
    struct BinSearchTreeNodeType *pRightChild;
} BinSearchTreeNode;

typedef struct BinSearchTreeType
{
    BinSearchTreeNode *pRootNode;
} BinSearchTree;

BinSearchTree *createBinSearchTree();                                           // 이진 탐색 트리 생성
int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element); // 이진 탐색 트리 원소 삽입
int deleteElementBST(BinSearchTree *pBinSearchTree, int key);                   // 이진 탐색 트리 원소 삭제
BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key);
BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key);
BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key); // 이진 탐색 트리에서의 검색 연산
void deleteBinSearchTree(BinSearchTree *pBinSearchTree);              // 이진 탐색 트리 삭제
void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode);       // 후위 순회 방식으로 메모리 해제

#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE 1
#define FALSE 0

#endif