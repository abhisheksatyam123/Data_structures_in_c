#ifndef DLLHEADER
#define DLLHEADER
    // defining struct data types
typedef struct dll_node Dll_node;
typedef struct dll_list Dll_list;

Dll_node * create_dll_node(int data);
Dll_list * make_dll_list();
void dll_insert(Dll_list * listpointer ,int data, int pos);
void print_dll_list(Dll_list * listpointer);
void delete_dll(Dll_list * listpointer,int pos);

#endif