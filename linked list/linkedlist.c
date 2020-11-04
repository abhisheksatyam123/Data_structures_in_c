#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

struct node{
	int data;
	struct list_node *next
};

struct list{  //pointer  stores Node address
	Node *head;
};

// creating dynamic Node, returns pointer to  Node and take input as int data
Node * create_node(int data){
	Node * newnode = malloc(sizeof(int)); //create pointer to int with space of int
	if(!newnode)
		return NULL;
	else{
		newnode->data = data;
		newnode->next = NULL; // to acess data by pointer to a structur use ->
		return newnode;
	}
}

// make_list function creates a  pointer to store List address
List * make_list(){
	List * list_pointer = malloc(sizeof(List));
	if(!list_pointer)
		return NULL;
	else{
		list-> head = NULL;
		return list_pointer;
	}
}

// display a list

void display_list(List * list_pointer){
	Node * current = list_pointer->head;
	int len = 0; // store the length
	if(current == NULL){ // return Nothing if no node 
		return;
	}

	for(;current->next != NULL; current = current->next){
		printf("%d ",current->data);
	}
}
void add(int data, List * list_pointer){
	
	new_node = create_node(data);
	if(list_pointer -> head == NULL){
		list_pointer->head = new_node;	
	}
	else{
		Node * current  = list_pointer -> head;
		while(current->next != NULL){
			current = current -> next;
		}
		current->next = new_node;	
	}

}

void delete(int data,List * list_pionter){
	
}
