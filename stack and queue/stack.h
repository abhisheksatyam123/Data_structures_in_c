#ifndef STACKHEADER
#define STACKHEADER
    // defining struct data types
typedef struct stacknode Stacknode;
typedef struct stacklist Stacklist;

Stacklist * make_stacklist();
void insert_stack(Stacklist * listpointer ,int data);
void print_stack(Stacklist * listpointer);
int delete_stack(Stacklist * listpointer);

#endif
