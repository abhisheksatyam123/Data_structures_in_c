
#ifndef _TREEHEADER_h
#define _TREEHEADER_h
//typedef struct treenode Treenode;
typedef struct treenode //somehow code is not recognizing sruct defination from other fire
{ 
	int data; 
	struct treenode * left; 
	struct treenode * right; 
}Treenode;

typedef struct queuenode{
	Treenode * data;
	struct Queuenode * next;
}Queuenode;
typedef struct queuelist{
	Queuenode * head;
	Queuenode * tail;
}Queuelist;
#endif
