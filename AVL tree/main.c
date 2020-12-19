// C program to insert a node in AVL tree 
#include<stdio.h> 
#include "tree.c"
#include "tree.h"

int main() 
{ 
Avlnode *root = NULL; 

/* Constructing tree given in the above figure */
root = insert(root, 1); 
root = insert(root, 2); 
root = insert(root, 3); 
root = insert(root, 4); 
root = insert(root, 5); 
root = insert(root, 6);
root = insert(root, 7);
root = insert(root, 8);
 
levelorder(root);


return 0; 
} 
