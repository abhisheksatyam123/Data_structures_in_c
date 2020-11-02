#ifndef QUEUE_HEADER
#define QUEUE_HEADER
    // defining struct data types
typedef struct queuenode Queuenode;
typedef struct queuelist Queuelist;

Queuenode * create_stack(int data);
Queuelist * make_queuelist();
void enqueue(Queuelist * listpointer ,int data);
void print_queue(Queuelist * listpointer);
int dequeue(Queuelist * listpointer);

#endif
