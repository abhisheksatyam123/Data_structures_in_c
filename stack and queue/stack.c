#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stacknode{
	int data;
	struct stacknode * next;
};

struct stacklist{
	Stacknode * head;
};

Stacklist * make_stacklist(){ //listpointer is pointer to Dll_list which store head which is pointer to DLlnode
	Stacklist * listpointer = malloc(sizeof(Stacklist));
	if(! listpointer)
		return NULL;
	listpointer -> head = NULL;
	return listpointer;
}

void insert_stack(Stacklist * listpointer ,int data){
	int k =1;
	int pos = 1;
	Stacknode * temp, * newnode,* head;
	head = listpointer -> head;
	newnode = malloc(sizeof(Stacknode));
	if(!newnode)
		printf("\n memory error \n");
	newnode -> data = data;
	if(pos ==1){
		temp = listpointer -> head;
		listpointer -> head = newnode;
		newnode -> next = temp;
	}
	return;
}

void print_stack(Stacklist * listpointer){
	Stacknode * current = listpointer -> head;
	if(current == NULL)
		return;
	while(current != NULL){
		printf(" %d ",current->data);
		current = current -> next;
	}
}
int delete_stack(Stacklist * listpointer){
	Stacknode *head, * current,*next;
	head = listpointer-> head;
	current = head;
	listpointer-> head = current->next;
	return current->data;
	}
