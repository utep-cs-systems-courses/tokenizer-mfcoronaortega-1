#include "stdio.h"

// struct for BST node
typedef struct BNode_s {
  struct BNode_s *children[2];
  char *str;
} BstNode;

// Root of the tree
BstNode *bstRoot;

// Basic BST functions

/* Insert a string into the BST */
void bstInsert(BstNode **rootp, char *str);

/* Print the BST in order */
void bstPrint(BstNode *root);

/* Remove all the nodes from the BST and free their memory */
void bstClear(BstNode **rootp);
