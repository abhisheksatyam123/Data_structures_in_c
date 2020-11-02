#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

int main(void){
    Queuelist * list1 = make_queuelist();
    Stacklist * list2 = make_stacklist();
	insert_stack(list2 ,1);
	insert_stack(list2 ,2);
	insert_stack(list2 ,3);
	insert_stack(list2 ,4);
	print_stack(list2);
	printf("\n printing stack \n");
	int d2 = delete_stack(list2);
	printf("de stacked integer is %d",d2);
	printf("\n printing stack \n");
	print_stack(list2);
    enqueue(list1 ,1);
    enqueue(list1 ,2);
    enqueue(list1 ,3);
	enqueue(list1 ,4);
	enqueue(list1 ,5);
	enqueue(list1 ,6);
	enqueue(list1 ,7);
    printf("\n printing queue");
    print_queue(list1);
    printf("\n");
    int d = dequeue(list1);
    printf("\n dequeued integer is %d \n",d);
	printf("\n printing queue");
    print_queue(list1);
    return 0;
}
