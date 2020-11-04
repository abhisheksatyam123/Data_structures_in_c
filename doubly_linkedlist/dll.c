#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

struct dll_node{
	int data;
	struct dll_node * next;
	struct dll_node * prev;
};

struct dll_list{
	Dll_node * head;
};

Dll_node * create_dll_node(int data);

Dll_node * create_dll_node(int data){
	Dll_node * newnode = malloc(sizeof(Dll_node));
	if(!newnode)
		return NULL;
	newnode -> data = data;
	newnode -> next = NULL;
	newnode -> prev = NULL;
	return newnode;
}

Dll_list * make_dll_list(){ //listpointer is pointer to Dll_list which store head which is pointer to DLlnode
	Dll_list * listpointer = malloc(sizeof(Dll_list));
	if(! listpointer)
		return NULL;
	listpointer -> head = NULL;
	return listpointer;
}

void dll_insert(Dll_list * listpointer ,int data, int pos){
	int k =1;
	Dll_node * temp, * newnode,* head;
	head = listpointer -> head;
	newnode = malloc(sizeof(Dll_node));
	if(!newnode)
		printf("\n memory error \n");
	newnode->data = data;
	if(pos ==1){
		temp = listpointer -> head;
		listpointer -> head = newnode;
		newnode -> next = temp;
		newnode -> prev = NULL;
	}
	return;
}

void print_dll_list(Dll_list * listpointer){
	Dll_node * current = listpointer -> head;
	if(current == NULL)
		return;
	while(current != NULL){
		printf(" %d ",current->data);
		current = current -> next;
	}
}
void delete_dll(Dll_list * listpointer,int pos){
	Dll_node *head, * current,* prev,*next;
	head = listpointer-> head;
	current = head;
	if(pos ==1){
		listpointer-> head = current->next;
		free(current);	
	}
	else{
		for(int i =0 ;i < pos-1 ;i++){
			prev = current;
			current = prev -> next;
		}
		next = current -> next;
		prev -> next = next;
		next -> prev =  prev;
		free(current);
	}
	return ;
}




