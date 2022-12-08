// ***
// *** DO NOT modify this file
// ***

#ifndef TREE_H
#define TREE_H

typedef struct tnode
{
  int value;
  struct tnode * left;
  struct tnode * right;
} TreeNode;

typedef struct trnode
{
  TreeNode * root;
} Tree;

Tree * newTree(void);
void freeTree(Tree * tr);
Tree * buildTree(int * inArray, int * postArray, int size);
void printPath(Tree * tr, int val);
int search(int arr[], int strt, int end, int value);
TreeNode* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex);
TreeNode* newNode(int value);
void printPath(Tree * tr, int val);
#endif
