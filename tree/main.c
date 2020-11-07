#include <stdio.h> 
#include "tree.c"
#include "tree.h"


int main()
{ 

Queuelist * q = make_queuelist();
Treenode *root = newtreenode(1); 
root->left        = newtreenode(2);
root->right       = newtreenode(3);
root->left->left  = newtreenode(4);
root->left->right = newtreenode(5);
root->right->left  = newtreenode(6);
root->right->right = newtreenode(7);
levelorder(root);
return 0; 
}
