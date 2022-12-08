// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tree.h"

// DO NOT MODIFY FROM HERE --->>>
Tree * newTree(void)
{
  Tree * t = malloc(sizeof(Tree));
  t -> root = NULL;
  return t;
}

void deleteTreeNode(TreeNode * tr)
{
  if (tr == NULL)
    {
      return;
    }
  deleteTreeNode (tr -> left);
  deleteTreeNode (tr -> right);
  free (tr);
}

void freeTree(Tree * tr)
{
  if (tr == NULL)
    {
      // nothing to delete
      return;
    }
  deleteTreeNode (tr -> root);
  free (tr);
}


// <<<--- UNTIL HERE

// ***
// *** You MUST modify the follow function
// ***
#ifdef TEST_BUILDTREE
// Consider the algorithm posted on
// https://www.geeksforgeeks.org/construct-a-binary-tree-from-postorder-and-inorder/
// Feel free to add helper functions
// inArray: an integer array containing the in-order traversal output
// postArray: an integer array containing the post-order traversal output
// size: number of integers in inArray or postArray
Tree * buildTree(int * inArray, int * postArray, int size)
{
  // In order --> Print ALL Lefts, then Branch Node, Then print all right
  // Post Oder --> Print Branched Nodes all the way down, then Branc Node, then go up
Tree * BinarySearchTree = malloc(sizeof(Tree));
//BinarySearchTree -> root = NULL;
int pIndex = size - 1;
(BinarySearchTree -> root) = buildUtil(inArray, postArray, 0, size - 1, &pIndex);
return(BinarySearchTree);
}

/* Function to find index of value in arr[start...end]
   The function assumes that value is postsent in in[] */
int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++) {
        if (arr[i] == value){break;}
    }
    return i;
}

/* Recursive function to construct binary of size n
   from  Inorder traversal in[] and Postorder traversal
   post[].  Initial values of inStrt and inEnd should
   be 0 and n -1.  The function doesn't do any error
   checking for cases where inorder and postorder
   do not form a tree */
TreeNode* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex)
{
    // Base case
    if (inStrt > inEnd) {return NULL;}
 
    /* Pick current node from Postorder traversal using
       postIndex and decrement postIndex */
    TreeNode* node = newNode(post[*pIndex]);
    (*pIndex)--;
 
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return node;
 
    /* Else find the index of this node in Inorder
       traversal */
    int iIndex = search(in, inStrt, inEnd, node->value);
 
    /* Using index in Inorder traversal, construct left and
       right subtrees */
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
 
    return node;
}

TreeNode* newNode(int value)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->value = value;
    node->left = node->right = NULL;
    return (node);
}

#endif

#ifdef TEST_PRINTPATH
bool printPathNode(TreeNode * node, int val){
  if(node == NULL){return false;}
  if((node -> value) == val){
    printf("%d ", val);
    return true;
  }
  if(printPathNode(node -> left, val) == true){
    printf("%d ", node -> value);
    return true;
  }
  if(printPathNode(node -> right, val) == true){
    printf("%d ", node -> value);
    return true;
  }
  return false;
}

void printPath(Tree * tr, int val)
{
  if(tr == NULL){return;}
  printPathNode(tr -> root, val);
  printf("\n");
}
#endif
