#include <stdio.h> 
#include <stdlib.h> 
#include "tree.h"

Queuelist * make_queuelist();
void enqueue(Queuelist * listpointer ,Treenode * data);
void print_queue(Queuelist * listpointer);
Treenode * dequeue(Queuelist * listpointer);
Treenode* newtreenode(int data);
void levelorder(Treenode * root);
int isemptyq(Queuelist * listpointer);
void deleteq(Queuelist * listpointer);

Treenode* newtreenode(int data)
{ 
	Treenode* node = malloc(sizeof(Treenode)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return(node); 
} 

Queuelist * make_queuelist(){ //listpointer is pointer to Dll_list which store head which is pointer to DLlnode
	Queuelist * listpointer = malloc(sizeof(Queuelist));
	if(! listpointer)
		return NULL;
	listpointer -> head = NULL;
	listpointer -> tail = NULL;
	return listpointer;
}

void enqueue(Queuelist * listpointer ,Treenode * data){
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

void print_queue(Queuelist * listpointer){
	Queuenode * current = listpointer -> head;
	if(current == NULL)
		return;
	while(current != NULL){
		printf(" %d ",current->data->data);
		current = current -> next;
	}
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



Treenode * dequeue(Queuelist * listpointer){
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



void levelorder(Treenode * root){
Queuelist *q = make_queuelist();
Treenode * temp;
if(!root)
	return;
enqueue(q,root);
while(!isemptyq(q)){
	temp = dequeue(q);
	printf(" %d ",temp->data);
	if(temp->left)
		enqueue(q,temp->left);
	if(temp->right)
		enqueue(q,temp->right);
}
deleteq(q);
}


