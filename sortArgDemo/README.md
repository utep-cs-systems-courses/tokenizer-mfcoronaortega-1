SortArgDemo
===================================
This directory contains source code for a program "sortargs."
Sortargs prints its command-line parameters in sorted order.  

It does this by storing each argument in a Binary Search Tree (BST) and then printing
the BST in order.

For example
```
$  ./sortargs my dog has fleas
dog
fleas
has
my
```
 SortArgDemo contains the following files:
 * sortargs.c - The main program driver that reads the arguments
 * bst.h - The header that contains the interface info for the BST
 * bst.c - The implementation of the binary search tree
