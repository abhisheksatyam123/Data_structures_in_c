
#ifndef _TREEHEADER_h
#define _TREEHEADER_h

typedef struct Node 
{ 
	int key; 
	struct Node *left; 
	struct Node *right; 
	int height; 
}Avlnode; 

typedef struct queuenode{
	Avlnode * data;
	struct Queuenode * next;
}Queuenode;

typedef struct queuelist{
	Queuenode * head;
	Queuenode * tail;
}Queuelist;

#endif
