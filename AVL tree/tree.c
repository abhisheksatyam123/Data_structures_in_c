#include <stdio.h> 
#include <stdlib.h> 
#include "tree.h"


int max(int a, int b); 
int height(Avlnode *N);
Avlnode* newNode(int key);
Avlnode *rightRotate(Avlnode *y);
Avlnode *leftRotate(Avlnode *x);
int getBalance(Avlnode *N);
Avlnode* insert(Avlnode *node, int key);
Queuelist * make_queuelist();
void levelorder(Avlnode * root);
int isemptyq(Queuelist * listpointer);
Avlnode * dequeue(Queuelist * listpointer);
void deleteq(Queuelist * listpointer);
Queuelist * make_queuelist();
void enqueue(Queuelist * listpointer ,Avlnode * data);

int height(Avlnode *N) 
{ 
	if (N == NULL) 
		return 0; 
	return N->height; 
} 

// A utility function to get maximum of two integers 
int max(int a, int b) 
{ 
	return (a > b)? a : b; 
} 

/* Helper function that allocates a new node with the given key and 
	NULL left and right pointers. */
Avlnode* newNode(int key) 
{ 
	Avlnode* node = malloc(sizeof(Avlnode)); 
	node->key = key; 
	node->left = NULL; 
	node->right = NULL; 
	node->height = 1; // new node is initially added at leaf 
	return(node); 
} 

// A utility function to right rotate subtree rooted with y 
// See the diagram given above. 
Avlnode *rightRotate(Avlnode *y) 
{ 
	struct Node *x = y->left; 
	struct Node *T2 = x->right; 

	// Perform rotation 
	x->right = y; 
	y->left = T2; 

	// Update heights 
	y->height = max(height(y->left), height(y->right))+1; 
	x->height = max(height(x->left), height(x->right))+1; 

	// Return new root 
	return x; 
} 

// A utility function to left rotate subtree rooted with x 
// See the diagram given above. 
Avlnode *leftRotate(Avlnode *x) 
{ 
	Avlnode *y = x->right; 
	Avlnode *T2 = y->left; 

	// Perform rotation 
	y->left = x; 
	x->right = T2; 

	// Update heights 
	x->height = max(height(x->left), height(x->right))+1; 
	y->height = max(height(y->left), height(y->right))+1; 

	// Return new root 
	return y; 
} 

// Get Balance factor of node N 
int getBalance(Avlnode *N) 
{ 
	if (N == NULL) 
		return 0; 
	return height(N->left) - height(N->right); 
} 

// Recursive function to insert a key in the subtree rooted 
// with node and returns the new root of the subtree. 
Avlnode* insert(Avlnode *node, int key) 
{ 
	/* 1. Perform the normal BST insertion */
	if (node == NULL) 
		return(newNode(key)); 

	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	else // Equal keys are not allowed in BST 
		return node; 


	node->height = 1 + max(height(node->left), 
						height(node->right)); 


	int balance = getBalance(node); 


	if (balance > 1 && key < node->left->key) 
		return rightRotate(node); 

	// Right Right Case 
	if (balance < -1 && key > node->right->key) 
		return leftRotate(node); 

	// Left Right Case 
	if (balance > 1 && key > node->left->key) 
	{ 
		node->left = leftRotate(node->left); 
		return rightRotate(node); 
	} 

	// Right Left Case 
	if (balance < -1 && key < node->right->key) 
	{ 
		node->right = rightRotate(node->right); 
		return leftRotate(node); 
	} 

	
	return node; 
} 


Queuelist * make_queuelist(){ //listpointer is pointer to Dll_list which store head which is pointer to DLlnode
	Queuelist * listpointer = malloc(sizeof(Queuelist));
	if(! listpointer)
		return NULL;
	listpointer -> head = NULL;
	listpointer -> tail = NULL;
	return listpointer;
}

void enqueue(Queuelist * listpointer ,Avlnode * data){
	Queuenode  * newnode,*head;
	newnode = malloc(sizeof(Queuenode));
	if(!newnode)
		printf("\n memory error \n");
	newnode -> data = data;
	newnode -> next = NULL;
	head = listpointer -> head;
	if(head == NULL){
		listpointer -> head = newnode;
		listpointer -> tail = newnode;
	}
	else{
		listpointer -> tail -> next = newnode;
		listpointer -> tail =  newnode;		
	}
	return;
}



void deleteq(Queuelist * listpointer){
	Queuenode * temp ;
	if(listpointer->head == NULL)
		return;
	while(listpointer->head != NULL){
		temp = listpointer->head;
		listpointer->head = listpointer->head->next;
		free(temp);
	}
	free(listpointer);
}



Avlnode * dequeue(Queuelist * listpointer){
	Queuenode  *temp,*head;
	head =  listpointer -> head;
	if(listpointer->head == NULL)
		printf("\n Nothing to return list is empty \n");
	else if(listpointer -> head == listpointer -> tail){
		listpointer -> head = NULL;
		listpointer -> tail = NULL;
		return head->data;
	}
	else{
		temp = head;
		listpointer -> head = head -> next;
		return temp -> data;
	}	
}


int isemptyq(Queuelist * listpointer){
	return(listpointer -> head == NULL);
}



void levelorder(Avlnode * root){
Queuelist *q = make_queuelist();
Avlnode * temp;
if(!root)
	return;
enqueue(q,root);
while(!isemptyq(q)){
	temp = dequeue(q);
	printf(" %d ",temp->key);
	if(temp->left)
		enqueue(q,temp->left);
	if(temp->right)
		enqueue(q,temp->right);
}
deleteq(q);
}
