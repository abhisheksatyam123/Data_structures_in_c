#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

struct queuenode{
	int data;
	struct queuenode * next;
};

struct queuelist{
	Queuenode * head;
	Queuenode * tail;
};

Queuelist * make_queuelist(){ //listpointer is pointer to Dll_list which store head which is pointer to DLlnode
	Queuelist * listpointer = malloc(sizeof(Queuelist));
	if(! listpointer)
		return NULL;
	listpointer -> head = NULL;
	listpointer -> tail = NULL;
	return listpointer;
}

void enqueue(Queuelist * listpointer ,int data){
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
		printf(" %d ",current->data);
		current = current -> next;
	}
}
int dequeue(Queuelist * listpointer){
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
