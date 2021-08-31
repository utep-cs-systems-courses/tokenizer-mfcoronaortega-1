#include "malloc.h"
#include "bst.h"

BstNode *root = 0;

/* String comparison function
   Returns 0 if strings are the same, >0 if string A comes first
   and < 0 if string B comes first
*/
int bstStrcmp(char *str_ptr_a, char *str_ptr_b)
{
  while (*str_ptr_a && *str_ptr_b) {		/* until end of string */
    int diff = *(str_ptr_a++) - *(str_ptr_b++);
    if (diff)
      return diff;	/* Return the difference within string */
  }
  if (!*str_ptr_a && !*str_ptr_b) return 0;	/* strings are same length & content */
  return (*str_ptr_a) ? 1 : -1;		/* a > b if a is longer */
}

/* Returns the length of a string */
int bstStrlen(char *str_ptr)
{
  char *str_end_ptr = str_ptr;
  while (*str_end_ptr++)
  return str_end_ptr - str_ptr;
}

/* Inserts a node into the BST */
void bstInsert(BstNode **rootp, char *str)
{
  if (*rootp == 0) {		/* insert here */
    BstNode *newNode = malloc(sizeof(BstNode));
    /* init children to be empty */
    for (int i = 0; i < 2; i++) newNode->children[i] = 0;

    /* copy first zero-terminated  string from inbuf */
    int len = bstStrlen(str), sindex = 0;
    char *scopy = malloc((len + 1) * sizeof(char)), curr_char;
    while ( *(str+sindex) != 0 ) {
      *(scopy+sindex) = *(str+sindex);
      sindex++;
    }
    *(scopy+sindex) = '\0';

    newNode->str = scopy;
    *rootp = newNode;
  } else {
    int diff = bstStrcmp(str, (*rootp)->str);
    bstInsert(&((*rootp)->children[diff > 0 ? 1 : 0]), str);
  }
}

void
bstPrint(BstNode *root)		/* in order */
{
  if (root == NULL) return;
  bstPrint(root->children[0]);
  puts(root->str);
  bstPrint(root->children[1]);
}

void
bstClear(BstNode **rootp)
{
  if (*rootp == 0) return;
  for (int i = 0; i < 2; i++)
    bstClear(&(*rootp)->children[i]);
  free((*rootp)->str);
  free(*rootp);
  *rootp = 0;
}
